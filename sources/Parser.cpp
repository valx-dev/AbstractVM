/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parser.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 11:47:15 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 11:47:17 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.hpp"

Parser::Parser()
{
	_commands["push"] = new CmdPush;
	_commands["pop"] = new CmdPop;
	_commands["dump"] = new CmdDump;
	_commands["assert"] = new CmdAssert;
	_commands["add"] = new CmdAdd;
	_commands["sub"] = new CmdSub;
	_commands["mul"] = new CmdMul;
	_commands["div"] = new CmdDiv;
	_commands["mod"] = new CmdMod;
	_commands["print"] = new CmdPrint;
	_commands["exit"] = new CmdExit;
}
Parser::Parser(Parser const &) {}
Parser::~Parser()
{
	for (std::map<std::string, ICommand *>::iterator it = _commands.begin(); it != _commands.end(); it++)
		delete it->second;
}

Parser &	Parser::operator=(Parser const &)
{
	return *this;
}

void	Parser::operate(std::vector<std::string> & vec, std::stack<const IOperand *> & operands, OpFactory & factory)
{
	try
	{
		_commands.at(vec.at(0))->execute(operands, vec, factory);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}
}
