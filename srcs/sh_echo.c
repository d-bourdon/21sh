/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 14:33:37 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 14:43:44 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int				sh_echo(char **av)
{
	int ac;
	int	endl;

	endl = 1;
	ac = nb_args(av);
	if (ac > 1 && ft_strcmp("-n", av[1]) == 0)
	{
		endl = 0;
		av++;
		ac--;
	}
	av++;
	while (*av != 0)
	{
		ft_putstr(*av);
		*(av + 1) != 0 ? ft_putchar(' ') : (void)0;
		av++;
	}
	endl ? ft_putchar('\n') : (void)0;
	return (1);
}
