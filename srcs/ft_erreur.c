/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_erreur.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/28 12:56:28 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/28 15:51:18 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <colors.h>

int		ft_erreur(char *str, int mode)
{
	if (mode == 0)
	{
		ft_putstr(LRED "Erreur Shell : ");
		ft_putstr(str);
		ft_putendl(CRES);
	}
	return (1);
}