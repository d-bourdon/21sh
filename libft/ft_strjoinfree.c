/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 14:14:06 by dbourdon          #+#    #+#             */
/*   Updated: 2016/06/17 14:09:55 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1 && s1)
		free(s1);
	else if (mode == 2 && s2)
		free(s2);
	else if (mode != 1 && mode != 2 && s1 && s2)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}
