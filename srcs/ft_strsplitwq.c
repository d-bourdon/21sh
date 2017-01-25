/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplitwq.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:39:02 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/25 19:44:29 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdio.h>

static char	*ft_strncpyq(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < len && src[i])
	{
		if (src[i] != '\"' && src[i] != '\'')
		{
			dst[j++] = src[i];
		}
		i++;
	}
	while (i < len)
	{
		dst[j] = '\0';
		i++;
		j++;
	}
	return (dst);
}

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
			i++;
			while (str[i] && str[i] != str[quote])
			{
				i++;
			}
			if (str[i] != str[quote])
				quote = -1;
		}
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
		out++;
	}
	return((quote != -1)? out : -1);
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
		len++;
		while (str[len] && str[len] != str[tmp])
			len++;
	}
	while (str[len] && ft_isspace(str[len]) == 0)
		len++;
	out = (char*)ft_memalloc(sizeof(char) * len + 1);
	out = ft_strncpyq(out, str, (size_t)len);
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
	if ((nb = nb_word(str)) == -1)
		return (NULL);
	if ((out = (char**)ft_memalloc(sizeof(char*) * nb + 1)) == NULL)
		return (NULL);
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		out[j++] = dupword(&str[i]);
		out[j] = NULL;
		if (str[i] == '\"' || str[i] == '\'')
		{
			tmp = i;
			i++;
			while (str[i] && str[i] != str[tmp])
				i++;
		}
		while (str[i] && ft_isspace(str[i]) == 0)
			i++;
	}
	return (out);
}
