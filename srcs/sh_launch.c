/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 13:59:46 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell.h>
#include <signal.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_errno.h>

int		sh_launch_env(t_cmd *cmd, char **env)
{
	pid_t	pid;
	int		status;

	if (access(cmd->av[0], X_OK) >= 0)
	{
		pid = wrap_fork();
		if (pid == 0)
		{
			try_execve(cmd->av[0], cmd->av, env);
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, WUNTRACED);
			check_for_signal(status, cmd->av[0]);
		}
		else
			ft_putendl_fd(ft_strerror(g_errno), 2);
	}
	else
	{
		g_errno = FT_ENOCMD;
		return (-1);
	}
	return (1);
}
