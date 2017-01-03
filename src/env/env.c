/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:30:41 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/03 17:41:59 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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