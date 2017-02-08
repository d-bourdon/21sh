/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:51:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/06 16:08:09 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <termcap.h>
#include <termios.h>
#include <minishell.h>
#include <sys/ioctl.h>
#include <fcntl.h>

t_dlist			*g_history;
char			*g_clipboard;

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
	int	sz;

	reset_cursor(cur);
	tputs(tgetstr("cd", NULL), 1, &put);
	sz = print_prompt();
	cur->x = sz;
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
	for (int i = 0; i < 3; i++)
	{
		tputs(tgetstr("nd", NULL), 1, &put_tty);
		cur->x += 1;
	}
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
	while ((*line)->prev)
		move_cur_left(line);
}

void			jmp_line_end(t_c **line)
{
	while ((*line)->next)
		move_cur_right(line);
}

void			jmp_line_up(t_c **line)
{
	const int	x = (*line)->pos.x;
	const int	y = (*line)->pos.y - 1;

	if (y >= 0)
		while ((*line)->prev && (*line)->prev->pos.y > y)
			move_cur_left(line);
		while ((*line)->prev && (*line)->prev->pos.x != x - 1)
			move_cur_left(line);
}

void			jmp_line_down(t_c **line)
{
	const int	x = (*line)->pos.x;
	const int	y = (*line)->pos.y + 1;

	while ((*line)->next && (*line)->next->pos.y < y)
		move_cur_right(line);
	while ((*line)->next && (*line)->next->pos.x != x + 1)
		move_cur_right(line);
}

void			free_line(t_c **line)
{
	t_c	*tmp;
	t_c	*next;

	tmp = get_first(*line);
	while (tmp)
	{
		next = (*line)->next;
		free(tmp);
		tmp = next;
	}
	*line = NULL;
}

t_c				*to_line(char *str)
{
	t_c		*line;

	line = new_c(0);
	line->cursor_on = 1;
	while (*str)
	{
		add_char(&line, *str);
		str += 1;
	}
	return (line);
}

void			copy_line(t_c **line)
{
	char	*str;

	str = to_str(*line);
	if (g_clipboard)
		ft_strdel(&g_clipboard);
	g_clipboard = str;
}

void			paste_line(t_c **line)
{
	char *clipboard;

	clipboard = g_clipboard;
	while (*clipboard)
	{
		add_char(line, *clipboard);
		clipboard += 1;
	}
}

void			load_history(void)
{
	g_history = ft_dlstnew("", 1);
	ft_dlstadd(&g_history, ft_dlstnew("", 1));
}

void			load_prev_cmd(t_c **line)
{
	if (g_history->next)
		g_history = g_history->next;
	*line = to_line(g_history->content);
}

void			load_next_cmd(t_c **line)
{
	if (g_history->prev)
		g_history = g_history->prev;
	*line = to_line(g_history->content);
}

void			parse_buffer(t_c **line, char *buffer, int buf_size)
{
	if (buf_size == 1 && (ft_isprint(buffer[0]) || ft_isspace(buffer[0])) && buffer[0] != '\n')
		add_char(line, buffer[0]);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 68)
		move_cur_left(line);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 67)
		move_cur_right(line);
	else if (buffer[0] == 127)
		delete_char(line);
	else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 65)
		jmp_line_up(line);
	else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 66)
		jmp_line_down(line);
	else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 68)
		jmp_word_back(line);
	else if (buffer[0] == 27 && buffer[1] == 27 && buffer[2] == 91 && buffer[3] == 67)
		jmp_word_forward(line);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 72)
		jmp_line_begin(line);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 70)
		jmp_line_end(line);
	else if (buffer[0] == -61 && buffer[1] == -89)
		copy_line(line);
	else if (buffer[0] == -30 && buffer[1] == -120 && buffer[2] == -102)
		paste_line(line);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 65)
		load_prev_cmd(line);
	else if (buffer[0] == 27 && buffer[1] == 91 && buffer[2] == 66)
		load_next_cmd(line);
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
	add_to_history(*command_line);
	return (0);
}
