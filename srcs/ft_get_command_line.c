/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:51:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/26 17:51:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <termcap.h>
#include <termios.h>
#include <minishell.h>

void			unset_raw(struct termios *t);

t_c				*new_c(char c)
{
	t_c		*new;

	new = (t_c *)ft_memalloc(sizeof(t_c));
	new->c = c;
	return (new);
}

void			set_raw(void)
{
	struct termios	t_attr;

	tcgetattr(STDIN_FILENO, &t_attr);
	unset_raw(&t_attr);
	t_attr.c_lflag &= ~(ECHO | ICANON);
	t_attr.c_cc[VTIME] = 0;
	t_attr.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &t_attr);
}

void			unset_raw(struct termios *t)
{
	static struct termios t_attr;

	if (t)
		ft_memcpy(&t_attr, t, sizeof(*t));
	else
		tcsetattr(STDIN_FILENO, TCSAFLUSH, &t_attr);
}

void			add_char(t_c **line, char c)
{
	t_c		*new;

	new = new_c(c);
	new->next = *line;
	new->prev = (*line)->prev;
	if (new->prev)
		new->prev->next = new;
	(*line)->prev = new;
}

void			parse_buffer(char *buffer, int buf_size, t_c **line)
{
	if (buf_size == 1 && (ft_isprint(buffer[0]) || ft_isspace(buffer[0])))
	{
		add_char(line, buffer[0]);
	}
}

size_t			depth_c(t_c *line)
{
	size_t	depth;

	depth = 0;
	while (line && line->c != 0)
	{
		depth += 1;
		line = line->next;
	}
	return (depth);
}

char			*to_str(t_c *line)
{
	char	*str;
	size_t	i;

	while (line->prev)
		line = line->prev;
	str = ft_strnew(depth_c(line));
	i = 0;
	while (line->next)
	{
		str[i++] = line->c;
		line = line->next;
	}
	return (str);
}

void			print_line(t_c *line)
{
	while (line->prev)
		line = line->prev;
	while (line->next)
	{
		ft_putchar(line->c);
		line = line->next;
	}
}

int				ft_get_command_line(char **command_line)
{
	char	buffer[8];
	int		nb_read;
	t_c		*line;

	line = new_c(0);
	set_raw();
	while (42)
	{
		ft_bzero(buffer, 8);
		nb_read = read(STDIN_FILENO, buffer, 8);
		parse_buffer(buffer, nb_read, &line);
		print_line(line);
		if (buffer[0] == '\n')
			break ;
	}
	unset_raw(0);
	*command_line = to_str(line);
	return (1);
}
