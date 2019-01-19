/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdDiv.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:42:01 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:03 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdDiv : public ICommand
{
public:
	CmdDiv();
	CmdDiv(CmdDiv const &);
	~CmdDiv();

	CmdDiv &	operator=(CmdDiv const &);

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

	class ZeroDivideException
	{
	public:
		ZeroDivideException() throw();
		ZeroDivideException(ZeroDivideException const &) throw();
		virtual ~ZeroDivideException() throw();
		virtual const char*	what() const throw();
		ZeroDivideException &	operator=(ZeroDivideException const &) throw();
	};
};
