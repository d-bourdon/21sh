/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:05:59 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/11 18:49:58 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"
# include <term.h>
#include <curses.h>

int		my_outc(int c)
{
	ft_putchar_fd(0, c);
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
	 info->term.c_lflag = (ICANON | ECHO);
	 //info->term.c_cflag &=  
	 info->term.c_cc[VMIN] = 1;
	 info->term.c_cc[VTIME] = 0;
	 if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
	 	return (-1);
	tputs(tgetstr("ti", NULL), 1, my_outc);
	tputs(tgetstr("im", NULL), 1, my_outc);
	return (0);
}

char	*ft_line_get(int fd)
{
	char	buff[3];
	char	*line = NULL;
	fd = 0;
/*
** On utilise la fonction tgoto, qui va retourner une série d'instructions (sous forme de chaine de caractère)
** afin de déplacer le curseur jusqu'à l'endroit voulu.
*/
//tputs(tgoto(res, pos_x, pos_y), 1, my_outc);
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
				//printf("IN\n");
				//tputs(tgetstr("le", NULL), 1, my_outc);
			}
		if (buff[0] == 27 && buff[1] == 91 && buff[2] == 67)
			{
				//printf("IN\n");
				tputs(tgoto(tgetstr("cm", NULL), 60, 1), 1, my_outc);
				//tputs(tgetstr("nd", NULL), 1, my_outc);
			}
		else
		{
			//ft_putstr_fd(buff, 3);
			//printf("%s", buff);
		}
	}
}