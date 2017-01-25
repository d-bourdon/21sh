/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 15:17:41 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 15:17:53 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <ft_errno.h>

int				is_dir(char *path)
{
	struct stat	st;

	if (stat(path, &st) == -1)
	{
		g_errno = FT_ENOENT;
		return (0);
	}
	else if (!(st.st_mode & S_IFDIR))
	{
		g_errno = FT_ENOTDIR;
		return (0);
	}
	return (1);
}
