/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   VirtualMachine.hpp                                 :+:      :+:    :+:   */
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


class VirtualMachine
{
	std::stack<const IOperand *>		_operands;
	
public:
	VirtualMachine();
	VirtualMachine(VirtualMachine const &);
	~VirtualMachine();

	VirtualMachine &	operator=(VirtualMachine const &);

	void	engine(std::istream &);
};
