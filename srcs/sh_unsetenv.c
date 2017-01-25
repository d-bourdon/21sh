/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:57:30 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 15:49:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_errno.h>
#include <minishell.h>

static int		isset(char *name)
{
	unsigned int	i;

	i = 0;
	while (g_environ[i] != 0)
	{
		if (ft_strncmp(name, g_environ[i], ft_strlen(name)) == 0
				&& g_environ[i][ft_strlen(name)] == '=')
			return (1);
		i += 1;
	}
	return (0);
}

int				sh_unsetenv(char **av)
{
	char			**dup;
	unsigned int	i;
	unsigned int	j;

	if (isset(av[1]))
	{
		if (!(dup = (char **)ft_memalloc(sizeof(char *) * nb_args(g_environ))))
		{
			g_errno = FT_ENOMEM;
			return (-1);
		}
		i = 0;
		j = 0;
		while (g_environ[j] != 0)
		{
			if (ft_strncmp(av[1], g_environ[j], ft_strlen(av[1])) != 0)
				dup[i++] = ft_strdup(g_environ[j++]);
			else
				j++;
		}
		free_split(g_environ);
		g_environ = dup;
	}
	return (1);
}
