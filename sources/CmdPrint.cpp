/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPrint.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:45:57 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:45:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPrint.hpp"

CmdPrint::CmdPrint() {}
CmdPrint::CmdPrint(CmdPrint const & obj)
{
	*this = obj;
}
CmdPrint::~CmdPrint() {}

CmdPrint &	CmdPrint::operator=(CmdPrint const &)
{
	return *this;
}

void	CmdPrint::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		if (oper.empty())
			throw EmptyStackException();

		if (oper.top()->getType() != INT8)
			throw WrongTypeException();
		else
			std::cout << oper.top()->toString() << std::endl;
	}
	catch (CmdPrint::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (CmdPrint::WrongTypeException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdPrint::EmptyStackException::EmptyStackException() throw() {}
CmdPrint::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdPrint::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdPrint::EmptyStackException::what() const throw()
{
	return "Stack is empty.";
}
CmdPrint::EmptyStackException &	CmdPrint::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}

//WrongTypeException---------------------------------------------------

CmdPrint::WrongTypeException::WrongTypeException() throw() {}
CmdPrint::WrongTypeException::WrongTypeException(WrongTypeException const & obj) throw()
{
	*this = obj;
}
CmdPrint::WrongTypeException::~WrongTypeException() throw() {}
const char *	CmdPrint::WrongTypeException::what() const throw()
{
	return "Wrong type.";
}
CmdPrint::WrongTypeException &	CmdPrint::WrongTypeException::operator=(WrongTypeException const &) throw()
{
	return *this;
}
