/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 10:25:05 by paim              #+#    #+#             */
/*   Updated: 2015/12/08 17:21:22 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dest;
	char	*srce;
	int		i;
	int		p;

	p = (int)n;
	dest = (char*)dst;
	srce = (char*)src;
	i = 0;
	while (i < p)
	{
		dest[i] = srce[i];
		i++;
	}
	return (dest);
}
