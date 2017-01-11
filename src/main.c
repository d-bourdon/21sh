/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:45:48 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/11 18:31:18 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static void	ft_affichage_help(void)
{
	ft_putstr("\033[1;34m*************************************************\n"
	"*           _____  __    _____ _                *\n"
	"*          / __  \\/  |  /  ___| |               *\n"
	"*          `\' / /\'`| |  \\ `--.| |__             *\n"
	"*            / /   | |   `--. \\ \'_ \\            *\n"
	"*          ./ /____| |_ /\\__/ / | | |           *\n"
	"*          \\_____/\\___/ \\____/|_| |_|           *\n"
	"*                                               *\n"
	"*************************************************\033[00m\n\n"
	"\033[01m-------------- Commandes spécifique -------------\n"
	"-------------------------------------------------\033[00m\n"
	"v. 3.0 -                            2016 dbourdon\n");
}

static void	sighandler(int a)
{a = 0;
exit(0);}

void	*singleton(void *data)
{
	static void *singleton_data;

	if (data)
		singleton_data = data;
	return (singleton_data);
}

int		main(void)
{
	char		**str;
	int			i;
	extern char	**environ;
	t_info		*info;
	char		*test;

	signal(SIGINT, sighandler);
	printf("before ft_init_info\n");
	info = ft_init_info(environ);
	printf("before singleton\n");
	singleton(info);
	ft_affichage_help();
	printf("Before ft_line_start\n");
	if (ft_line_start(info) == -1)
		return (1);
	printf("OK before ft_line_get\n");
	test = ft_line_get(0);
	printf("after\n");
	exit(10);
	while (42)
	{
		str = (char**)malloc(sizeof(char*) * 1);
		ft_putstr("\n\033[1;34m");
		ft_putstr(info->workdir);
		ft_putstr("\n\033[1;32m$\033[33m--> \033[00m");
		i = get_next_line(0, str);
	//	if (str[0][0] != '\0' && (tmp = ft_cherche_env(str[0])) != NULL)
	//		ft_affichage_un_env(tmp);
		if (str[0][0] != '\0')
		{
			ft_cd(ft_strsplitw(str[0]), info->env);
			printf("ENV %s\n", ft_env_chr(info->env, "PWD")->value);
		}
	}
	return (1);
} 
