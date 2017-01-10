/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:06:53 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/10 17:35:46 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <termios.h>
# include <curses.h>
# include <unistd.h>
//# include <term.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct		s_term
{
	struct termios	term;
	struct termios	b_term;
	int				l_win;
	int				h_win;
}					t_term;

int		ft_line_start(t_term *info);
char	*ft_line_get(int fd);

#endif