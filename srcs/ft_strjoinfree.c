/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/27 13:51:11 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/31 18:00:42 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>

char	*ft_strjoinfree(char *s1, char *s2, int mode)
{
	char	*tmp;

	tmp = ft_strjoin(s1, s2);
	if (mode == 1 && s1)
		free(s1);
	else if (mode == 2 && s2)
		free(s2);
	else if (mode > 2 && s1 && s2)
	{
		free(s1);
		free(s2);
	}
	return (tmp);
}