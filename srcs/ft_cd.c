/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:49:13 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/01 11:33:30 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <stdlib.h>
#include <colors.h>

/*
** A besoin d'une struct t_info qui comporte un char *workdir (initialisé
** au début du shell avec un getcwd) et definie en singletone
** et d'une liste chainé t_env avec l'env.
*/

int		ft_cd(char **argv)
{
	t_info	*info;

	info = singleton(NULL);
	if (ft_env_chr(info->env, "PWD") == NULL)
		ft_env_stock(info->env, "PWD", " ");
	if (argv[0] && !argv[1])
		return (ft_cd_home(info->env));
	if (ft_strcmp(argv[1], "-L") == 0 || ft_strcmp(argv[1], "-P") == 0)
		return (ft_cd_option(argv, info->env));
	if (argv[0] && argv[1] && !argv[2])
	{
		if (ft_cd_spe(argv[1], info->env) == 1)
			return (1);
		else if (chdir(argv[1]) == -1)
			return (ft_cd_error(argv[1], 0));
		else
		{
			ft_cd_set_pwd(argv[1], info->env);
		}
		return (1);
	}
	else
		return (ft_cd_error(argv[1], 2));
	return (1);
}

int		ft_cd_home(t_env *env)
{
	t_info *info;

	info = singleton(NULL);
	if (chdir(ft_env_chr(env, "HOME")->value) == -1)
		return (ft_cd_error("Aucun $HOME défini.", 1));
	free(info->workdir);
	info->workdir = ft_strdup(ft_env_chr(env, "HOME")->value);
	ft_env_stock(env, "OLDPWD", ft_env_chr(env, "PWD")->value);
	ft_env_stock(env, "PWD", info->workdir);
	return (1);
}

int		ft_cd_option(char **argv, t_env *env)
{
	if (!(argv[0] && argv[1] && argv[2] && !argv[3]))
		return (ft_cd_error(NULL, 3));
	if (ft_strcmp(argv[1], "-P") == 0)
		return (ft_cd_lien(argv[2], env));
	if (ft_cd_spe(argv[2], env) == 1)
		return (1);
	if (chdir(argv[2]) == -1)
		return (ft_cd_error(argv[2], 0));
	else
		ft_cd_set_pwd(argv[2], env);
	return (1);
}

int		ft_cd_error(char *str, int mode)
{
	if (mode == 0)
	{
		if (access(str, F_OK) == 0)
			ft_putstr(SBOL "cd >" CRED " Chemin interdit : " CRES);
		else
			ft_putstr(SBOL "cd >" CRED " Chemin inéxistant : " CRES);
		ft_putendl(str);
	}
	else if (mode == 1)
	{
		ft_putstr(SBOL "cd >" CRED);
		ft_putstr(str);
		ft_putendl(CRES);
	}
	else
	{
		ft_putstr(LRED "Commande invalide" CRES " > cd [-L|-P] [" SBOL "do");
		ft_putstr("ssier" CRES " | " SBOL ".." CRES " | " SBOL "/" CRES);
		ft_putendl(" | " SBOL "-" CRES " | " SBOL "~" CRES " |  ]");
	}
	return (1);
}

void	ft_cd_set_pwd(char *path, t_env *env)
{
	t_info	*info;

	info = singleton(NULL);
	if (path[0] == '/')
		path = ft_clear_path(path, 1);
	else
		path = ft_clear_path_free(ft_strjoinfree(
			ft_strjoin(info->workdir, "/"),path, 1), 1);
	free(info->workdir);
	info->workdir = ft_strdup(path);
	setenv("OLDPWD", ft_env_chr(env, "PWD")->value, 1);
	setenv("PWD", path, 1);
	free(path);
	singleton(info);
}
