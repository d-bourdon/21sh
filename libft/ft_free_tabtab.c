/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tabtab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/20 11:21:23 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/20 14:56:26 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fr_free_tabtab(char **tab)
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

void	fr_free_ntab(char **tab, int n)
{
	int		i;

	i = 0;
	while (tab && tab[i] && i < n )
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
}

void	fr_free_tabtabn(char **tab, int n)
{
	int		i;

	i = 0;
	while (tab && tab[i] && i < n)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}
