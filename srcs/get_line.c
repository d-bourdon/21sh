/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_line.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:51:23 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/09 17:35:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <libft.h>
#include <minishell.h>
#include <key.h>

t_keycode		key_get(const char *const buffer)
{
	t_key_funcs const	key_funcs[] = {
		{ KEYCODE_UP, key_is_up },
		{ KEYCODE_DOWN, key_is_down },
		{ KEYCODE_RIGHT, key_is_right },
		{ KEYCODE_LEFT, key_is_left },
		{ KEYCODE_ENTER, key_is_enter },
		{ KEYCODE_DELETE, key_is_delete },
		{ KEYCODE_CTRL_D, key_is_ctrl_d },
		{ KEYCODE_CTRL_C, key_is_ctrl_c },
		{ KEYCODE_NONE, NULL }
	};
	int					i;

	i = 0;
	while (key_funcs[i].f != NULL)
	{
		if (key_funcs[i].f(buffer))
			return (key_funcs[i].keycode);
		i += 1;
	}
	return (KEYCODE_NONE);
}

t_keycode		parse_input(char *input, t_dlist **line)
{
	const t_keycode	key = key_get(input);

	(void)line;
	if (key == KEYCODE_ENTER)
	{
	}
	else if (key == KEYCODE_NONE)
		; //line_add_character();
	return (key);
}

int				get_line(char **command_line)
{
	char	buf[8];
	t_dlist	*line;
	int		size;

	line = NULL;
	*command_line = ft_strdup("ls\n");
	set_raw();
	while (42)
	{
		size = read(STDIN_FILENO, buf, 8);
		if (parse_input(buf, &line) == KEYCODE_ENTER)
			break ;
	}
	unset_raw();
	return (1);
}