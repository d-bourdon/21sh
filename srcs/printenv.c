/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/28 11:27:50 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/28 13:50:26 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <minishell.h>

void			printenv(void)
{
	unsigned int	i;

	i = 0;
	while (g_environ[i] != 0)
	{
		ft_putendl(g_environ[i]);
		i += 1;
	}
}
