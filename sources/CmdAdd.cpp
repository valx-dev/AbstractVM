/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdAdd.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:44:14 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:15 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdAdd.hpp"

CmdAdd::CmdAdd() {}
CmdAdd::CmdAdd(CmdAdd const & obj)
{
	*this = obj;
}
CmdAdd::~CmdAdd() {}

CmdAdd &	CmdAdd::operator=(CmdAdd const &)
{
	return *this;
}

static void		exe(std::stack<const IOperand *> & oper)
{
	if (oper.empty())
		throw CmdAdd::EmptyStackException();
	IOperand const * first = oper.top();
	oper.pop();

	if (oper.empty())
	{
		oper.push(first);
		throw CmdAdd::EmptyStackException();
	}
	IOperand const * second = oper.top();
	oper.pop();

	oper.push(*second + *first);

	delete first;
	delete second;
}

void	CmdAdd::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		exe(oper);
	}
	catch (CmdAdd::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdAdd::EmptyStackException::EmptyStackException() throw() {}
CmdAdd::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdAdd::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdAdd::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdAdd::EmptyStackException &	CmdAdd::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}