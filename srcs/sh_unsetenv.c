/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:57:30 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 16:48:44 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_errno.h>
#include <minishell.h>
#include <stdlib.h>

static void		free_env(t_env *env)
{
	free(env->name);
	free(env->value);
	free(env);
}

int				sh_unsetenv(char **av)
{
	t_info	*info;
	t_env	*env;
	t_env	*tmp;

	info = singleton(NULL);
	env = info->env;
	if (env && ft_strequ(env->name, av[1]))
	{
		tmp = env->next;
		free_env(env);
		info->env = tmp;
		return (1);
	}
	while (env && env->next && !ft_strequ(env->next->name, av[1]))
		env = env->next;
	if (env && env->next)
	{
		tmp = env->next->next;
		free_env(env->next);
		env->next = tmp;
	}
	return (1);
}
