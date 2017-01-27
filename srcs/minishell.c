/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:24:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/27 18:01:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <ft_errno.h>
#include <termcap.h>

void	sigint_parent(int signal)
{
	ft_putchar('\n');
	(void)signal;
}

int		minishell(void)
{
	char	*line;
	t_cmd	*cmd;
	t_cmd	*tmp_cmd;
	int		status;

	line = NULL;
	status = 1;
	while (status)
	{
		signal(SIGINT, sigint_parent);
		print_prompt();
		ft_get_command_line(&line);
		if (line != NULL)
		{
			cmd = ft_line_parse(line);
			ft_line_detect_pipe(cmd);
			tmp_cmd = cmd;
			while (tmp_cmd)
			{
				if ((status = sh_execute(cmd->av)) == -1)
					print_error(ft_strerror(g_errno));
				tmp_cmd = tmp_cmd->next;
			}
			free(line);
			ft_free_cmd(cmd);
		}
	}
	line ? free(line) : (void)0;
	return (1);
}
