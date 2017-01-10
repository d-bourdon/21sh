/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 15:05:59 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/10 17:33:10 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "line.h"


int		ft_line_start(t_term *info)
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
	info->term.c_lflag &= ~(ICANON);
	info->term.c_lflag &= ~(ECHO);
	info->term.c_cc[VMIN] = 1;
	info->term.c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, &(info->term)) == -1)
		return (-1);
	//tputs(tgetstr("vi", NULL), 1, my_outc);
	return (0);
}

char	*ft_line_get(int fd)
{
	char	buff[3];
	char	*line;

	while (1)
	{
		read(0, buff, 3);
		if (buff[0] == 10 && buff[1] == 0 && buff[2] == 0)
			return (line);
		else
			printf("%d %d %d - %c %c %c - %s\n", buff[0], buff[1], buff[2], buff[0], buff[1], buff[2], buff);
	}
}