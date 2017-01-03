/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/30 08:43:39 by paim              #+#    #+#             */
/*   Updated: 2015/12/08 18:35:30 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			n;
	char			*str;

	if (!s)
		return (NULL);
	if (ft_strlen(s) < start)
		return (NULL);
	i = 0;
	while (i != start)
		i++;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	n = 0;
	while (n != len)
	{
		str[n] = s[i];
		i++;
		n++;
	}
	str[n] = '\0';
	return (str);
}
