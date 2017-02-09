# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/20 09:10:32 by oyagci            #+#    #+#              #
#    Updated: 2017/02/09 17:22:50 by oyagci           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC					= clang
CFLAGS				= -Wall -Wextra -Werror -g

NAME				= minishell

OBJSDIR				= objs
SRCSDIR				= srcs
DEPSDIR				= includes

_SRCS				= main.c \
					  count_arguments.c \
					  parse_args.c \
					  is_unescaped_quote.c \
					  is_quote.c \
					  minishell.c \
					  which.c \
					  wrap_execve.c \
					  subve.c \
					  check_for_signal.c \
					  print_prompt.c \
					  fetch_paths.c \
					  cd.c \
					  ft_errno.c \
					  sh_execute.c \
					  sh_exit.c \
					  try_execve.c \
					  print_error.c \
					  wrap_fork.c \
					  sh_launch.c \
					  getenv.c \
					  free_split.c \
					  sh_getenv.c \
					  env.c \
					  nb_args.c \
					  setenv.c \
					  printenv.c \
					  sh_setenv.c \
					  sh_echo.c \
					  sh_unsetenv.c \
					  sh_pwd.c \
					  try_chdir.c \
					  is_dir.c \
					  get_line.c \
					  put.c \
					  switch_input_mode.c \
					  autocomplete.c \
					  ft_echo.c \
					  ft_echo2.c \
					  line_parse.c \
					  ft_strsplitwq.c \
					  ft_tabtab.c \
					  line_detect_pipe.c \
					  ft_strjoinfree.c \
					  ft_hash.c \
					  ft_hash_init.c \
					  ft_erreur.c \
					  ft_info_init.c \
					  ft_env.c \
					  ft_cd.c \
					  ft_cd2.c \
					  ft_clear_path.c \
					  ft_pipe_close.c \
					  set_raw.c \
					  key.c
					  
_OBJS				= $(_SRCS:.c=.o)
_DEPS				= minishell.h msh_signals.h key.h

SRCS				= $(addprefix $(SRCSDIR)/,$(_SRCS))
OBJS				= $(addprefix $(OBJSDIR)/,$(_OBJS))
DEPS				= $(addprefix $(DEPSDIR)/,$(_DEPS))

INCLUDES			= -I libft/includes/ -I includes/
LIBS				= -L libft/ -lft -ltermcap

MKDIR				= mkdir -p

# **************************************************************************** #

all: $(NAME)

$(NAME): $(OBJS) $(DEPS)
	make -C libft/
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(INCLUDES) $(LIBS)
	@echo 'Done $(NAME)'

$(OBJSDIR)/%.o: $(SRCSDIR)/%.c
	@$(MKDIR) $(OBJSDIR)
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	$(RM) -R $(OBJSDIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C libft/

re: fclean all
