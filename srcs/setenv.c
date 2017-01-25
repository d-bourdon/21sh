/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 09:53:26 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 11:28:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

static char		*getenvvalue(char const *name, char const *value)
{
	char	*val;

	val = ft_strjoin(name, "=");
	val = ft_stradd(val, (char *)value);
	return (val);
}

char			**addenviron(char *env[], char const *name, char const *value)
{
	char			**environ;
	unsigned int	i;

	environ = (char **)ft_memalloc(sizeof(char *) * (nb_args(env) + 2));
	i = 0;
	while (env[i] != 0)
	{
		environ[i] = ft_strdup(env[i]);
		i += 1;
	}
	environ[i] = getenvvalue(name, value);
	return (environ);
}

int				setenv(char const *name, char const *value, int overwrite)
{
	unsigned int	i;
	char			**up_env;

	i = 0;
	while (g_environ[i] != 0)
	{
		if (ft_strncmp(g_environ[i], name, ft_strlen(name)) == 0)
		{
			if (overwrite)
			{
				free(g_environ[i]);
				g_environ[i] = getenvvalue(name, value);
				return (1);
			}
			else
				return (1);
		}
		i += 1;
	}
	up_env = addenviron(g_environ, name, value);
	free_split(g_environ);
	g_environ = up_env;
	return (1);
}
