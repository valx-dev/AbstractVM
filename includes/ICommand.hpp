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
#include "IOperand.hpp"
#include "Operand.hpp"
#include "OpFactory.hpp"

class ICommand
{
public:
	virtual void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &) = 0;

	virtual ~ICommand() {};	
};
