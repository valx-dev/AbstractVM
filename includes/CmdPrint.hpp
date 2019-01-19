/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPrint.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:42:19 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:20 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdPrint : public ICommand
{
public:
	CmdPrint();
	CmdPrint(CmdPrint const &);
	~CmdPrint();

	CmdPrint &	operator=(CmdPrint const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

	class EmptyStackException
	{
	public:
		EmptyStackException() throw();
		EmptyStackException(EmptyStackException const &) throw();
		virtual ~EmptyStackException() throw();
		virtual const char*	what() const throw();
		EmptyStackException &	operator=(EmptyStackException const &) throw();
	};

	class WrongTypeException
	{
	public:
		WrongTypeException() throw();
		WrongTypeException(WrongTypeException const &) throw();
		virtual ~WrongTypeException() throw();
		virtual const char*	what() const throw();
		WrongTypeException &	operator=(WrongTypeException const &) throw();
	};
};
