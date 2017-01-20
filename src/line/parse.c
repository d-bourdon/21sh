/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:59:04 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/20 13:35:19 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

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
 			quote = i;
 			i++;
 			while (str[i] && str[i] != str[quote])
 				i++;
 			if (!str[i])
 				return (out);
 		}
 		if (str[i] == ';' || !str[i])
 		{
 			if (start != i)
 			{
 				printf("Line exploit = %s, %d, %d\n", str, start, i);
 				ft_line_exploit(str, start, i, &out);
 				printf("	out : %s\n", out->av[0]);
 			}
 			start = i + 1;
 		}
 		i++;
 	}
		printf("cmd before quit parse: %s\n", out->av[0]);
 	return (out);
}

void	ft_line_exploit(char *str, int start, int i, t_cmd **out)
{
	int 	j;
	t_cmd	*list;
	t_cmd	*ok;
	char	*tmp;
	char	**tb;

	j = 0;
	if ((tmp = (char*)ft_memalloc(sizeof(char) * (i - start) + 1)) == NULL)
		return ;
	tmp = ft_strncpy(tmp, &str[start], i - start);
	tb = ft_strsplitwq(tmp);
	free(tmp);
	if ((ok = (t_cmd*)ft_memalloc(sizeof(t_cmd))) == NULL)
		return ;
	printf("EXPLOIT !!!!!%s\n", tb[0]);
	ok->av = tb;
	ok->ipipe = NULL;
	ok->opipe = NULL;
	ok->next = NULL;
	if (*out == NULL)
		*out = ok;
	else
	{
		list = *out;
		while (list->next)
			list  = list->next;
		list->next = ok;
	}
}