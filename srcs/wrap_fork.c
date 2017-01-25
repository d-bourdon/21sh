/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrap_fork.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:16 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 10:26:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_errno.h>

pid_t	wrap_fork(void)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		g_errno = FT_ENOMEM;
	return (pid);
}
