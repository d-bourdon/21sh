/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 14:58:25 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 15:10:22 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

t_dlist			*ft_dlstnew(void const *content, size_t content_size)
{
	t_dlist	*new;

	new = (t_dlist *)ft_memalloc(sizeof(t_dlist));
	if (content && content_size)
	{
		new->content = (void *)ft_memalloc(content_size);
		new->content_size = content_size;
		ft_memcpy(new->content, content, content_size);
	}
	return (new);
}
