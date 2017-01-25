/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:30:48 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 13:49:55 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <minishell.h>
#include <libft.h>

char	*parse_escape(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\\' && line[i + 1] == '\\')
			ft_memmove(&line[i], &line[i + 1], ft_strlen(&line[i + 1]) + 1);
		i += 1;
	}
	return (line);
}

char	*remove_quotes(char *line)
{
	unsigned int i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '"' && (i > 0 ? line[i - 1] != '\\' : 1))
			ft_memmove(&line[i], &line[i + 1], ft_strlen(&line[i + 1]) + 1);
		i += 1;
	}
	return (line);
}

char	*remove_escapes(char *line)
{
	unsigned int	i;

	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '\\' && line[i + 1] != '\\')
			ft_memmove(&line[i], &line[i + 1], ft_strlen(&line[i + 1]) + 1);
		i += 1;
	}
	return (line);
}

char	*parse_separators(char *line)
{
	unsigned int	i;
	int				in_quote;

	in_quote = 0;
	i = 0;
	while (line[i] != 0)
	{
		if (line[i] == '"' && (i > 0 ? line[i - 1] != '\\' : 1))
			in_quote = !in_quote;
		else if (ft_isspace(line[i]) && !in_quote)
			line[i] = '\n';
		i += 1;
	}
	return (line);
}

char	**parse_args(char *cmd)
{
	unsigned int	i;
	char			**av;
	char			*line;

	line = ft_strdup(cmd);
	parse_escape(line);
	parse_separators(line);
	av = ft_strsplit(line, '\n');
	i = 0;
	while (av[i] != 0)
	{
		remove_quotes(av[i]);
		remove_escapes(av[i]);
		i += 1;
	}
	free(line);
	return (av);
}
