/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IOperand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:49:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/03 15:49:14 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

enum eOperandType{ INT8, INT16, INT32, FLOAT, DOUBLE};

class IOperand
{
public:
	virtual int				getPrecision(void) const = 0;
	virtual eOperandType	getType(void) const = 0;

	virtual IOperand const *	operator+(IOperand const &) const = 0;
	virtual IOperand const *	operator-(IOperand const &) const = 0;
	virtual IOperand const *	operator*(IOperand const &) const = 0;
	virtual IOperand const *	operator/(IOperand const &) const = 0;
	virtual IOperand const *	operator%(IOperand const &) const = 0;

	virtual std::string const &	toString(void) const = 0;

	virtual ~IOperand(void) {};
};
