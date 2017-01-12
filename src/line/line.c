/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:05:59 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/12 18:03:49 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
# include <term.h>
#include <curses.h>

int		my_outc(int c)
{
	ft_putchar(c);
	return (1);
}

int		ft_line_start(t_info *info)
{
	char	*name_term;

	if ((name_term = getenv("TERM")) == NULL)
		name_term = ft_strdup("vt100");
	if (tgetent(NULL, name_term) == -1)
		return (-1);
	if (tcgetattr(0, &(info->term)) == -1)
		return (-1);
	if (tcgetattr(0, &(info->b_term)) == -1)
		return (-1);
	 info->term.c_lflag  &= ~(ICANON);
	 info->term.c_lflag  &= ~(ECHO);
	 info->term.c_cc[VMIN] = 1;
	 info->term.c_cc[VTIME] = 0;
	 if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
	 	return (-1);
	tputs(tgetstr("im", NULL), 1, my_outc);
	return (0);
}

char	*ft_line_get(int fd)
{
	char	buff[3];
	char	*line = ft_strdup("-");
	fd = 0;
	while (1)
	{
		buff[0] = 0;
		buff[1] = 0;
		buff[2] = 0;
		read(0, buff, 3);
		if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0)
			return (line);
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 68)
			{
				tputs(tgetstr("le", NULL), 1, my_outc);
			}
		else if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
			{
				tputs(tgetstr("nd", NULL), 1, my_outc);
			}
		else if (buff[0] == 127)
		{
				tputs(tgetstr("le", NULL), 1, my_outc);
				tputs(tgetstr("dc", NULL), 1, my_outc);
				//tputs(tgetstr("nd", NULL), 1, my_outc);
		}
		else if (buff[0] == 9)
			tputs("\t", 1, my_outc);
		else
		{
		line = ft_strjoinfree(line, &buff[0], 1);
			//printf("%d - %d - %d\n", buff[0], buff[1], buff[2]);
			write(1, &buff[0], 1);
		}
	}
}
