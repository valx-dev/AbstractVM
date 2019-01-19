/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lexer.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/08 13:43:45 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/08 13:43:46 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Lexer.hpp"

Lexer::words_t Lexer::explode(std::string const & str)
{
    std::string	buff;
    words_t	vec;

    for (auto n:str) {
        if (n != ' ' && n != '(' && n != ')') {
            buff += n;
        } else if ((n == ' ' || n == '(' || n == ')') && buff != "") {
            vec.push_back(buff);
            buff = "";
        }
    }
    if (buff != "") {
        vec.push_back(buff);
    }
    return vec;
}
