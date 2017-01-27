/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 14:33:46 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/27 19:53:02 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

t_hash	**ft_hash_init(void)
{
	t_hash	**out;

	if ((out = (t_hash**)ft_memalloc(sizeof(t_hash) * L_HASH)) == NULL)
		return (NULL);
	return (out);
}

void	ft_hash_add(char *name, char *value, int hash, t_hash **table)
{
	t_hash	*ajout;
	t_hash	*tmp;

	if ((ajout = (t_hash*)ft_memalloc(sizeof(t_hash))) == NULL)
		return ;
	ajout->cmd = ft_strdup(name);
	ajout->path = ft_strdup(value);
	ajout->next = NULL;
	if (!table[hash])
		table[hash] = ajout;
	else
	{
		tmp = table[hash];
		while (tmp && tmp->next)
			tmp = tmp->next;
		tmp->next = ajout;
	}
}
