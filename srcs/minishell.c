/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:24:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/27 16:58:07 by dbourdon         ###   ########.fr       */
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
				cmd = cmd->next;
			}
			free(line);
			cmd = NULL; // Warning // fonction free_cmd(cmd);
		}
	}
	line ? free(line) : (void)0;
	return (1);
}
