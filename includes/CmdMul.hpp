/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMul.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:39:06 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:39:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdMul : public ICommand
{
public:
	CmdMul();
	CmdMul(CmdMul const &);
	~CmdMul();

	CmdMul &	operator=(CmdMul const &);

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
};
