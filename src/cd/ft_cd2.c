/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 12:51:03 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/04 16:31:20 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_cd.h"


int		ft_cd_lien(char *path, t_env *env)
{
	
}
int main(void)
{
	t_env *env;
	t_env *tmp2;
	char tmp[500];
	char **argv;

	tmp2 = (t_env*)malloc(sizeof(t_env));
	tmp2->name = strdup("PWD");
	tmp2->value = strdup("/Users/dbourdon/21sh/");
	tmp2->next = NULL;
	ft_env_addend(&(env), tmp2);	
	tmp2 = (t_env*)malloc(sizeof(t_env));
	tmp2->name = strdup("OLDPWD");
	tmp2->value = strdup("/Users/dbourdon/21sh/");
	tmp2->next = NULL;
	ft_env_addend(&(env), tmp2);
	tmp2 = (t_env*)malloc(sizeof(t_env));
	tmp2->name = strdup("HOME");
	tmp2->value = strdup("/Users/dbourdon/");
	tmp2->next = NULL;
	ft_env_addend(&(env), tmp2);
	argv = (char**)malloc(sizeof(char*)*3);
	argv[0] = strdup("cd");
	argv[1] = strdup("/tmp/");
	argv[2] = NULL;
	getcwd(tmp, 500);
	printf("DEBUT CD %s\n", tmp);
	ft_cd(argv, env);
	printf("\n Fin : %s\n", ft_env_chr(env, "PWD")->value);
}