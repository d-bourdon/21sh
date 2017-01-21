/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:45:48 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/21 15:00:16 by dbourdon         ###   ########.fr       */
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
	char		*str;
	int			i;
	extern char	**environ;
	t_info		*info;
	//void		*hash; 
//	t_cmd		*tmp;

	i = 0;
	signal(SIGINT, sighandler);
	printf("before ft_init_info\n");
	info = ft_init_info(environ);
	printf("before singleton\n");
	singleton(info);
	ft_affichage_help();
	printf("Before ft_line_start\n");
	if (ft_line_start(info) == -1)
		return (1);
//	printf("OK before ft_line_get\n");
	//test = ft_line_get(0);
	//printf("\n%s\n", test);
	//exit(10);
	while (42)
	{
		ft_putstr("\n\033[1;34m");
		ft_putstr(info->workdir);
		ft_putstr("\n\033[1;32m$\033[33m--> \033[00m");
		str = ft_line_get(0);
		info->cmd = ft_line_parse(str);
		if (info->cmd == NULL)
			printf("NULLLLLLLLLLLLLLLLL\n");
		printf("cmd before builtin: %s\n", info->cmd->av[0]);
		ft_detect_builtin(info->cmd, info);
		// while (info->cmd)
		// {
		// 	fr_free_tabtab(info->cmd->av);
		// 	tmp = info->cmd->next;
		// 	free (info->cmd);
		// 	info->cmd = tmp;
		// }
	}
	return (1);
} 
