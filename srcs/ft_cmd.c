/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 16:49:11 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/28 20:04:10 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

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

int		ft_cmd_exec(t_cmd *cmd) 
{
	t_info	*info;
	char	*path
	int		i;

	i = 0;
	info = singleton(NULL);
	if (cmd->av[0] == NULL)
		return (1);
	while (i < sizeof(g_builtin_str) / sizeof(char *))
	{
		if (ft_strequ(cmd->av[0], g_builtin_str[i]))
			return ((g_builtin_func[i])(av));
		i++;
	}
	cmd = ft_hash_check(info, cmd);
	if (!ft_strchr(cmd->av[0], '/') && (path = which(cmd->av[0]))) // si ya pas de path donc pas dans la table de hash
	{
		free(cmd->av[0]);
		cmd->av[0] = path;
		return (sh_launch_env(cmd, ft_env_to_char(info->env)));
	}
	else if (ft_strchr(cmd->av[0], '/'))
		return (sh_launch_env(cmd, ft_env_to_char(info->env)));
	g_errno = FT_ENOCMD;
	return (-1);
}