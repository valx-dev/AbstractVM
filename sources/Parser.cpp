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

#include "CommandFactory.hpp"

void Parser::operate(std::vector<std::string> & vec,
                     std::stack<const IOperand *> & operands,
                     OpFactory & factory)
{

    try
    {
        const CmdFactory::commands_t cmds = CmdFactory().create(vec);

        for (const auto &cmd : cmds) {
            cmd->execute(operands, vec, factory);
        }
    }
    catch (std::exception & e)
    {
        std::cout << e.what() << std::endl;
    }
}
