/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdSub.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:52 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:54 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdSub : public ICommand
{
public:
	CmdSub();
	CmdSub(CmdSub const &);
	~CmdSub();

	CmdSub &	operator=(CmdSub const &);

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
