/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 09:53:26 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 18:33:35 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

t_env	*addenviron(char const *name, char const *value)
{
	t_env			*out;

	out = (t_env*)ft_memalloc(sizeof(t_env));
	out->name = ft_strdup(name);
	out->value = ft_strdup(value);
	out->next = NULL;
	return (out);
}

int		setenv(char const *name, char const *value, int overwrite)
{
	t_info			*info;
	t_env			*env;

	info = singleton(NULL);
	env = info->env;
	while (env)
	{
		if (ft_strequ(env->name, name))
		{
			if (overwrite)
			{
				free(env->value);
				env->value = ft_strdup(value);
			}
			return (1);
		}
		env = env->next;
	}
	env = info->env;
	ft_env_addend(&env, addenviron(name, value));
	return (1);
}
