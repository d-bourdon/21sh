/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 17:07:39 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 18:23:28 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_pow(int nb, int pow)
{
	if (pow < 0)
		return (1 / ft_pow(nb, -pow));
	else if (pow == 0)
		return (1);
	else
		return (nb * ft_pow(nb, pow - 1));
}
