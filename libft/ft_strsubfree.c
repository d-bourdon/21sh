/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsubfree.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/21 16:47:17 by dbourdon          #+#    #+#             */
/*   Updated: 2016/08/18 12:43:13 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsubfree(char *s, unsigned int start, size_t len)
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
	free(s);
	return (str);
}
