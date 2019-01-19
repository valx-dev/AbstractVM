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

#include <iostream>
#include <map>
#include <vector>
#include <stack>
#include "IOperand.hpp"
#include "OpFactory.hpp"
#include "ICommand.hpp"
#include "CmdPush.hpp"
#include "CmdPop.hpp"
#include "CmdDump.hpp"
#include "CmdAssert.hpp"
#include "CmdAdd.hpp"
#include "CmdSub.hpp"
#include "CmdMul.hpp"
#include "CmdDiv.hpp"
#include "CmdMod.hpp"
#include "CmdPrint.hpp"
#include "CmdExit.hpp"

// typedef void (*func)(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);

class Parser
{
	std::map<std::string, ICommand *>	_commands;

public:
	Parser();
	Parser(Parser const &);
	~Parser();

	Parser &	operator=(Parser const &);

	void	operate(std::vector<std::string> &, std::stack<const IOperand *> &, OpFactory &);
	
};
