/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/16 14:16:10 by dbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 12:44:28 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count1(char const *s, int i, int tmp)
{
	while (s[i] != '\0')
	{
		while (ft_isspace(s[i]))
			i++;
		if (s[i] == '\0')
			return (tmp);
		if (!ft_isspace(s[i]))
		{
			while (!ft_isspace(s[i]) && s[i] != '\0')
				i++;
			tmp++;
		}
	}
	return (tmp);
}

static char	**ft_count2(const char *s, int tmp2, char **tab)
{
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	while (s[i2] != '\0')
	{
		while (ft_isspace(s[i2]))
			i2++;
		if (!ft_isspace(s[i2]))
		{
			i = 0;
			while (!ft_isspace(s[i2]) && s[i2] != '\0')
			{
				i++;
				i2++;
			}
			if ((tab[tmp2] = (char*)malloc(sizeof(char) * (i + 1))) == NULL)
				return (NULL);
			tmp2++;
		}
	}
	return (tab);
}

static char	**ft_treat(char **tab, int i2, char *s)
{
	int		tmp2;
	int		i;

	i = 0;
	tmp2 = 0;
	while (s[i2] != '\0')
	{
		while (ft_isspace(s[i2]))
			i2++;
		if (!ft_isspace(s[i2]) && s[i2] != '\0')
		{
			i = 0;
			while (!ft_isspace(s[i2]) && s[i2] != '\0')
			{
				tab[tmp2][i] = s[i2];
				i++;
				i2++;
			}
			tab[tmp2][i] = '\0';
			tmp2++;
		}
	}
	tab[tmp2] = NULL;
	return (tab);
}

static char	**ft_exeption(char **tab, int p, char const *s)
{
	int		v;

	v = 0;
	if ((tab = (char**)malloc(sizeof(char*) + 1)) == NULL)
		return (NULL);
	if ((tab[0] = (char*)malloc(sizeof(char) * p)) == NULL)
		return (NULL);
	p = 0;
	while (ft_isspace(s[p]))
		p++;
	while (s[p] != '\0' && !ft_isspace(s[p]))
	{
		tab[0][v] = s[p];
		p++;
		v++;
	}
	tab[0][p] = '\0';
	tab[1] = NULL;
	return (tab);
}

char		**ft_strsplitw(char const *s)
{
	char	**tab;
	int		v;
	int		p;

	v = 0;
	p = 0;
	tab = NULL;
	if (!s)
		return (NULL);
	if (ft_count1(s, 0, 0) == 1)
	{
		while (ft_isspace(s[v]))
			v++;
		while (s[v] != '\0' && !ft_isspace(s[v]))
		{
			v++;
			p++;
		}
		return (ft_exeption(tab, p, s));
	}
	if ((tab = (char**)malloc(sizeof(char*) *
					(ft_count1(s, 0, 0) + 1))) == NULL)
		return (NULL);
	tab = ft_count2(s, 0, tab);
	return (ft_treat(tab, 0, (char *)s));
}
