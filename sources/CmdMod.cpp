/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdMod.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:45:44 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:45:47 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdMod.hpp"

CmdMod::CmdMod() {}
CmdMod::CmdMod(CmdMod const & obj)
{
	*this = obj;
}
CmdMod::~CmdMod() {}

CmdMod &	CmdMod::operator=(CmdMod const &)
{
	return *this;
}

static void		exe(std::stack<const IOperand *> & oper)
{
	if (oper.empty())
		throw CmdMod::EmptyStackException();
	IOperand const * first = oper.top();
	oper.pop();

	if (oper.empty())
	{
		oper.push(first);
		throw CmdMod::EmptyStackException();
	}
	if (!std::stod(first->toString()))
	{
		oper.push(first);
		throw CmdMod::ZeroDivideException();
	}
	IOperand const * second = oper.top();
	oper.pop();

	if (first->getType() > INT32 || second->getType() > INT32)
	{
		oper.push(second);
		oper.push(first);
		throw CmdMod::FloatingPointException();
	}

	oper.push(*second % *first);

	delete first;
	delete second;
}

void	CmdMod::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		exe(oper);
	}
	catch (CmdMod::ZeroDivideException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (CmdMod::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (CmdMod::FloatingPointException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdMod::EmptyStackException::EmptyStackException() throw() {}
CmdMod::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdMod::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdMod::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdMod::EmptyStackException &	CmdMod::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}

//ZeroDivideException---------------------------------------------------

CmdMod::ZeroDivideException::ZeroDivideException() throw() {}
CmdMod::ZeroDivideException::ZeroDivideException(ZeroDivideException const & obj) throw()
{
	*this = obj;
}
CmdMod::ZeroDivideException::~ZeroDivideException() throw() {}
const char *	CmdMod::ZeroDivideException::what() const throw()
{
	return "Division by zero.";
}
CmdMod::ZeroDivideException &	CmdMod::ZeroDivideException::operator=(ZeroDivideException const &) throw()
{
	return *this;
}

//FloatingPointException---------------------------------------------------

CmdMod::FloatingPointException::FloatingPointException() throw() {}
CmdMod::FloatingPointException::FloatingPointException(FloatingPointException const & obj) throw()
{
	*this = obj;
}
CmdMod::FloatingPointException::~FloatingPointException() throw() {}
const char *	CmdMod::FloatingPointException::what() const throw()
{
	return "Floating point in mod.";
}
CmdMod::FloatingPointException &	CmdMod::FloatingPointException::operator=(FloatingPointException const &) throw()
{
	return *this;
}
