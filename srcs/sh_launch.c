/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/26 14:10:49 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell.h>
#include <signal.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_errno.h>

int		sh_launch_env(char **av, char **env)
{
	pid_t	pid;
	int		status;

	if (access(av[0], X_OK) >= 0)
	{
		pid = wrap_fork();
		if (pid == 0)
		{
			try_execve(av[0], av, env);
			exit(EXIT_FAILURE);
		}
		else if (pid > 0)
		{
			waitpid(pid, &status, WUNTRACED);
			check_for_signal(status, av[0]);
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

int		sh_launch(char **av)
{
	int status;

	status = sh_launch_env(av, g_environ);
	return (status);
}
