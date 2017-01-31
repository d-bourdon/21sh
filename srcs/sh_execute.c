/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:53:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 12:56:41 by dbourdon         ###   ########.fr       */
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

int		sh_execute_env(t_cmd *cmd, char **env)
{
	int		i;
	char	*path;
	t_info	*info;

	info = singleton(NULL);
	if (cmd->av[0] == NULL)
		return (1);
	i = 0;
	while (i < sh_nb_builtins())
	{
		if (ft_strequ(cmd->av[0], g_builtin_str[i]))
			return ((g_builtin_func[i])(cmd->av));
		i++;
	}
	cmd = ft_hash_check(info, cmd);
	if (!ft_strchr(cmd->av[0], '/') && (path = which(cmd->av[0])))
	{
		free(cmd->av[0]);
		cmd->av[0] = path;
		return (sh_launch_env(cmd, env));
	}
	else if (ft_strchr(cmd->av[0], '/'))
		return (sh_launch_env(cmd, env));
	g_errno = FT_ENOCMD;
	return (-1);
}

int		sh_execute(t_cmd *cmd)
{
	t_info	*info;
	char	**env;
	int		ret;

	info = singleton(NULL);
	env = ft_env_to_char(info->env);
	ret = sh_execute_env(cmd, env);
	ft_tabtab_free(env);
	return (ret);
}
