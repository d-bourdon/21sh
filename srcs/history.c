/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:06:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/06 16:03:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <fcntl.h>

extern t_dlist *g_history;

void			add_to_history(char *line)
{
	int fd;

	if ((fd = open(".42sh_history", O_WRONLY | O_APPEND)))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
	while (g_history->prev)
		g_history = g_history->prev;
	ft_dlstadd(&g_history, ft_dlstnew(line, ft_strlen(line) + 1));
}
