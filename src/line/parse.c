/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 17:59:04 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/17 19:51:20 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.sh"

t_cmd	*ft_line_parse(char *str, t_info *info)
{
	t_cmd	*out;
 	int		i;
 	int		start;
 	int		quote;

 	start = 0;
 	i = 0;
 	while (str[i])
 	{
 		if (str[i] == '\"' || str[i] == '\'')
 		{
 			quote = i;
 			while (str[i] && str[i] != quote[quote])
 				i++;
 			if (!str[i])
 			{
 				ft_line_error(str, 1);
 				return (out);
 			}
 		}
 		if (str[i] == ';')
 		{
 			out = ft_line_exploit(str, start, i, out);
 			start = i + 1;
 		}
 		i++;
 	}
 	return (out);
}


void ft_line_detect(char **str, t_cmd *cmd)
{
	hjl
}

t_cmd *ft_line_exploit(char *str, int start, int i, t_cmd *out)
{
	int 	j;
	char	*tmp;
	char	**tb;

	j = 0;
	tmp = (char*)malloc(sizeof(char) * (i - start) + 1);
	tmp = ft_strncpy(tmp, str + start, i - start);
	tb = ft_strsplitwq(tmp); //strsplit sépartespacesauf dans les quotes et backquotes

}