/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:53:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/03 13:21:34 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <stdlib.h>
#include <libft.h>
#include <ft_errno.h>
#include <fcntl.h>
#include <unistd.h>

char	*g_builtin_str[] = {
	"cd",
	"exit",
	"getenv",
	"setenv",
	"echo",
	"unsetenv",
	"pwd",
};

int		(*g_builtin_func[])(char **) = {
	&ft_cd,
	&sh_exit,
	&sh_getenv,
	&sh_setenv,
	&ft_echo,
	&sh_unsetenv,
	&sh_pwd,
};

int		sh_nb_builtins(void)
{
	return (sizeof(g_builtin_str) / sizeof(char *));
}

static void	close_redir(int	*fd, char *file)
{
	if (file == NULL)
		return ;
	if (file && file[0] == '<')
		dup2(fd[1], STDIN_FILENO);
	if (file && file[0] == '>')
		dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	free(fd);
}

static int	execute_builtin(t_cmd *cmd, char **env)
{
	int		i;
	int		*fd;

	i = -1;
	if (ft_strequ(cmd->av[0], "env") || ft_strequ(cmd->av[0], "export"))
		if (env != NULL)
		{
			fd = ft_redir(cmd->infile);
			i = sh_env(cmd);
			close_redir(fd, cmd->infile);
			return (i);
		}
	while (++i < sh_nb_builtins())
		if (ft_strequ(cmd->av[0], g_builtin_str[i]))
		{
			fd = ft_redir(cmd->infile);
			i = (g_builtin_func[i])(cmd->av);
			close_redir(fd, cmd->infile);
			return (i);
		}
	return (999);
}

int		sh_execute_env(t_cmd *cmd, char **env)
{
	int		i;
	char	*path;
	t_info	*info;

	info = singleton(NULL);
	if (cmd->av[0] == NULL)
		return (1);
	if ((i = execute_builtin(cmd, env)) != 999)
		return (i);
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
