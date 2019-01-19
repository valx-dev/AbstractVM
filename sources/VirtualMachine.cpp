/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMaсhine.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:44 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/04 18:51:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "VirtualMaсhine.hpp"

VirtualMaсhine::VirtualMaсhine() {}
VirtualMaсhine::VirtualMaсhine(VirtualMaсhine const & obj)	{	*this = obj;	}
VirtualMaсhine::~VirtualMaсhine() {}

VirtualMaсhine &	VirtualMaсhine::operator=(VirtualMaсhine const &)
{
	return *this;
}

void	VirtualMaсhine::engine(std::istream & stream)
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
