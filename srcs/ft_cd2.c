/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:51:03 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/25 15:59:08 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>


int		ft_cd_lien(char *path, t_env *env)
{
	t_info	*info;
	char	tmp[500];

	if (ft_cd_spe(path, env) == 1)
		return (1);
	info = singleton(NULL);
	if (chdir(path) == -1)
		return (ft_cd_error(path, 0));
	free(info->workdir);
	getcwd(tmp, 500);
	info->workdir = ft_strdup(tmp);
	ft_env_stock(env, "OLDPWD", ft_env_chr(env, "PWD")->value);
	ft_env_stock(env, "PWD", info->workdir);
	return (1);
}

int		ft_cd_spe(char *path, t_env *env)
{
	char	*tmp;
	t_info	*info;

	if (ft_strcmp(path, "-") == 0)
	{
		info = singleton(NULL);
		tmp = strdup(ft_env_chr(env, "OLDPWD")->value);
		ft_env_stock(env, "OLDPWD", ft_env_chr(env, "PWD")->value);
		ft_env_stock(env, "PWD", tmp);
		free(info->workdir);
		info->workdir = ft_strdup(tmp);
		free(tmp);
		return (1);
	}
	else if (ft_strcmp(path, "~") == 0)
	{
		ft_cd_home(env);
		return (1);
	}
	else
		return (0);
}
