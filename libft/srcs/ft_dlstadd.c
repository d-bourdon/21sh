/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 15:13:42 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 16:15:56 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void			ft_dlstadd(t_dlist **alst, t_dlist *new)
{
	if (*alst)
	{
		new->next = *alst;
		(*alst)->prev = new;
		*alst = (*alst)->prev;
	}
	else
	{
		*alst = new;
	}
}
