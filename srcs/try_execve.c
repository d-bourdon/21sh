/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_execve.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 10:26:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <ft_errno.h>

int			try_execve(char *cmd, char **av, char **envp)
{
	int	status;

	status = 0;
	if ((status = wrap_execve(cmd, av, envp)) == -1)
		print_error(ft_strerror(g_errno));
	return (status);
}
