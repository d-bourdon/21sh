/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:49:13 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/19 14:54:20 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

/*
** A besoin d'une struct t_info qui comporte un char *workdir (initialisé
** au début du shell avec un getcwd) et definie en singletone
** et d'une liste chainé t_env avec l'env.
*/

int		ft_cd(char **argv, t_env *env)
{
	printf("ARGV %s - %s\n", argv[0], argv[1]);
	if (ft_env_chr(env, "PWD") == NULL)
		ft_env_stock(env, "PWD", " ");
	if (argv[0] && !argv[1])
		return (ft_cd_home(env));
	if (strcmp(argv[1], "-L") == 0 || strcmp(argv[1], "-P") == 0)
		return (ft_cd_option(argv, env));
	if (argv[0] && argv[1] && !argv[2])
	{
		if (ft_cd_spe(argv[1], env) == 1)
			return (1);
		else if (chdir(argv[1]) == -1)
			return (ft_cd_error(argv[1], 0));
		else
			ft_cd_set_pwd(argv[1], env);
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
			ft_putstr("\033[01mcd:\033[31m Chemin interdit : \033[00m");
		else
			ft_putstr("\033[01mcd:\033[31m Chemin inéxistant : \033[00m");
		ft_putstr(str);
	}
	else if (mode == 1)
	{
		ft_putstr("\033[01mcd:\033[31m");
		ft_putstr(str);
		ft_putstr("\033[00m");
	}
	else
	{
		ft_putstr("\033[31mCommande invalide\033[00m: cd [-L|-P] [\033[01mdo");
		ft_putstr("ssier\033[00m | \033[01m..\033[00m | \033[01m/\033[00m ");
		ft_putstr("| \033[01m-\033[00m | \033[01m~\033[00m |  ]");
	}
	return (0);
}

void	ft_cd_set_pwd(char *path, t_env *env)
{
	t_info	*info;

	info = singleton(NULL);
	if (path[0] == '/')
		path = ft_clear_path_free(path, 1);
	else
		path = ft_clear_path_free(ft_strjoinfree(
			ft_strjoin(info->workdir, "/"), path, 3), 1);
	free(info->workdir);
	info->workdir = ft_strdup(path);
	ft_env_stock(env, "OLDPWD", ft_env_chr(env, "PWD")->value);
	ft_env_stock(env, "PWD", path);
}
