/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdAssert.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:44:04 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:44:05 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdAssert.hpp"

CmdAssert::CmdAssert() {}
CmdAssert::CmdAssert(CmdAssert const & obj)
{
	*this = obj;
}
CmdAssert::~CmdAssert() {}

CmdAssert &	CmdAssert::operator=(CmdAssert const &)
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

void	CmdAssert::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	try
	{
		if (oper.empty())
			throw CmdAssert::EmptyStackException();

		const IOperand * tmp = factory.createOperand(typer(vec.at(1)), vec.at(2));

		if (tmp->getPrecision() != oper.top()->getPrecision())
		{
			delete tmp;
			throw CmdAssert::NonEqualException();
		}
		if (tmp->toString() != oper.top()->toString())
		{
			delete tmp;
			throw CmdAssert::NonEqualException();
		}
		delete tmp;
	}
	catch (CmdAssert::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	catch (CmdAssert::NonEqualException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdAssert::EmptyStackException::EmptyStackException() throw() {}
CmdAssert::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdAssert::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdAssert::EmptyStackException::what() const throw()
{
	return "Not enough arguments.";
}
CmdAssert::EmptyStackException &	CmdAssert::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}

//NonEqualException---------------------------------------------------

CmdAssert::NonEqualException::NonEqualException() throw() {}
CmdAssert::NonEqualException::NonEqualException(NonEqualException const & obj) throw()
{
	*this = obj;
}
CmdAssert::NonEqualException::~NonEqualException() throw() {}
const char *	CmdAssert::NonEqualException::what() const throw()
{
	return "Assert failed.";
}
CmdAssert::NonEqualException &	CmdAssert::NonEqualException::operator=(NonEqualException const &) throw()
{
	return *this;
}
