/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   OpFactory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 17:17:24 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/06 17:17:25 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "OpFactory.hpp"
#include "Operand.hpp"

OpFactory::OpFactory() {}
OpFactory::OpFactory(OpFactory const & obj) { *this = obj;	}
OpFactory::~OpFactory() {}

OpFactory &	OpFactory::operator=(OpFactory const &)
{
    return *this;
}

IOperand const * OpFactory::createInt8(std::string const & val) const
{
    return new Operand<char>(std::stoi(val), INT8, this);
}

IOperand const * OpFactory::createInt16(std::string const & val) const
{
    return new Operand<short>(std::stoi(val), INT16, this);
}

IOperand const * OpFactory::createInt32(std::string const & val) const
{
    return new Operand<int>(std::stoi(val), INT32, this);
}

IOperand const * OpFactory::createFloat(std::string const & val) const
{
    return new Operand<float>(std::stof(val), FLOAT, this);
}

IOperand const * OpFactory::createDouble(std::string const & val) const
{
    return new Operand<double>(std::stod(val), DOUBLE, this);
}

eOperandType OpFactory::fromString(const std::string &stype)
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
}

IOperand const *OpFactory::createOperand(std::string const & type,
                                         std::string const & val) const
{
    return createOperand(fromString(type), val);
}

IOperand const *OpFactory::createOperand(eOperandType type,
                                         std::string const & val) const
{
    switch (type)
    {
        case(INT8):		return createInt8(val);		break;
        case(INT16):	return createInt16(val);	break;
        case(INT32):	return createInt32(val);	break;
        case(FLOAT):	return createFloat(val);	break;
        case(DOUBLE):	return createDouble(val);	break;
        default:		return NULL;
    }
}

