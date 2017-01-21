/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 12:10:36 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/21 16:24:11 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	*hash_areti(char *str, int size)
{
	int		i;
	int		j;
	int		*out;
	int		len;

	i = 2;
	len = 0;
	j = 0;
	while (i < size)
		if (!str[i++])
			len++;
	if ((out = (int*)ft_memalloc(sizeof(int) * len)) == NULL)
		return (NULL);
	i = 2;
	while (i < size)
	{
		if (!str[i])
			out[j++] = i;
		i++;
	}
	return (out);
}

t_cmd		*ft_hash_check(t_info *info, t_cmd *cmd)
{
	int		hash;
	t_hash	*tmp;

	hash = ft_hash_calc(cmd->av[0]);
	tmp = info->hash[hash];
	if (tmp == NULL)
		return (cmd);
	else if (ft_strequ(tmp->cmd, cmd->av[0]))
	{
		free(cmd->av[0]);
		cmd->av[0] = ft_strdup(tmp->path);
		return (cmd);
	}
	else
		while (tmp->next)
		{
			if (ft_strequ(tmp->next->cmd, cmd->av[0]))
			{
				free(cmd->av[0]);
				cmd->av[0] = ft_strdup(tmp->next->path);
				return (cmd);
			}
			tmp = tmp->next;
		}
	return (cmd);
}

int			ft_hash_calc(char *str)
{
	int		i;
	int		len;
	int		*prem;
	int		out;

	len = ft_strlen(str);
	i = 0;
	out = 0;
	prem = ft_hash_eratho((len * 100) / 15);
	while (i < len && prem[i])
	{
		out += (int)str[i] + prem[i];
		i++;
	}
	out = out % L_HASH;
	free(prem);
	return (out);
}

int			*ft_hash_eratho(int size)
{
	int		i;
	int		j;
	char	*str;
	int		*out;

	i = 2;
	if ((str = (char*)ft_memalloc(size + 1)) == NULL)
		return (NULL);
	while (i * i <= size)
	{
		if (!str[i])
		{
			j = i + i;
			while (j < size)
			{
				str[j] = 1;
				j += i;
			}
		}
		i++;
	}
	out = hash_areti(str, size);
	free(str);
	return (out);
}
