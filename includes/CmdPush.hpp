/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CmdPush.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:37:58 by vkaidans          #+#    #+#             */
/*   Updated: 2019/01/10 14:38:00 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "ICommand.hpp"

class CmdPush : public ICommand
{
public:
	CmdPush();
	CmdPush(CmdPush const &);
	~CmdPush();

	CmdPush &	operator=(CmdPush const &);

	void	execute(std::stack<const IOperand *> &, std::vector<std::string> &, OpFactory &);
};
