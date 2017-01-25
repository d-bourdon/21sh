/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:33:37 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/07 10:17:13 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

char			*dup_path(char *const *envp)
{
	while (*envp != 0)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			return (ft_strdup(*envp + 5));
		envp += 1;
	}
	return (NULL);
}

char			*fetch_paths(unsigned int index)
{
	char			**paths;
	char			*path_raw;
	static char		*path = NULL;

	if (path != NULL)
		ft_strdel(&path);
	path_raw = dup_path(g_environ);
	if (path_raw)
	{
		paths = ft_strsplit(path_raw, ':');
		if (paths != NULL)
		{
			if (index < (unsigned int)nb_args(paths))
				path = ft_strdup(paths[index]);
			free_split(paths);
		}
		free(path_raw);
	}
	return (path);
}
