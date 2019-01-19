/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdExit.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:46:05 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:46:06 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdExit.hpp"

CmdExit::CmdExit() {}
CmdExit::CmdExit(CmdExit const & obj)
{
	*this = obj;
}
CmdExit::~CmdExit() {}

CmdExit &	CmdExit::operator=(CmdExit const &)
{
	return *this;
}

void	CmdExit::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)oper;
	(void)vec;
	(void)factory;

	exit(0);
}
