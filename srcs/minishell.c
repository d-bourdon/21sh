/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:24:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/10 15:26:20 by dbourdon         ###   ########.fr       */
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
				printf("ROUTE FD = %s\n", tmp_cmd->routefd);
				ft_def_routefd(tmp_cmd->routefd);
				if (g_errno == FT_ENOSYN)
					break ;
				if ((status = sh_execute(tmp_cmd)) == -1)
					print_error(ft_strerror(g_errno));
				if (tmp_cmd->pipe)
					tmp_cmd = ft_next_to_pipe(tmp_cmd);
				else
					tmp_cmd = tmp_cmd->next;
			}
			ft_reset_fd();
			free(line);
			ft_free_cmd(cmd);
		}
	}
	line ? free(line) : (void)0;
	return (1);
}
