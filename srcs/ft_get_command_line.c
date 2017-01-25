/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_command_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:51:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/10 10:41:01 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <libft.h>
#include <termcap.h>
#include <termios.h>
#include <minishell.h>

void	move_cursor(char *cmd_line, char *c, size_t *cur_pos)
{
	if (c[0] == 27 && c[1] == 91)
	{
		if (c[2] == 68 && *cur_pos > 0)
		{
			tputs(tgetstr("le", NULL), 0, &put);
			*cur_pos -= 1;
		}
		if (c[2] == 67 && *cur_pos < ft_strlen(cmd_line))
		{
			tputs(tgetstr("nd", NULL), 0, &put);
			*cur_pos += 1;
		}
	}
}

void	erase_char(char **cmd_line, char *c, size_t *cur_pos)
{
	if (c[0] == 127 && c[1] == 0 && *cur_pos > 0)
	{
		tputs(tgetstr("le", NULL), 0, &put);
		tputs(tgetstr("dc", NULL), 0, &put);
		ft_memmove(&(cmd_line[0][*cur_pos - 1]),
				&(cmd_line[0][*cur_pos]),
				ft_strlen(&(cmd_line[0][*cur_pos])) + 1);
		*cur_pos -= 1;
	}
}

void	print_char(char **cmd_line, char *c, size_t *cur_pos)
{
	char	*tmp;

	if (ft_isprint(c[0]) && c[1] == 0)
	{
		tputs(tgetstr("im", NULL), 0, &put);
		tputs(tgetstr("ic", NULL), 0, &put);
		tmp = ft_strjoin_at(*cmd_line, c, *cur_pos);
		free(*cmd_line);
		*cmd_line = tmp;
		write(STDOUT_FILENO, c, 1);
		*cur_pos += 1;
		tputs(tgetstr("ei", NULL), 0, &put);
	}
}

void	clear_screen(char **line, size_t *cur_pos)
{
	tputs(tgetstr("cl", NULL), 0, &put);
	free(*line);
	*line = ft_strnew(0);
	print_prompt();
	*cur_pos = 0;
}

int		ft_get_command_line(char **command_line)
{
	char		c[3];
	size_t		cur_pos;
	short		loop;

	cur_pos = 0;
	*command_line = ft_strnew(0);
	switch_input_mode();
	loop = 1;
	while (loop)
	{
		ft_bzero(c, 3);
		read(STDIN_FILENO, &c, 3);
		print_char(command_line, c, &cur_pos);
		c[0] == '\n' ? (int)(put('\n') && (loop = 0)) : (void)0;
		c[0] == 4 ? exit(switch_input_mode()) : (void)0;
		c[0] == 12 ? clear_screen(command_line, &cur_pos) : (void)0;
		autocomplete(*command_line, c, &cur_pos);
		move_cursor(*command_line, c, &cur_pos);
		erase_char(command_line, c, &cur_pos);
	}
	switch_input_mode();
	return (1);
}
