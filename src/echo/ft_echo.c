/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:50:45 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/21 17:08:14 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

void	ft_putends(char const *s)
{
	char	*str;

	if (!s)
		return ;
	str = (char *)s;
	ft_putstr(str);
	ft_putchar(' ');
}

int		ft_echo(char **av, t_env *env)
{
	int		opt;
	int		i;

	opt = 0;
	if (!av[0] || !av[1])
		return (ft_echo_error(NULL, 1));
	if (av[1][0] == '-')
	{
		if (ft_strequ(av[1], "-n"))
			option = 1;
		else if (ft_strequ(av[1], "-e"))
			option = 2;
		else if (ft_strequ(av[1], "-en") || ft_strequ(av[1], "-ne"))
			option = 3;
		else
			return (ft_echo_error(NULL, 1));
	}
	if (option >= 2)
		av = parse_option(av);
	i = (option != 0)? 2: 1;
	while (av[i])
		ft_putends(av[i]);
	if (option != 1 || option != 3)
		ft_putchar('\n');
}
