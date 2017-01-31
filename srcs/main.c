/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:16:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 17:46:11 by oyagci           ###   ########.fr       */
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

int				main(void)
{
	int			status;
	extern char	**environ;

	singleton(ft_init_info(environ));
	g_environ = dup_environ(environ);
	load_history(".42sh_history");
	if (tgetent(NULL, ft_getenv("TERM")) == -1)
	{
		ft_putendl("TERM environement variable not set.");
		return (0);
	}
	status = minishell();
	free_split(g_environ);
	return (status);
}
