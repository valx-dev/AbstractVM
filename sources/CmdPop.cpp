/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPop.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:43:44 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:43:45 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "CmdPop.hpp"

CmdPop::CmdPop() {}
CmdPop::CmdPop(CmdPop const & obj)
{
	*this = obj;
}
CmdPop::~CmdPop() {}

CmdPop &	CmdPop::operator=(CmdPop const &)
{
	return *this;
}

void	CmdPop::execute(std::stack<const IOperand *> & oper, std::vector<std::string> & vec, OpFactory & factory)
{
	(void)vec;
	(void)factory;

	try
	{
		if (oper.empty())
			throw CmdPop::EmptyStackException();

		delete oper.top();
		oper.pop();
	}
	catch (CmdPop::EmptyStackException & e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
}

//EmptyStackException---------------------------------------------------

CmdPop::EmptyStackException::EmptyStackException() throw() {}
CmdPop::EmptyStackException::EmptyStackException(EmptyStackException const & obj) throw()
{
	*this = obj;
}
CmdPop::EmptyStackException::~EmptyStackException() throw() {}
const char *	CmdPop::EmptyStackException::what() const throw()
{
	return "Stack is empty.";
}
CmdPop::EmptyStackException &	CmdPop::EmptyStackException::operator=(EmptyStackException const &) throw()
{
	return *this;
}
