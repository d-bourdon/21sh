/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:41 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/10 13:15:46 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_env.h"
#include <stdio.h>

t_env	*ft_env_chr(t_env *list, char *str)
{
	t_env	*tmp;

	printf("CHR\n");
	tmp = list;
	while(tmp && ft_strcmp(tmp->name, str) != 0)
		tmp = tmp->next;
	printf("END\n");
	if (tmp == NULL)
	{
		printf("OK\n");
		tmp = list;
	}
printf("BACK %s\n", tmp->value);
	return (tmp);
}

void	ft_env_stock(t_env *env, char *find, char *value)
{
	t_env	*tmp;
	t_env	*ajout;
	tmp = ft_env_chr(env, find);
	printf("OK env %s \n", tmp->value);
	if (tmp->value == NULL)
		{
			printf("NULL\n");
			ajout = (t_env*)malloc(sizeof(t_env));
			printf("malloc\n");
			ajout->name = ft_strdup(find);
			printf("find %s value %s\n", find, value);
			if (value == NULL)
				ajout->value = ft_strdup(" ");
			else
				ajout->value = ft_strdup(value);
			ajout->next = NULL;
			printf("BEFORE OK\n");
			ft_env_addend(&env, ajout);
			printf("OK ?\n");
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

// char	**ft_env_alive(char **environ)
// {
// 	char **env;

// 	if (environ)
// 		return (environ);
// 	env = (char**)malloc(sizeof(char*)*4);
// 	env[0] = ft_strdup("OLDPWD= ");
// 	env[1] = ft_strdup("PWD= ");
// 	env[2] = ft_strdup("HOME= ");
// 	env[3] = ft_strdup("PWD= ");


// }
