/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/27 13:50:02 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 10:04:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>
#include <sys/stat.h>
#include <minishell.h>
#include <ft_errno.h>
#include <unistd.h>

int				has_access(char *path)
{
	const int acc = access(path, X_OK);

	if (acc == -1)
	{
		g_errno = FT_EACCES;
		return (0);
	}
	return (1);
}

char			*evaluate_arguments(char **av)
{
	char	*dir_op;

	if (nb_args(av) > 1)
		dir_op = ft_strdup(av[1]);
	else if (ft_getenv("HOME") == NULL || ft_strlen(ft_getenv("HOME")) == 0)
		return (ft_strdup("/"));
	else
		dir_op = ft_strdup(ft_getenv("HOME"));
	return (dir_op);
}

void			free_items(char *a, char *b)
{
	free(a);
	free(b);
}

int				cd(char *av[])
{
	char			*dir_op;
	char			*curpath;
	char			pwd[255];
	char			oldpwd[255];

	dir_op = evaluate_arguments(av);
	if (dir_op[0] == '/')
		curpath = ft_strdup(dir_op);
	else if (ft_strcmp(av[1], "-") == 0)
	{
		curpath = ft_strdup(ft_getenv("OLDPWD"));
		sh_pwd(NULL);
	}
	else
		curpath = ft_strdup(dir_op);
	getcwd(oldpwd, 255);
	if (!is_dir(curpath) || !has_access(curpath) || try_chdir(curpath) == -1)
	{
		free_items(curpath, dir_op);
		return (-1);
	}
	free_items(curpath, dir_op);
	setenv("OLDPWD", oldpwd, 1);
	setenv("PWD", getcwd(pwd, 255), 1);
	return (1);
}
