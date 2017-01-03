/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paim <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 17:37:55 by paim              #+#    #+#             */
/*   Updated: 2015/12/11 17:30:52 by paim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;

	tmp = *alst;
	while (tmp->next != NULL)
	{
		(*del)(tmp->content, tmp->content_size);
		free(tmp);
		tmp = tmp->next;
	}
	(*del)(tmp->content, tmp->content_size);
	free(tmp);
	*alst = NULL;
}
