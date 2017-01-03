/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 00:36:14 by paim              #+#    #+#             */
/*   Updated: 2015/11/30 07:37:13 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*n;

	n = (char *)malloc(sizeof(char) * size);
	if (n == NULL)
		return (NULL);
	while (size > 0)
		n[(size--) - 1] = 0;
	return (n);
}
