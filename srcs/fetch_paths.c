/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fetch_paths.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:33:37 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/30 13:44:25 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>

char			*fetch_paths(unsigned int index)
{
	char			**paths;
	char			*path_raw;
	static char		*path = NULL;
	t_info			*info;
	t_env			*env;

	info = singleton(NULL);
	if (path != NULL)
		ft_strdel(&path);
	env = ft_env_chr(info->env, "PATH");
	path_raw = env->value;
	if (path_raw)
	{
		paths = ft_strsplit(path_raw, ':');
		if (paths != NULL)
		{
			if (index < (unsigned int)nb_args(paths))
				path = ft_strdup(paths[index]);
			free_split(paths);
		}
		//free(path_raw);
	}
	return (path);
}
