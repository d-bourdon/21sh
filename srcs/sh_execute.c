/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:53:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/26 13:47:06 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_errno.h>

char	*g_builtin_str[] = {
	"cd",
	"exit",
	"getenv",
	"env",
	"setenv",
	"echo",
	"unsetenv",
	"pwd",
	"export",
};

int		(*g_builtin_func[])(char **) = {
	&cd,
	&sh_exit,
	&sh_getenv,
	&sh_env,
	&sh_setenv,
	&ft_echo,
	&sh_unsetenv,
	&sh_pwd,
	&sh_env
};

int		sh_nb_builtins(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}

int		sh_execute_env(char **av, char **env)
{
	int		i;
	char	*path;

	if (av[0] == NULL)
		return (1);
	i = 0;
	while (i < sh_nb_builtins())
	{
		if (ft_strcmp(av[0], g_builtin_str[i]) == 0)
			return ((g_builtin_func[i])(av));
		i += 1;
	}
	if (!ft_strchr(av[0], '/') && (path = which(av[0])))
	{
		free(av[0]);
		av[0] = path;
		return (sh_launch_env(av, env));
	}
	else if (ft_strchr(av[0], '/'))
		return (sh_launch_env(av, env));
	g_errno = FT_ENOCMD;
	return (-1);
}

int		sh_execute(char **av)
{
	return (sh_execute_env(av, g_environ));
}
