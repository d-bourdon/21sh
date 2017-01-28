/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:41 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/28 15:59:38 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

t_env	*ft_env_chr(t_env *list, char *str)
{
	t_env	*tmp;

	tmp = list;
	while (tmp && ft_strcmp(tmp->name, str) != 0)
		tmp = tmp->next;
	if (tmp == NULL)
		tmp = list;
	return (tmp);
}

void	ft_env_stock(t_env *env, char *find, char *value)
{
	t_env	*tmp;
	t_env	*ajout;
	tmp = ft_env_chr(env, find);
	if (tmp->value == NULL)
		{
			ajout = (t_env*)ft_memalloc(sizeof(t_env));
			ajout->name = ft_strdup(find);
			if (value == NULL)
				ajout->value = ft_strdup(" ");
			else
				ajout->value = ft_strdup(value);
			ajout->next = NULL;
			ft_env_addend(&env, ajout);
			return ; 
		}
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
