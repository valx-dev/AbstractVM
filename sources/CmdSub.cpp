/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdSub.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:44:21 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:23 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdSub.hpp"

CmdSub::CmdSub() {}
CmdSub::CmdSub(CmdSub const & obj)
{
	*this = obj;
}
CmdSub::~CmdSub() {}

CmdSub &	CmdSub::operator=(CmdSub const &)
{
	return *this;
}

static void		exe(std::stack<const IOperand *> & oper)
{
	if (oper.empty())
		throw CmdSub::EmptyStackException();
	IOperand const * first = oper.top();
	oper.pop();

	if (oper.empty())
	{
		oper.push(first);
		throw CmdSub::EmptyStackException();
	}
	IOperand const * second = oper.top();
	oper.pop();

	oper.push(*second - *first);

	delete first;
	delete second;
}

void	CmdSub::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		exe(oper);
	}
	catch (CmdSub::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdSub::EmptyStackException::EmptyStackException() throw() {}
CmdSub::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdSub::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdSub::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdSub::EmptyStackException &	CmdSub::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}
