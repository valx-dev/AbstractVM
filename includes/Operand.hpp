/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Operand.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 21:23:08 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/05 21:23:10 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "IOperand.hpp"
#include "OpFactory.hpp"

template<typename T>
class Operand : public IOperand
{
	T					_oper;
	eOperandType		_type;
	const OpFactory *	_factory;
	std::string			_str;

public:
	Operand() : _oper(0), _type(INT8), _factory(NULL)
	{
		_str = std::to_string(_oper);
	}
	Operand(T val, eOperandType type, const OpFactory * factory) : _oper(val), _type(type),  _factory(factory)
	{
		std::cout << "got new val: " << val << std::endl;
		_str = std::to_string(val);
	}
	Operand(Operand const & obj)	{	*this = obj;	}
	~Operand() {};

	IOperand const *	operator+(IOperand const & obj) const
	{
		if (this->getPrecision() > obj.getPrecision())
		{
			return _factory->createOperand(this->getType(),
				std::to_string(std::stod(this->toString()) + std::stod(obj.toString())));
		}
		else
		{
			return _factory->createOperand(obj.getType(),
				std::to_string(std::stod(this->toString()) + std::stod(obj.toString())));
		}
	}

	IOperand const *	operator-(IOperand const & obj) const
	{
		if (this->getPrecision() > obj.getPrecision())
		{
			return _factory->createOperand(this->getType(),
				std::to_string(std::stod(this->toString()) - std::stod(obj.toString())));
		}
		else
		{
			return _factory->createOperand(obj.getType(),
				std::to_string(std::stod(this->toString()) - std::stod(obj.toString())));
		}
	}

	IOperand const *	operator*(IOperand const & obj) const
	{
		if (this->getPrecision() > obj.getPrecision())
		{
			return _factory->createOperand(this->getType(),
				std::to_string(std::stod(this->toString()) * std::stod(obj.toString())));
		}
		else
		{
			return _factory->createOperand(obj.getType(),
				std::to_string(std::stod(this->toString()) * std::stod(obj.toString())));
		}
	}

	IOperand const *	operator/(IOperand const & obj) const
	{
		if (this->getPrecision() > obj.getPrecision())
		{
			return _factory->createOperand(this->getType(),
				std::to_string(std::stod(this->toString()) / std::stod(obj.toString())));
		}
		else
		{
			return _factory->createOperand(obj.getType(),
				std::to_string(std::stod(this->toString()) / std::stod(obj.toString())));
		}
	}

	IOperand const *	operator%(IOperand const & obj) const
	{
		if (obj.getType() > INT32)
			throw FloatPointException();
		if (this->getPrecision() > obj.getPrecision())
		{
			return _factory->createOperand(this->getType(),
				std::to_string(std::stoi(this->toString()) % std::stoi(obj.toString())));
		}
		else
		{
			return _factory->createOperand(obj.getType(),
				std::to_string(std::stoi(this->toString()) % std::stoi(obj.toString())));
		}
	}

	int	getPrecision() const
	{
		return _type;
	}

	eOperandType	getType() const
	{
		return _type;
	}

	std::string const &	toString() const
	{
		return _str;
	}

	class FloatPointException
	{
	public:
		FloatPointException() throw() {}
		FloatPointException(FloatPointException const & obj) throw()
		{
			*this = obj;
		}
		virtual ~FloatPointException() throw() {}
		virtual const char*	what() const throw()
		{
			return "Floating point exception.";
		}
		FloatPointException &	operator=(FloatPointException const &) throw()
		{
			return *this;
		}
	};
};
