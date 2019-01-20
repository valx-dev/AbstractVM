/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPop.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:08 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:09 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdPop : public ICommand
{
public:
    CmdPop();
    CmdPop(CmdPop const &);
    ~CmdPop();

    CmdPop &	operator=(CmdPop const &);

    void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

    static std::string id()
    {
        return "pop";
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
};
