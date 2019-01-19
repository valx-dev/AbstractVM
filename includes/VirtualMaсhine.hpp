/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMaсhine.hpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 18:51:24 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/04 18:51:26 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <fstream>
#include <iostream>
#include <stack>
#include <map>
#include "IOperand.hpp"
#include "Operand.hpp"
#include "Lexer.hpp"
#include "Parser.hpp"


class VirtualMaсhine
{
	std::stack<const IOperand *>		_operands;
	
public:
	VirtualMaсhine();
	VirtualMaсhine(VirtualMaсhine const &);
	~VirtualMaсhine();

	VirtualMaсhine &	operator=(VirtualMaсhine const &);

	void	engine(std::istream &);
};
