/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:06:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 17:35:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <fcntl.h>
#include <stdlib.h>

t_dlist			*g_history;
int				g_index;

void			load_history(char *hist_path)
{
	int		fd;
	char	*line;

	g_history = NULL;
	if (0 && (fd = open(hist_path, O_RDONLY | O_CREAT, 0666)) > 0)
	{
		while (get_next_line(fd, &line) > 0)
		{
			ft_dlstadd(&g_history, ft_dlstnew(line, ft_strlen(line) + 1));
			free(line);
		}
		free(line);
		close(fd);
	}
	else
	{
		ft_dlstadd(&g_history, ft_dlstnew("echo Hello World", sizeof("echo Hello World")));
		ft_dlstadd(&g_history, ft_dlstnew("", 1));
	}
}

void			add_to_history(char *line)
{
	int		fd;
	size_t	len;

	if ((fd = open(".42sh_history", O_WRONLY | O_APPEND | O_CREAT, 0666)))
	{
		if ((len = ft_strlen(line)))
		{
			write(fd, line, ft_strlen(line));
			write(fd, "\n", 1);
		}
		close(fd);
	}
	while (g_history && *((char *)(g_history->content)) != 0 && g_history->prev)
		g_history = g_history->prev;
	ft_dlstadd(&g_history, ft_dlstnew(line, len + 1));
}

void			load_prev_cmd(t_c **line)
{
	if (g_history && g_history->prev)
	{
		g_history = g_history->prev;
		free_line(line);
		*line = to_line(g_history->content);
	}
}

void			load_next_cmd(t_c **line)
{
	if (g_history && g_history->next)
	{
		g_history = g_history->next;
		free_line(line);
		*line = to_line(g_history->content);
	}
}
