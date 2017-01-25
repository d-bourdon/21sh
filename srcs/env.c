/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:08:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 11:30:29 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>

int		get_options(int *ac, char **av)
{
	int	options;
	int	opt;

	*ac = nb_args(av);
	options = 0;
	while ((opt = ft_getopt(*ac, av, "i")) > 0)
	{
		if (opt == 'i')
			options = 1;
	}
	g_optreset = 1;
	return (options);
}

void	env_set(char **av)
{
	char	*sign;
	char	*name;
	char	*val;

	sign = ft_strchr(av[0], '=');
	if (sign)
	{
		name = ft_strnew(sign - *av);
		ft_strncpy(name, *av, sign - *av);
		val = ft_strdup(sign + 1);
		setenv(name, val, 1);
		free(name);
		free(val);
	}
	else
	{
		name = ft_strdup(av[0]);
		setenv(name, "", 1);
		free(name);
	}
}

int		sh_env(char **av)
{
	int				ac;
	unsigned int	i;
	int				options;

	options = get_options(&ac, av);
	if (options == 1)
		sh_execute_env(av + 2, NULL);
	else
	{
		av += g_optind;
		ac -= g_optind;
		i = 0;
		if (ac == 0)
			printenv();
		else if (ac == 1)
			env_set(av);
	}
	return (1);
}
