/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:16:19 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/09 16:27:35 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <termcap.h>

int				main(void)
{
	int			status;
	extern char	**environ;

	singleton(ft_init_info(environ));
	if (tgetent(NULL, ft_getenv("TERM")) == -1)
	{
		ft_putendl("TERM environement variable not set.");
		return (0);
	}
	status = minishell();
	return (status);
}
