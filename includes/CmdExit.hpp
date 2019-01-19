/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdExit.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:42:35 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:42:37 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdExit : public ICommand
{
public:
	CmdExit();
	CmdExit(CmdExit const &);
	~CmdExit();

	CmdExit &	operator=(CmdExit const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);
};
