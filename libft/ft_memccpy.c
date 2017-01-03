/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 11:09:05 by paim              #+#    #+#             */
/*   Updated: 2015/12/08 17:22:18 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dest;
	unsigned char	*srce;
	int				i;
	int				p;

	p = (int)n;
	dest = (unsigned char*)dst;
	srce = (unsigned char*)src;
	i = 0;
	while (i < p)
	{
		dest[i] = srce[i];
		if (srce[i] == (unsigned char)c)
		{
			i += 1;
			return (dest + i);
		}
		i++;
	}
	return (NULL);
}
