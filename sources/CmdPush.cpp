/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPush.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:31 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:33 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPush.hpp"

CmdPush::CmdPush() {}
CmdPush::CmdPush(CmdPush const & obj)
{
	*this = obj;
}
CmdPush::~CmdPush() {}

CmdPush &	CmdPush::operator=(CmdPush const &)
{
	return *this;
}

static eOperandType	typer(std::string & stype)
{
	if (stype == "int8")
		return INT8;
	else if (stype == "int16")
		return INT16;
	else if (stype == "int32")
		return INT32;
	else if (stype == "float")
		return FLOAT;
	else if (stype == "double")
		return DOUBLE;
	else
		return DOUBLE;
};

void	CmdPush::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)oper;
	(void)vec;
	(void)factory;

	oper.push(factory.createOperand(typer(vec.at(1)), vec.at(2)));
}
