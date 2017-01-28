/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabtab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 16:08:06 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/28 16:29:29 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

/*
** Because "tabtab" is GREAT
*/

int		ft_tabtab_len(char **tab)
{
	int		i;

	i = 0;
	if (!tab)
		return (0);
	while (tab[i])
		i++;
	return (i);
}

char	**ft_tabtab_frag(char **tab)
{
	int		len;
	int		i;
	char	**out;

	i = 0;
	len = 0;
	while (tab[i])
	{
		if (tab[i][0] != '\0')
			len++;
		i++;
	}
	out = (char**)ft_memalloc(sizeof(char*) * len + 1);
	i = 0;
	len = 0;
	while (tab[i])
	{
		if (tab[i][0] != '\0')
			out[len++] = ft_strdup(tab[i]);
		i++;
	}
	free_split(tab);
	out[len] = NULL;
	return (out);
}

void	ft_tabtab_free(char **tab)
{
	int		i;
	
	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

void	ft_tabtab_ifree(char ***tab, int i_free)
{
	int		i;
	int		len;

	i = i_free;
	if (!*tab)
		return ;
	len = ft_tabtab_len(*tab);
	while ((*tab)[i] && i < len)
	{
		free((*tab)[i]);
		(*tab)[i] = NULL;
		i++;
	}
}

char	**ft_tabtab_icpy(char **origin, int i_cpy)
{
	int		i;
	int		j;
	int		len;
	char	**out;

	if (!origin)
		return (NULL);
	i = i_cpy;
	j = 0;
	len = ft_tabtab_len(origin);
	out = (char**)ft_memalloc(sizeof(char*) * len);
	while (origin[i] && i < len)
	{
		out[j] = ft_strdup(origin[i]);
		i++;
		j++;
	}
	out[j] = NULL;
	return (out);
}