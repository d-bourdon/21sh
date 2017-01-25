/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 08:59:07 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/25 16:26:08 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <libft.h>
#include <sys/wait.h>
#include <minishell.h>
#include <stdlib.h>
#include <ft_errno.h>

int	subve(char const *path, char *const *av, char *const *envp)
{
	int		ret;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putendl_fd(av[0], 2);
		return (-1);
	}
	if (pid > 0)
	{
		wait(&ret);
		check_for_signal(ret, av[0]);
		return (ret);
	}
	return (wrap_execve(path, av, envp));
}
