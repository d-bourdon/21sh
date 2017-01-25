/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:53:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/07 10:29:58 by oyagci           ###   ########.fr       */
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
	&sh_echo,
	&sh_unsetenv,
	&sh_pwd,
	&sh_env
};

int		sh_nb_builtins(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}

int		from_root(char *s)
{
	if (s[0] == '/')
		return (1);
	return (0);
}

int		is_d_dd_slash(char *s)
{
	if ((ft_strncmp(s, "./", 2) == 0
				|| ft_strncmp(s, "../", 3) == 0))
		return (1);
	return (0);
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
	if ((!is_d_dd_slash(av[0]) || !from_root(av[0])) && (path = which(av[0])))
	{
		free(av[0]);
		av[0] = path;
		return (sh_launch_env(av, env));
	}
	if ((is_d_dd_slash(av[0]) || from_root(av[0])) && !(path = which(av[0])))
	{
		free(path);
		return (sh_launch_env(av, env));
	}
	g_errno = FT_ENOCMD;
	return (-1);
}

int		sh_execute(char **av)
{
	return (sh_execute_env(av, g_environ));
}
