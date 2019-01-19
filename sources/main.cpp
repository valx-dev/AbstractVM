/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 15:13:56 by vkaidans          #+#    #+#             */
/*   Updated: 2018/12/03 15:13:58 by vkaidans         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include "VirtualMachine.hpp"

int	main(int argc, char ** argv)
{
	(void)argc;
	(void)argv;
	VirtualMachine vm;

	if (argc == 2)
	{
		std::ifstream	file(argv[1]);
		
		if (file.is_open())
		{
			vm.engine(file);
		}
		else
		{
			std::cerr << "file don't exist\n";
		}
	}
	else
	{
		vm.engine(std::cin);
	}

	// stack stack;

	// while (input == true)
	// {
	// 	if push int8 - double
	// 		stack += add new operand
	// 	if math
	// 		do math
	// 	if dump
	// 		show_stack()
	// 	if assert

	// }
	system("leaks avm");
	return (0);
}
