/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_unescaped_quote.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 10:08:36 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 13:47:41 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

int				is_unescaped_quote(unsigned int i, char *s)
{
	if (i > 0)
	{
		if (s[i - 1] != '\\' &&
				(ft_isspace(s[i - 1])
				|| is_quote(s[i])))
			return (1);
		else
			return (0);
	}
	return (1);
}
