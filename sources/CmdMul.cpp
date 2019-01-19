/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMul.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:44:48 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:52 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdMul.hpp"

CmdMul::CmdMul() {}
CmdMul::CmdMul(CmdMul const & obj)
{
	*this = obj;
}
CmdMul::~CmdMul() {}

CmdMul &	CmdMul::operator=(CmdMul const &)
{
	return *this;
}

static void		exe(std::stack<const IOperand *> & oper)
{
	if (oper.empty())
		throw CmdMul::EmptyStackException();
	
	IOperand const * first = oper.top();
	oper.pop();

	if (oper.empty())
	{
		oper.push(first);
		throw CmdMul::EmptyStackException();
	}
	IOperand const * second = oper.top();
	oper.pop();

	oper.push(*second * *first);

	delete first;
	delete second;
}

void	CmdMul::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		exe(oper);
	}
	catch (CmdMul::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdMul::EmptyStackException::EmptyStackException() throw() {}
CmdMul::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdMul::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdMul::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdMul::EmptyStackException &	CmdMul::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}
