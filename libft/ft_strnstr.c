/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/25 11:55:25 by paim              #+#    #+#             */
/*   Updated: 2015/12/09 17:29:36 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	int i;

	if (!*s1 && !*s2)
		return ((char *)s1);
	while (*s1 != '\0' && n > 0)
	{
		i = 0;
		while ((n > 0) && s1[i] && s1[i] == s2[i])
		{
			i += 1;
			n -= 1;
		}
		if (!s2[i])
			return ((char *)s1);
		if (s2[i] == '\0')
			return ((char *)s1);
		n += i;
		n--;
		s1++;
	}
	return (NULL);
}
