/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdAssert.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:26 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:28 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdAssert : public ICommand
{
public:
    CmdAssert();
    CmdAssert(CmdAssert const &);
    ~CmdAssert();

    CmdAssert &	operator=(CmdAssert const &);

    void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

    static std::string id()
    {
        return "assert";
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

    class NonEqualException
    {
    public:
        NonEqualException() throw();
        NonEqualException(NonEqualException const &) throw();
        virtual ~NonEqualException() throw();
        virtual const char*	what() const throw();
        NonEqualException &	operator=(NonEqualException const &) throw();
    };
};
