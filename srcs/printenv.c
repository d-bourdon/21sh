/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:27:50 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 16:31:07 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

void	printenv(void)
{
	t_info	*info;
	t_env	*env;

	info = singleton(NULL);
	env = info->env;
	while (env)
	{
		ft_putstr(env->name);
		ft_putstr("=");
		ft_putendl(env->value);
		env = env->next;
	}
}
