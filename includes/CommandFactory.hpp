/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   CommandFactory.hpp                                 :+:      :+:    :+:   */
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

#include "ICommand.hpp"

class CmdFactory
{
    using command_map_t = std::map<std::string, ICommand::Ptr>;
    command_map_t _commands;

    template <typename T>
    inline void register_command()
    {
        const auto &item = _commands.emplace(
                    std::make_pair(T::id(), std::make_unique<T>()));
        if (!item.second) {
            throw std::runtime_error("element already registered: " + T::id());
        }
    }

public:
    using commands_t = std::vector<ICommand::Ptr>;
    CmdFactory();

    // TODO: makeup a better name
    commands_t create(const std::vector<std::string> &list);
};
