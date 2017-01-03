/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_revers.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/20 16:33:12 by dbourdon          #+#    #+#             */
/*   Updated: 2016/12/28 18:23:35 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

char	*ft_revers(char *in)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	if (!in)
		return (NULL);
	j = ft_strlen(in) - 1;
	out = (char*)malloc(sizeof(char) * j + 1);
	while (j > -1)
	{
		out[i] = in[j];
		i++;
		j--;
	}
	return (out);
}

char	*ft_reversfree(char *in)
{
	int		i;
	int		j;
	char	*out;

	i = 0;
	if (!in)
		return (NULL);
	j = ft_strlen(in) - 1;
	out = (char*)malloc(sizeof(char) * j + 1);
	while (j > -1)
	{
		out[i] = in[j];
		i++;
		j--;
	}
	free(in);
	return (out);
}
