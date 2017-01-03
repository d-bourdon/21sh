/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 15:51:38 by paim              #+#    #+#             */
/*   Updated: 2015/11/30 01:41:31 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *src, size_t n)
{
	int i;
	int j;
	int b;

	b = (int)n;
	j = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (b != 0)
	{
		while (j < b)
		{
			dst[i + j] = src[j];
			j++;
		}
		b--;
	}
	dst[i + j] = '\0';
	return (dst);
}
