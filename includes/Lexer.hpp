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
	Lexer();
	Lexer(Lexer const &);
	~Lexer();

	std::vector<std::string>	explode(std::string const &);

	Lexer &	operator=(Lexer const &);
	
};
