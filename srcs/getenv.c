/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 14:08:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char	*ft_getenv(char *env)
{
	char	*current;
	t_info	*info;
	t_env	*tmp;

	current = NULL;
	info = singleton(NULL);
	tmp = info->env;
	while (tmp)
	{
		if (ft_strequ(tmp->name, env))
			return (current = tmp->value);
		tmp = tmp->next;
	}
	return (NULL);
}
