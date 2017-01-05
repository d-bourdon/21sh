# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/15 14:15:13 by dbourdon          #+#    #+#              #
#    Updated: 2017/01/05 19:09:03 by dbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh

SRC = 	./src/cd/*.c ./src/env/*.c ./src/*.c

MALIB = libft/libft.a

FILE_H = -I ./includes/ -I ./libft/

OBJ = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: clean fclean re norme check

all: $(NAME)

$(NAME) : $(MALIB) $(OBG)
	-@clang $(FLAGS) $(SRC) $(FILE_H) -o $(NAME) -L./libft/ -lft -l termcap
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
	#-@make re -C libft/

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
