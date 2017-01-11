/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:03:23 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/11 18:15:33 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft.h"
# include "ft_env.h"
# include "ft_cd.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>
# include <termios.h>
# include <termcap.h>
# include <curses.h>
# include <unistd.h>
# include <fcntl.h>

typedef	struct		s_info
{
	char			*workdir;
	t_env			*env;
	struct termios	term;
	struct termios	b_term;
	int				l_win;
	int				h_win;
}					t_info;


int		my_outc(int c);
/*
** main.c :
*/
void	*singleton(void *data);

/*
** ft_init.c :
*/
void	ft_freetabtab(char **tabl);
t_env	*ft_init_env(char **environ);
t_info	*ft_init_info(char **environ);

/*
** line/line.c
*/
int		ft_line_start(t_info *info);
char	*ft_line_get(int fd);
#endif