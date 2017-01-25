/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_execve.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 09:01:56 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/24 11:59:38 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <libft.h>
#include <ft_errno.h>

int	wrap_execve(char const *path, char *const *argv, char *const *envp)
{
	int	status;

	status = execve(path, argv, envp);
	if (status == -1)
		g_errno = FT_EACCES;
	return (status);
}
