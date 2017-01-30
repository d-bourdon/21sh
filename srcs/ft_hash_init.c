/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:33:46 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/30 13:42:31 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdio.h>

t_hash	**ft_hash_init(void)
{
	t_hash	**out;

	if ((out = (t_hash**)ft_memalloc(sizeof(t_hash) * L_HASH)) == NULL)
		return (NULL);
	return (out);
}

void	ft_hash_add(char *name, char *value)
{
	t_hash	*ajout;
	t_hash	*tmp;
	t_info	*info;
	int		hash;

	hash = ft_hash_calc(name);
	info = singleton(NULL);
	if ((ajout = (t_hash*)ft_memalloc(sizeof(t_hash))) == NULL)
		return ;
	ajout->cmd = ft_strdup(name);
	ajout->path = ft_strdup(value);
	ajout->next = NULL;
	if (!info->hash[hash])
	{
		printf("On ajoute %s - %d\n", ajout->cmd, hash);
		info->hash[hash] = ajout;
	}
	else
	{
		printf("on add car ça existe\n");
		tmp = info->hash[hash];
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ajout;
	}
}
