# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/06/15 14:15:13 by dbourdon          #+#    #+#              #
#    Updated: 2017/01/19 13:14:47 by dbourdon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 21sh
LIB_NAME = libft/libft.a
INC_DIR = includes
SRC_DIR = src
OBJ_DIR = obj

SRCS = 	./src/cd/ft_cd.c \
		./src/cd/ft_cd2.c \
		./src/cd/ft_clear_path.c \
		./src/env/ft_env.c \
		./src/ft_init.c \
		./src/main.c  \
		./src/line/line.c \
		./src/line/parse.c \
		./src/ft_strsplitwq.c \
		./src/detect_cmd.c 


OBJS = $(SRCS:$(SRCS)%.c=$(OBJ_DIR)/%.o)

IFLAGS = -I $(INC_DIR) -I libft
FLAGS = -Wall -Werror -Wextra

CC = clang $(FLAGS)
LIBFLAGS = -Llibft -lft
RM = /bin/rm -f

all: $(LIB_NAME) $(NAME)

$(LIB_NAME) :
	@make -C libft re

$(NAME) : $(OBJS)
	@echo "Make Objects :\033[1;32m DONE !\033[m"
	@$(CC) $(IFLAGS) -o $@ $^ $(LIBFLAGS) -l termcap
	@echo "Make $(NAME) :\033[1;32m DONE !\033[m"

$(OBJ_DIR)/%.o: $(SRCS).c
	@$(CC) $(IFLAGS) -o $@ -c $<

clean:
	@make -C libft clean
	@echo "Make clean :\033[1;31m DONE !\033[m"

fclean : clean
	@$(RM) $(NAME)
	@make -C libft fclean
	@echo "Make fclean :\033[1;31m DONE !\033[m"

re: fclean all

.PHONY: all clean fclean re