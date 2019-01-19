/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdDump.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:38:18 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:19 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdDump : public ICommand
{
public:
	CmdDump();
	CmdDump(CmdDump const &);
	~CmdDump();

	CmdDump &	operator=(CmdDump const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);
};
