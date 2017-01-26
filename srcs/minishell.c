/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 13:24:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/26 14:32:30 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <ft_errno.h>
#include <termcap.h>

void	sigint_parent(int signal)
{
	ft_putchar('\n');
	(void)signal;
}

int		minishell(void)
{
	char	*line;
	char	**av;
	int		status;

	line = NULL;
	status = 1;
	while (status)
	{
		signal(SIGINT, sigint_parent);
		print_prompt();
		ft_get_command_line(&line);
		if (line != NULL)
		{
			av = parse_args(line);
			if ((status = sh_execute(av)) == -1)
				print_error(ft_strerror(g_errno));
			free(line);
			free_split(av);
			av = NULL;
		}
	}
	line ? free(line) : (void)0;
	free_split(av);
	return (1);
}
