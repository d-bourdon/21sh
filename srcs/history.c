/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/30 17:06:39 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/30 17:29:50 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

void			load_history(char *hist_path)
{
	char	*line;
	int		fd;
	t_list	*hist;

	hist = NULL;
	if ((fd = open(hist_path, O_RDONLY)) > 0)
		while (get_next_line(fd, &line) > 0)
			ft_lstadd(&hist, ft_lstnew(line, ft_strlen(line) + 1));
}

void			add_to_history(char *line)
{
	int fd;

	if ((fd = open(".42sh_history", O_WRONLY | O_APPEND)))
	{
		write(fd, line, ft_strlen(line));
		write(fd, "\n", 1);
		close(fd);
	}
}

void            load_prev_cmd(void)
{
    
}
