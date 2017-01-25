/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:16:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/08 15:07:20 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <termcap.h>

char	**g_environ;

char			**dup_environ(char *env[])
{
	char			**environ;
	unsigned int	i;

	environ = (char **)ft_memalloc(sizeof(char *) * (nb_args(env) + 1));
	i = 0;
	while (env[i] != 0)
	{
		environ[i] = ft_strdup(env[i]);
		i += 1;
	}
	return (environ);
}

int				main(int ac, char *av[], char *env[])
{
	int	status;

	(void)ac;
	(void)av;
	g_environ = dup_environ(env);
	if (tgetent(NULL, ft_getenv("TERM")) == -1)
	{
		ft_putendl("TERM environement variable not set.");
		return (0);
	}
	status = minishell();
	free_split(g_environ);
	return (status);
}
