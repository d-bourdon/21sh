/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_getenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:25:49 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/10 09:39:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

int		sh_getenv(char **av)
{
	int		argc;
	int		i;
	char	*env_var;

	i = 1;
	argc = nb_args(av);
	while (i < argc)
	{
		env_var = ft_getenv(av[i]);
		if (env_var != NULL)
			ft_putendl(env_var);
		i += 1;
	}
	return (1);
}
