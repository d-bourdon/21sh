/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 17:31:01 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/03 17:41:56 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENV_H
# define ENV_H

# include "libft.h"

struct	s_env
{
	char	*name;
	char	*value;
	t_env	*next;
}		t_env;

t_env	*ft_env_chr(t_env *list, char *str);
void	ft_env_stock(t_env *env, char *find, char *value)

#endif