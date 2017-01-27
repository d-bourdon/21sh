/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 16:37:00 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/27 16:57:38 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

t_cmd	*ft_line_parse(char *str)
{
	t_cmd	*out;
	int		i;
	int		start;
	int		quote;

	start = 0;
	i = 0;
	out = NULL;
	while (str[i - ((i < 1)? 0 : 1)])
	{
		if (str[i] == '\"' || str[i] == '\'')
		{
			quote = i++;
			while (str[i] && str[i] != str[quote])
				i++;
			if (!str[i])
				return (out);
		}
		if (str[i] == ';' || !str[i])
		{
			if (start != i)
				ft_line_exploit(str, start, i, &out);
			start = i + 1;
		}
		i++;
	}
	return (out);
}

void	ft_line_exploit(char *str, int start, int i, t_cmd **out)
{
	t_cmd	*list;
	t_cmd	*ok;
	char	*tmp;
	char	**tb;

	if ((tmp = (char*)ft_memalloc(sizeof(char) * (i - start) + 1)) == NULL)
		return ;
	tmp = ft_strncpy(tmp, &str[start], i - start);
	tb = ft_strsplitwq(tmp);
	free(tmp);
	if ((ok = (t_cmd*)ft_memalloc(sizeof(t_cmd))) == NULL)
		return ;
	ok->av = tb;
	ok->ipipe = NULL;
	ok->opipe = NULL;
	ok->next = NULL;
	if (*out == NULL)
		*out = ok;
	else

	{
		list = *out;
		while (list && list->next)
			list  = list->next;
		list->next = ok;
	}
}
