/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:41 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/08 15:52:09 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <stdio.h>

t_env	*ft_env_chr(t_env *list, char *str)
{
	t_env	*tmp;

	tmp = list;
	while(tmp && ft_strcmp(tmp->name, str) != 0)
		tmp = tmp->next;
	return (tmp);
}

void	ft_env_stock(t_env *env, char *find, char *value)
{
	t_env	*tmp;

	tmp = ft_env_chr(env, find);
	if (tmp == NULL)
		return ;
	free(tmp->value);
	tmp->value = ft_strdup(value);
	return ;
}

void	ft_env_addend(t_env **liste, t_env *ajout)
{
	t_env	*tmp;

	tmp = *liste;
	if (*liste == NULL)
	{
		*liste = ajout;
		return ;
	}
	else
	{
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (ajout != NULL)
			tmp->next = ajout;
	}
}
