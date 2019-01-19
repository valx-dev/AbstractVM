/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:43:20 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 13:43:21 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector>
#include <string>

class Lexer
{
public:
    using words_t = std::vector<std::string>;

    Lexer() = default;
    Lexer(Lexer const &) = default;
    ~Lexer() = default;

    words_t	explode(std::string const &);

    Lexer &	operator=(Lexer const &) = default;

};
