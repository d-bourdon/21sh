/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/25 13:19:30 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/25 15:29:23 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int		ft_otod(int octal)
{
	int decimal;
	int i;

	i = 0;
	decimal = 0;
	while (octal != 0)
	{
		decimal = decimal + (octal % 10) * ft_pow(8, i++);
		octal = octal / 10;
	}
	return (decimal);
}

void	ft_putends(char const *s)
{
	char	*str;

	if (!s)
		return ;
	str = (char *)s;
	ft_putstr(str);
	ft_putchar(' ');
}
