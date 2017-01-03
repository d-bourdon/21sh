/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/26 13:54:13 by paim              #+#    #+#             */
/*   Updated: 2015/12/23 11:06:43 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char	*dest;
	size_t	i;

	if (!(dest = (char*)malloc(sizeof(char) * len)))
		return (NULL);
	i = 0;
	while (i < len)
	{
		dest[i] = ((char*)src)[i];
		i++;
	}
	i = 0;
	while (i < len)
	{
		((char *)dst)[i] = dest[i];
		++i;
	}
	return (dst);
}
