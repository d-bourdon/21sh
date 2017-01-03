# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/15 14:15:13 by dbourdon          #+#    #+#              #
#    Updated: 2017/01/03 14:55:01 by dbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = 	./src/*

MALIB = libft/libft.a

FILE_H = -I ./includes/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re norme check

all: $(NAME)

$(NAME) : $(MALIB) $(OBG)
	-@clang $(FLAGS) $(SRC) $(FILE_H) -g -o $(NAME) -L./libft/ -lft -l termcap
	@echo "Compilation"

$(MALIB):
	-@make -C libft/

clean: 
	-@make -C libft/ clean
	-@rm -f $(OBJ) *.gch
	@echo "Supression"

fclean: clean
	-@rm -f $(NAME)
	-@make -C libft/ fclean
	@echo "totale..."

re: fclean all
	-@make re -C libft/

norme:
	@norminette ./includes/*.[ch] ./src/*.[ch] ./libft/*.[ch]

check:
	@echo "***** Verification norme :"
	@make norme
	@echo "***** Verification auteur :"
	cat -e auteur
	@echo "***** Lancement du make re ... "
	@make re
	@echo "***** Fini !"
