/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:51:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/28 14:05:23 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <termcap.h>
#include <termios.h>
#include <minishell.h>
#include <sys/ioctl.h>

void			set_pos(t_pos *pos, int x, int y)
{
	pos->x = x;
	pos->y = y;
}

int				put_tty(int c)
{
	write(1, &c, 1);
	return (1);
}

t_c				*get_first(t_c *line)
{
	while (line->prev)
		line = line->prev;
	return (line);
}

int				nb_chars(t_c *line)
{
	int nb;

	nb = 0;
	while (line->next)
	{
		nb += 1;
		line = line->next;
	}
	return (nb);
}

char			*to_str(t_c *line)
{
	char	*str;
	int		i;

	line = get_first(line);
	str = ft_strnew(nb_chars(line));
	i = 0;
	while (line->next)
	{
		str[i++] = line->c;
		line = line->next;
	}
	return (str);
}

struct winsize	get_winsize(void)
{
	struct winsize	win;

	ioctl(STDIN_FILENO, TIOCGWINSZ, &win);
	return (win);
}

void			reset_cursor(t_pos *cur)
{
	while (cur->y > 0)
	{
		tputs(tgetstr("up", NULL), 1, &put);
		cur->y -= 1;
	}
	tputs(tgetstr("cr", NULL), 1, &put);
	cur->x = 0;
}

void			clear_line(t_pos *cur)
{
	reset_cursor(cur);
	tputs(tgetstr("cd", NULL), 1, &put);
}

t_c				*new_c(char c)
{
	t_c *new;

	new = (t_c *)ft_memalloc(sizeof(t_c));
	new->c = c;
	return (new);
}

void			add_char(t_c **line, char c)
{
	t_c	*new;

	new = new_c(c);
	new->next = *line;
	new->prev = (*line)->prev;
	if (new->prev)
		new->prev->next = new;
	(*line)->prev = new;
}

void			delete_char(t_c **line)
{
	if ((*line)->prev)
	{
		(*line)->prev = (*line)->prev->prev;
		if ((*line)->prev)
			(*line)->prev->next = (*line);
	}
}

void			move_cur_left(t_c **line)
{
	if ((*line)->prev)
	{
		(*line)->cursor_on = 0;
		*line = (*line)->prev;
		(*line)->cursor_on = 1;
	}
}

void			move_cur_right(t_c **line)
{
	if ((*line)->next)
	{
		(*line)->cursor_on = 0;
		*line = (*line)->next;
		(*line)->cursor_on = 1;
	}
}

void			set_raw(struct termios *save)
{
	struct termios			t_attr;

	(void)save;
	tcgetattr(STDIN_FILENO, &t_attr);
	t_attr.c_cc[VTIME] = 0;
	t_attr.c_cc[VMIN] = 1;
	t_attr.c_lflag &= ~(ECHO | ICANON);
	tcsetattr(STDIN_FILENO, TCSANOW, &t_attr);
}

void			put_cursor(t_c *line, t_pos *cur)
{
	const struct winsize	win = get_winsize();

	line = get_first(line);
	reset_cursor(cur);
	while (line && !line->cursor_on)
	{
		if (cur->x >= win.ws_col - 1)
		{
			ft_putchar('\n');
			cur->x = 0;
			cur->y += 1;
		}
		tputs(tgetstr("nd", NULL), 1, &put_tty);
		cur->x += 1;
		line = line->next;
	}
}

void			set_index(t_c *line)
{
	const struct winsize	win = get_winsize();
	t_pos					p;

	line = get_first(line);
	p.x = 0;
	p.y = 0;
	while (line)
	{
		if (p.x >= win.ws_col - 1)
		{
			p.x = 0;
			p.y += 1;
		}
		line->pos.x = p.x;
		line->pos.y = p.y;
		p.x += 1;
		line = line->next;
	}
}

void			print_line(t_c *line, t_pos *cur)
{
	const struct winsize	win = get_winsize();

	line = get_first(line);
	clear_line(cur);
	while (line && line->c != 0)
	{
		if (cur->x >= win.ws_col - 1)
		{
			ft_putchar('\n');
			cur->x = 0;
			cur->y += 1;
		}
		ft_putchar(line->c);
		cur->x += 1;
		line = line->next;
	}
	put_cursor(line, cur);
	set_index(line);
}

void			jmp_word_back(t_c **line)
{
	move_cur_left(line);
	while ((*line)->prev && ft_isspace((*line)->prev->c))
		move_cur_left(line);
	while ((*line)->prev && !ft_isspace((*line)->prev->c))
		move_cur_left(line);
}

void			jmp_word_forward(t_c **line)
{
	move_cur_right(line);
	while ((*line)->next && ft_isspace((*line)->next->c) && (*line)->next->c != 0)
		move_cur_right(line);
	while ((*line)->next && !ft_isspace((*line)->next->c) && (*line)->next->c != 0)
		move_cur_right(line);
	move_cur_right(line);
}

void			jmp_line_begin(t_c **line)
{
	while ((*line)->prev && (*line)->prev->pos.x != 0)
		move_cur_left(line);
}

void			parse_buffer(t_c **line, char *buffer, int buf_size)
{
	if (buf_size == 1 && (ft_isprint(buffer[0]) || ft_isspace(buffer[0])) && buffer[0] != '\n')
		add_char(line, buffer[0]);
	else if (buf_size == 3 && buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		move_cur_left(line);
	else if (buf_size == 3 && buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		move_cur_right(line);
	else if (buf_size == 1 && buffer[0] == 127)
		delete_char(line);
	else if (buf_size == 4 && buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 68)
		jmp_word_back(line);
	else if (buf_size == 4 && buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 67)
		jmp_word_forward(line);
	else if (buf_size == 3 && buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 72)
		jmp_line_begin(line);
}

int				ft_get_command_line(char **command_line)
{
	char	buffer[8];
	int		sz;
	t_c		*line;
	t_pos	pos;

	pos.x = 0;
	pos.y = 0;
	set_pos(&pos, 0, 0);
	line = new_c(0);
	line->cursor_on = 1;
	set_raw(NULL);
	while (42)
	{
		sz = read(STDIN_FILENO, buffer, 8);
		parse_buffer(&line, buffer, sz);
		print_line(line, &pos);
		if (buffer[0] == '\n')
			break ;
	}
	ft_putchar('\n');
	*command_line = to_str(line);
	return (0);
}
