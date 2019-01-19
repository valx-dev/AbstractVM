# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vkaidans <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 10:57:41 by vkaidans          #+#    #+#              #
#    Updated: 2018/10/13 10:57:42 by vkaidans         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = avm

SRC_DIR :=	./sources/
OBJ_DIR :=	./objects/
INC_DIR :=	./includes/

SRC =	main.cpp VirtualMachine.cpp OpFactory.cpp \
		Lexer.cpp Parser.cpp \
		CmdPush.cpp CmdDump.cpp CmdPop.cpp CmdAssert.cpp CmdPrint.cpp \
		CmdAdd.cpp CmdSub.cpp CmdDiv.cpp CmdMul.cpp CmdMod.cpp \
		CmdExit.cpp

OBJ = $(addprefix $(OBJ_DIR), $(SRC:.cpp=.o))

FLAGS = -Wall -Wextra -Werror

.SILENT:

all: $(NAME)

$(NAME): $(OBJ)
	clang++ -std=c++11 $(FLAGS) $(OBJ) -o $(NAME)
	printf '\033[32m[ ✔ ] %s\n\033[0m' "Created avm"

$(OBJ): | $(OBJ_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_DIR)%.o: %.cpp
	clang++ -std=c++11 -c $< -o $@ $(FLAGS) -I $(INC_DIR)

clean:
	rm -f $(OBJ)
	rm -r $(OBJ_DIR)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Cleaned avm"

fclean: clean
	rm -f $(NAME)
	printf '\033[31m[ ✔ ] %s\n\033[0m' "Fcleaned avm"

re: fclean all

vpath %.cpp $(SRC_DIR)

.PHONY: all clean fclean all
