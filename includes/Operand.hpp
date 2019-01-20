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

#include <functional>

#include "IOperand.hpp"
#include "OpFactory.hpp"

template<typename T>
class Operand : public IOperand
{
    T					_oper;
    eOperandType		_type;
    const OpFactory *	_factory;
    std::string			_str;

    IOperand const *apply(IOperand const &obj,
                          std::function<double(double, double)> fn) const
    {
        const auto &type = getPrecision() > obj.getPrecision()
                ? getType() : obj.getType();

        const auto &result = fn(std::stod(toString()),
                                std::stod(obj.toString()));
        return _factory->createOperand(type, std::to_string(result));
    }

public:
    Operand() : Operand(0, INT8, nullptr) {}
    Operand(T val, eOperandType type, const OpFactory * factory)
        : _oper(val), _type(type),  _factory(factory)
    {
        std::cout << "got new val: " << val << std::endl;
        _str = std::to_string(val);
    }
    Operand(Operand const & obj)	{	*this = obj;	}
    ~Operand() {};

    IOperand const *	operator+(IOperand const & obj) const
    {
        return apply(obj, [](auto first, auto second) {
                                return first + second;
                            });
    }

    IOperand const *	operator-(IOperand const & obj) const
    {
        return apply(obj, [](auto first, auto second) {
                                return first - second;
                            });
    }

    IOperand const *	operator*(IOperand const & obj) const
    {
        return apply(obj, [](auto first, auto second) {
                                return first * second;
                            });
    }

    IOperand const *	operator/(IOperand const & obj) const
    {
        return apply(obj, [](auto first, auto second) {
                                return first / second;
                            });
    }

    IOperand const *	operator%(IOperand const & obj) const
    {
        // TODO: change function param types?
        return apply(obj, [](auto first, auto second) {
                                return int(first) % int(second);
                            });
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

    struct FloatPointException : public std::runtime_error
    {
        FloatPointException()
            : std::runtime_error("Floating point exception.")
        {}
    };
};
