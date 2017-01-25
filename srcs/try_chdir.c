/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   try_chdir.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:58:27 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 15:00:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <ft_errno.h>

int	try_chdir(char *path)
{
	if (chdir(path) == -1)
	{
		g_errno = FT_ENOTDIR;
		return (-1);
	}
	return (1);
}
