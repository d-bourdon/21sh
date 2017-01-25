/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/21 16:50:45 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/25 14:16:57 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

static int	hexa_echo(char *str, int i)
{
	char	nbr[3];
	int		nb;
	char	c;

	nb = 0;
	if (!str[i] || !str[i + 1] || !str[i + 2])
		return (0);
	if (ft_isdigit(str[i]) && ft_isdigit(str[i + 1]) && ft_isdigit(str[i + 2]))
	{
		nbr[0] = str[i];
		nbr[1] = str[i + 1];
		nbr[2] = str[i + 2];
		nb = ft_atoi(nbr);
		nb = ft_otod(nb);
		c = (char)nb;
		write(1, &c, 1);
		return (-1);
	}
	return (0);
}

static int	print_opt(char *str, int i)
{
	i++;
	if (str[i] == 'a')
		write(1, "\a", 1);
	else if (str[i] == 'b')
		write(1, "\b", 1);
	else if (str[i] == 'c')
		return (-1);
	else if (str[i] == 'f')
		write(1, "\f", 1);
	else if (str[i] == 'n')
		write(1, "\n", 1);
	else if (str[i] == 'r')
		write(1, "\r", 1);
	else if (str[i] == 't')
		write(1, "\t", 1);
	else if (str[i] == 'v')
		write(1, "\v", 1);
	else if (str[i] == '\\')
		write(1, "\\", 1);
	else if ((i = hexa_echo(str, i)) == 0)
		return (0);
	return ((i == -1) ? 4 : 2);
}

static int	affiche_opt(char *str, int opt)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '\\')
		{
			if ((j = print_opt(str, i)) != 0)
			{
				if (j == -1)
					return (-1);
				i = i + j;
			}
			else
				write(1, &str[i], 1);
		}
		i++;
	}
	return (0);
}

int			ft_echo(char **av)
{
	int		option;
	int		i;

	option = 0;
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
	i = (option != 0) ? 2 : 1;
	while (av[i])
		if (affiche_opt(av[i], option) == -1)
			return (1);
	if (option != 1 || option != 3)
		ft_putchar('\n');
	return (1);
}
