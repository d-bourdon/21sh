/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:33:48 by paim              #+#    #+#             */
/*   Updated: 2016/08/05 13:34:54 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcatchar(char *dst, const char src)
{
	int i;

	i = 0;
	while (dst[i] != '\0')
		i++;
	dst[i] = src;
	dst[i + 1] = '\0';
	return (dst);
}

char	*ft_strcat(char *dst, const char *src)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (dst[i] != '\0')
		i++;
	while (src[j] != '\0')
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (dst);
}
