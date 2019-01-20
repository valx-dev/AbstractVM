/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:06 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 11:47:08 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <string>
#include <vector>
#include <stack>

#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "ICommand.hpp"

class Parser
{
public:
    void operate(std::vector<std::string> &,
                 std::stack<const IOperand *> &, OpFactory &);

};
