/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   which.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 15:44:53 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/10 09:46:43 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <minishell.h>

static char			*get_path(char *cmd)
{
	unsigned int	i;
	DIR				*dir_p;
	struct dirent	*dir;
	char			*cmd_path;

	i = 0;
	while (fetch_paths(i) != NULL)
	{
		if ((dir_p = opendir(fetch_paths(i))))
		{
			while ((dir = readdir(dir_p)) != NULL)
			{
				if (cmd != NULL && ft_strcmp(cmd, dir->d_name) == 0)
				{
					cmd_path = ft_strjoin(fetch_paths(i), "/");
					cmd_path = ft_stradd(cmd_path, dir->d_name);
					closedir(dir_p);
					return (cmd_path);
				}
			}
			closedir(dir_p);
		}
		i += 1;
	}
	return (NULL);
}

char				*which(char *cmd)
{
	char		*path;

	path = NULL;
	path = get_path(cmd);
	return (path);
}
