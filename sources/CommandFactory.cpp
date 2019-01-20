/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandFactory.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:15 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 11:47:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CommandFactory.hpp"
#include "CmdAssert.hpp"
#include "CmdPrint.hpp"
#include "CmdPop.hpp"
#include "CmdMod.hpp"

class CmdExit : public ICommand {
public:
    void execute(operations_t &, args_t &, OpFactory &) override
    {
        exit(0);
    }
    // NOTE: usage of 'id' could be ommited in case of fromClass(__CLASS_NAME__)
    //  will be implemented either via macro or via static calls
    static std::string id()
    {
        return "exit";
    }
};

class CmdDump : public ICommand {
public:
    void execute(operations_t &stack, args_t &, OpFactory &) override
    {
        std::stack<const IOperand *> st = stack;

        while (!st.empty())
        {
            std::cout << st.top()->toString() << std::endl;
            st.pop();
        }
    }
    static std::string id()
    {
        return "dump";
    }
};

class CmdPush : public ICommand {
public:
    void execute(operations_t &stack, args_t &args, OpFactory &factory) override
    {
        stack.push(factory.createOperand(args.at(1), args.at(2)));
    }
    static std::string id()
    {
        return "push";
    }
};

class TwoOperandCmd : public ICommand {
public:
    void execute(operations_t &stack, args_t &, OpFactory &) override
    {
        if (stack.empty()) {
            throw EmptyStackException();
        }
        IOperand const * first = stack.top();
        stack.pop();

        if (stack.empty()) {
            stack.push(first);
            throw EmptyStackException();
        }
        IOperand const * second = stack.top();
        stack.pop();

        stack.push(execute(first, second));

        delete first;
        delete second;
    }

    struct EmptyStackException : public std::runtime_error {
        EmptyStackException() : std::runtime_error("Not enough arguments.") {}
    };

protected:
    virtual const IOperand *execute(const IOperand *first,
                                    const IOperand *second) const = 0;
};

class CmdAdd : public TwoOperandCmd {
public:
    const IOperand *execute(const IOperand *first,
                            const IOperand *second) const override
    {
        return *second + *first;
    }
    static std::string id()
    {
        return "add";
    }
};

class CmdSub : public TwoOperandCmd {
public:
    const IOperand *execute(const IOperand *first,
                            const IOperand *second) const override
    {
        return *second - *first;
    }
    static std::string id()
    {
        return "sub";
    }
};

class CmdMul : public TwoOperandCmd {
public:
    const IOperand *execute(const IOperand *first,
                            const IOperand *second) const override
    {
        return *second * *first;
    }
    static std::string id()
    {
        return "mul";
    }
};

class CmdDiv : public TwoOperandCmd {
public:
    const IOperand *execute(const IOperand *first,
                            const IOperand *second) const override
    {
        if (!std::stod(first->toString())) {
            // TODO: restore the stack on failure
//            oper.push(first);
            throw ZeroDivideException();
        }
        return *second / *first;
    }
    static std::string id()
    {
        return "div";
    }

    struct ZeroDivideException : public std::runtime_error {
        ZeroDivideException() : std::runtime_error("Division by zero.") {}
    };

};


CmdFactory::CmdFactory()
{
    register_command<CmdPush>();
    register_command<CmdPop>();
    register_command<CmdDump>();
    register_command<CmdAssert>();
    register_command<CmdAdd>();
    register_command<CmdSub>();
    register_command<CmdMul>();
    register_command<CmdDiv>();
    register_command<CmdMod>();
    register_command<CmdPrint>();
    register_command<CmdExit>();
}

CmdFactory::commands_t CmdFactory::create(const std::vector<std::string> &list)
{
    commands_t commands;
    if (list.empty()) {
        std::cout << "list is empty" << std::endl;
        return commands;
    }
    const auto &command_name = list[0];
    const auto &cmd = _commands.find(command_name);
    if (cmd == _commands.end()) {
        std::cout << "command not registered: " << command_name << std::endl;
    } else {
        commands.push_back(cmd->second);
    }
    return commands;
}
