/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_info_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:54:52 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/10 15:30:03 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>
#include <fcntl.h>

void	ft_reset_fd(void)
{
	t_info	*info;
	info = singleton(NULL);
	printf("STATUS : %d - %d - %d\n",STDIN_FILENO, STDOUT_FILENO, STDERR_FILENO);
	//dup2(info->fd_b[0], STDIN_FILENO);
	dup2(info->fd_b[1], STDOUT_FILENO);
	dup2(info->fd_b[2], STDERR_FILENO);
}

static int	*fd_backup(void)
{
	int		*fd;

	fd = (int*)ft_memalloc(sizeof(int)* 3);
	fd[0] = dup(STDIN_FILENO);
	fd[1] = dup(STDOUT_FILENO);
	fd[2] = dup(STDERR_FILENO);
	return (fd);
}

char	*ft_strdupfree(char *s1)
{
	char	*str;

	str = ft_strdup(s1);
	free(s1);
	return (str);
}

void	*singleton(void *data)
{
	static void *singleton_data;

	if (data)
		singleton_data = data;
	return (singleton_data);
}

t_info	*ft_init_info(char **environ)
{
	t_info	*info;
	char	tmp[500];

	info = (t_info*)ft_memalloc(sizeof(t_info));
	if (getcwd(tmp, 500) == NULL)
		exit(ft_erreur("Path actuel introuvable.", 0));
	info->l_win = 0;
	info->h_win = 0;
	info->fd_b = fd_backup();
	info->workdir = ft_strdup(tmp);
	info->cmd = NULL;
	info->env = ft_init_env(environ);
	info->hash = ft_hash_init();
	return (info);
}

t_env	*ft_init_env(char **environ)
{
	int		i;
	t_env	*ajout;
	char	**tmp;
	t_env	*env;
	char	**tmp2;

	i = 0;
	tmp2 = environ;
	env = NULL;
	while (tmp2[i])
	{
		ajout = (t_env*)ft_memalloc(sizeof(t_env));
		tmp = ft_strsplit(tmp2[i], '=');
		ajout->name = ft_strdup(tmp[0]);
		ajout->value = ft_strdup(tmp[1]);
		ajout->next = NULL;
		ft_tabtab_free(tmp);
		ft_env_addend(&env, ajout);
		i++;
	}
	return (env);
}
