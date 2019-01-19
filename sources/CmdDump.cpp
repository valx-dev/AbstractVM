/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdDump.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:52 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:55 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdDump.hpp"

CmdDump::CmdDump() {}
CmdDump::CmdDump(CmdDump const & obj)
{
	*this = obj;
}
CmdDump::~CmdDump() {}

CmdDump &	CmdDump::operator=(CmdDump const &)
{
	return *this;
}

void	CmdDump::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)oper;
	(void)vec;
	(void)factory;

	std::stack<const IOperand *> st = oper;

	while (!st.empty())
	{
		std::cout << st.top()->toString() << std::endl;
		st.pop();
	}
}
