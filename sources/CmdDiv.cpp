/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdDiv.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:45:33 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:45:35 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdDiv.hpp"

CmdDiv::CmdDiv() {}
CmdDiv::CmdDiv(CmdDiv const & obj)
{
	*this = obj;
}
CmdDiv::~CmdDiv() {}

CmdDiv &	CmdDiv::operator=(CmdDiv const &)
{
	return *this;
}

static void		exe(std::stack<const IOperand *> & oper)
{
	if (oper.empty())
		throw CmdDiv::EmptyStackException();
	IOperand const * first = oper.top();
	oper.pop();

	if (oper.empty())
	{
		oper.push(first);
		throw CmdDiv::EmptyStackException();
	}
	if (!std::stod(first->toString()))
	{
		oper.push(first);
		throw CmdDiv::ZeroDivideException();
	}
	IOperand const * second = oper.top();
	oper.pop();

	oper.push(*second / *first);

	delete first;
	delete second;
}

void	CmdDiv::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		exe(oper);
	}
	catch (CmdDiv::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (CmdDiv::ZeroDivideException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdDiv::EmptyStackException::EmptyStackException() throw() {}
CmdDiv::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdDiv::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdDiv::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdDiv::EmptyStackException &	CmdDiv::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}

//ZeroDivideException---------------------------------------------------

CmdDiv::ZeroDivideException::ZeroDivideException() throw() {}
CmdDiv::ZeroDivideException::ZeroDivideException(ZeroDivideException const & obj) throw()
{
	*this = obj;
}
CmdDiv::ZeroDivideException::~ZeroDivideException() throw() {}
const char *	CmdDiv::ZeroDivideException::what() const throw()
{
	return "Division by zero.";
}
CmdDiv::ZeroDivideException &	CmdDiv::ZeroDivideException::operator=(ZeroDivideException const &) throw()
{
	return *this;
}
