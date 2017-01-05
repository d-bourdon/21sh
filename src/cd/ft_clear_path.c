/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clear_path.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 16:31:49 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/05 18:38:53 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

static void	stfreetabtab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

static char	*stock_clear(char **clear, int mode)
{
	char	*out;
	int		i;

	i = 0;
	if (mode > 1)
		mode = 1;
	if (mode < 0)
		mode = 0;
	out = ft_strnew(1 + mode);
	if (mode == 1)
		out[0] = '/';
	while (clear[i])
	{
		if (ft_strcmp(clear[i], "/") != 0)
		{
			out = ft_strjoinfree(out, clear[i], 1);
			out = ft_strjoinfree(out, "/", 1);
		}
		i++;
	}
	if (ft_strlen(out) > 1)
		out[ft_strlen(out) - 1] = '\0';
	stfreetabtab(clear);
	return (out);
}

char		*ft_clear_path(char *str, int mode)
{
	char	**clear;
	int		i;

	i = 0;
	clear = ft_strsplit(str, '/');
	while (i > -1 && clear[i])
	{
		if (ft_strcmp(clear[i], ".") == 0)
		{
			free(clear[i]);
			clear[i] = ft_strdup("/");
		}
		else if (ft_strcmp(clear[i], "..") == 0)
		{
			free(clear[i]);
			clear[i] = ft_strdup("/");
			while (i > 0 && clear[i] && ft_strcmp(clear[i], "/") == 0)
				i--;
			free(clear[i]);
			clear[i] = ft_strdup("/");
		}
		i++;
	}
	return (stock_clear(clear, mode));
}

char		*ft_clear_path_free(char *s, int m)
{
	char *out;

	out = ft_clear_path(s, m);
	free(s);
	return (out);
}
