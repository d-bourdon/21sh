/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:51:03 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/05 19:03:17 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"


int		ft_cd_lien(char *path, t_env *env)
{
	t_info *info;
	char	tmp[500];

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

// int main(void)
// {
// 	t_env *env;
// 	t_env *tmp2;
// 	char tmp[500];
// 	char **argv;

// 	tmp2 = (t_env*)malloc(sizeof(t_env));
// 	tmp2->name = strdup("PWD");
// 	tmp2->value = strdup("/Users/dbourdon/21sh/");
// 	tmp2->next = NULL;
// 	ft_env_addend(&(env), tmp2);	
// 	tmp2 = (t_env*)malloc(sizeof(t_env));
// 	tmp2->name = strdup("OLDPWD");
// 	tmp2->value = strdup("/Users/dbourdon/21sh/");
// 	tmp2->next = NULL;
// 	ft_env_addend(&(env), tmp2);
// 	tmp2 = (t_env*)malloc(sizeof(t_env));
// 	tmp2->name = strdup("HOME");
// 	tmp2->value = strdup("/Users/dbourdon/");
// 	tmp2->next = NULL;
// 	ft_env_addend(&(env), tmp2);
// 	argv = (char**)malloc(sizeof(char*)*3);
// 	argv[0] = strdup("cd");
// 	argv[1] = strdup("/tmp/");
// 	argv[2] = NULL;
// 	getcwd(tmp, 500);
// 	printf("DEBUT CD %s\n", tmp);
// 	ft_cd(argv, env);
// 	printf("\n Fin : %s\n", ft_env_chr(env, "PWD")->value);
// }
