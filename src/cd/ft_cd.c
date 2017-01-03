/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:49:13 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/03 18:17:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"

int		ft_cd(char **argv, t_env *env)
{
	if (argv[0] && !argv[1])
		ft_cd_home(env);
	else if (ft_strcmp(argv[1], "-L") == 0 || ft_strcmp(argv[1], "-P") == 0)
		return (ft_cd_option(argv, env));
	else if (argv[0] && argv[1] && !argv[2])
	{
		//if (ft_cd_lien(argv[1], env) == 1)
		//	return(1); //	else
		 if (chdir(argv[1]) == -1)
			ft_cd_error(argv[1], 0);
		else
			ft_cd_set_pwd(argv[1], env);
	}
	else
		ft_cd_error(argv[1], 1);
	return (1);
}

void	ft_cd_home(t_env *env)
{
	if (chdir(ft_lstchrenv(env, "HOME")->value) == -1)
		ft_putstr("\033[01mcd:\033[31m Aucun $HOME défini.\033[00m");
	else
	{
		ft_env_stock(env, "OLDPWD", ft_env_chr("PWD")->value);
		ft_env_stock(env, "PWD", ft_env_chr("HOME")->value);
	}
}

int		ft_cd_option(char **argv, t_env *env)
{
	if (ft_strcmp(argv[1], "-L") == 0)
		if (ft_cd_lien(argv[2], env) == 1)
			return (1);
	if (ft_cd_spe(argv[2]) == 1)
		return (1);
	if (chdir(argv[2]) == -1)
		ft_cd_error(argv[2], 0)
	else
		ft_cd_set_pwd(argv[1], env);
	return (1);
}