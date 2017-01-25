/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_launch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:43 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/25 15:26:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <minishell.h>
#include <signal.h>
#include <stdlib.h>
#include <libft.h>

int		sh_launch_env(char **av, char **env)
{
	pid_t	pid;
	pid_t	wpid;
	int		status;

	pid = wrap_fork();
	if (pid == 0)
	{
		try_execve(av[0], av, env);
		exit(EXIT_FAILURE);
	}
	else if (pid > 0)
	{
		wpid = waitpid(pid, &status, WUNTRACED);
		check_for_signal(status, av[0]);
	}
	else
		ft_putendl_fd("[ERROR] Could not fork.", 2);
	return (1);
}

int		sh_launch(char **av)
{
	int status;

	status = sh_launch_env(av, g_environ);
	return (status);
}
