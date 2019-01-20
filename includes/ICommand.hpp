/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICommand.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:36:08 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:36:18 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <vector>
#include <stack>
#include <memory>

#include "IOperand.hpp"
#include "Operand.hpp"
#include "OpFactory.hpp"

class ICommand
{
public:
    using Ptr = std::shared_ptr<ICommand>;

    using operations_t = std::stack<const IOperand *>;
    using args_t = std::vector<std::string>;

    virtual void execute(operations_t &, args_t &, OpFactory &) = 0;

    virtual ~ICommand() = default;
};
