/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/13 18:20:52 by dbourdon          #+#    #+#             */
/*   Updated: 2016/05/17 14:59:14 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_intlen(int num)
{
	long	tmp;
	int		i;

	i = 0;
	tmp = (long)num;
	if (tmp < 0)
	{
		tmp = tmp * -1;
		i++;
	}
	if (tmp == 0)
		return (1);
	while (tmp > 0)
	{
		tmp = tmp / 10;
		i++;
	}
	return (i);
}
