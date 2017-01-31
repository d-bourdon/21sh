/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 13:08:29 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 15:51:48 by dbourdon         ###   ########.fr       */
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

int		sh_env(t_cmd *cmd)
{
	int				ac;
	char			**av;
	unsigned int	i;
	int				options;

	options = get_options(&ac, cmd->av);
	if (options == 1)
	{
		cmd->av[0][0] = '\0';
		cmd->av[1][0] = '\0';
		cmd->av = ft_tabtab_frag(cmd->av);
		sh_execute_env(cmd, NULL);
	}
	else
	{
		av = cmd->av;
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
