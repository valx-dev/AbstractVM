/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMachine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/04 18:51:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtualMachine.hpp"

VirtualMachine::VirtualMachine() {}
VirtualMachine::VirtualMachine(VirtualMachine const & obj)	{	*this = obj;	}
VirtualMachine::~VirtualMachine() {}

VirtualMachine &	VirtualMachine::operator=(VirtualMachine const &)
{
	return *this;
}

void	VirtualMachine::engine(std::istream & stream)
{
	std::string					buff;
	Lexer						lexer;
	Parser						parser;
	std::vector<std::string>	vec;
	OpFactory					factory;

	while (getline(stream, buff))
	{
		try
		{
			vec = lexer.explode(buff);
			parser.operate(vec, _operands, factory);
		}
		catch (std::exception & e)
		{
			std::cout << e.what() << std::endl;
		}
	}
}
