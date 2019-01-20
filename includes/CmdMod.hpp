/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMod.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:42:10 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:11 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdMod : public ICommand
{
public:
    CmdMod();
    CmdMod(CmdMod const &);
    ~CmdMod();

    CmdMod &	operator=(CmdMod const &);

    void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

    static std::string id()
    {
        return "mod";
    }

    class EmptyStackException
    {
    public:
        EmptyStackException() throw();
        EmptyStackException(EmptyStackException const &) throw();
        virtual ~EmptyStackException() throw();
        virtual const char*	what() const throw();
        EmptyStackException &	operator=(EmptyStackException const &) throw();
    };

    class ZeroDivideException
    {
    public:
        ZeroDivideException() throw();
        ZeroDivideException(ZeroDivideException const &) throw();
        virtual ~ZeroDivideException() throw();
        virtual const char*	what() const throw();
        ZeroDivideException &	operator=(ZeroDivideException const &) throw();
    };

    class FloatingPointException
    {
    public:
        FloatingPointException() throw();
        FloatingPointException(FloatingPointException const &) throw();
        virtual ~FloatingPointException() throw();
        virtual const char*	what() const throw();
        FloatingPointException &	operator=(FloatingPointException const &) throw();
    };
};
