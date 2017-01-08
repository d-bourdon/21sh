/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:39:42 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/08 15:52:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_freetabtab(char **tab)
{
	int		i;

	i = 0;
	while (tab && tab[i])
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	if (tab)
		free(tab);
}

t_info	*ft_init_info(char **environ)
{
	t_info	*info;
	char	tmp[500];

	info = (t_info*)malloc(sizeof(t_info));
	if (getcwd(tmp, 500) == NULL)
	{
		printf("ERROR\n"); //norme
		exit(1);
	}
	info->workdir = ft_strdup(tmp);
	info->env = ft_init_env(environ);
	return (info);
}

t_env	*ft_init_env(char **environ)
{
	int		i;
	t_env	*ajout;
	char	**tmp;
	t_env	*env;
	char	**tmp2;

	i = 0;
	tmp2 = environ;
	env = NULL;
	while (tmp2[i])
	{
		printf("Hello : %d - %s\n", i, tmp2[i]);
		ajout = (t_env*)malloc(sizeof(t_env));
		tmp = ft_strsplit(tmp2[i], '=');
		ajout->name = ft_strdupfree(ft_strjoin(tmp[0], "\0"));
		ajout->value = ft_strdupfree(ft_strjoin(tmp[1], "\0"));
		ajout->next = NULL;
		ft_freetabtab(tmp);
		ft_env_addend(&env, ajout);
		i++;
	}
	return (env);
}
