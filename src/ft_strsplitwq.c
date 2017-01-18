/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/18 12:39:11 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/18 16:28:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	nb_word(char *str)
{
	int		i;
	int		quote;
	int		out;

	i = 0;
	out = 0;
	quote = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = i;
			while (str[i] && str[i] != str[quote])
				i++;
			if (str[i] != str[quote])
				quote = 0;
		}
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
		out++;
	}
	return((quote == 0)? out : -1);
}

static char	*dupword(char *str)
{
	char	*out;
	int		len;
	int		tmp;

	len = 0;
	if (!str[len])
		return (NULL);
	if (str[len] == '\"' || str[len] == '\'')
	{
		tmp = len;
		while (str[len] && str[len] != strtmp)
			len++;
	}
	while (str[len] && ft_isspace(str[len]) == 0)
		len++;
	out = (char*)ft_memalloc(sizeof(char) * len);
	out = ft_strncpy(out, str, (size_t)len);
	return (out);
}

char		**ft_strsplitwq(char *str)
{
	char	**out;
	int		nb;
	int		i;
	int		j;
	int		tmp;

	i = 0;
	j = 0;
	tmp = 0;
	if ((nb = nb_word(str)) == -1);
		return (NULL);
	if ((out = (char**)ft_memalloc(sizeof(char*) * nb)) == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		out[j++;] = dupword(&str[i]);
		if (str[i] == '\"' || str[i] == '\'')
		{
			tmp = i;
			while (str[i] && str[i] != str[tmp])
				i++;
		}
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
	}
	return (out);
}
