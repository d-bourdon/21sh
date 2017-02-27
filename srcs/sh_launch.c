/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/12 14:46:15 by dbourdon         ###   ########.fr       */
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
	int		fd;

	fd = -2;
	if (access(cmd->av[0], X_OK) >= 0)
	{
		if (cmd->infile != NULL)
			fd = ft_open_redir(cmd->infile);
		if (fd == -1)
			return (-1);
		pid = wrap_fork();
		if (pid == 0) //fils
		{
			if (cmd->pipe == 1 && cmd->infile != NULL)
				ft_pipe_redir(cmd, env, fd);
			if (cmd->pipe == 1)
			{
				exec_fd_redir(fd, cmd->infile);
				ft_pipe_process(cmd, env);
			}
			else
			{
				exec_fd_redir(fd, cmd->infile);
				try_execve(cmd->av[0], cmd->av, env);
			}
			exit(EXIT_FAILURE);
		}
		else if (pid > 0) //pere
		{
			waitpid(pid, &status, WUNTRACED);
			check_for_signal(status, cmd->av[0]);
		}
		else
			ft_putendl_fd(ft_strerror(g_errno), 2);
		if (cmd->infile != NULL)
			close(fd);
	}
	else
	{
		g_errno = FT_ENOCMD;
		return (-1);
	}
	return (1);
}
