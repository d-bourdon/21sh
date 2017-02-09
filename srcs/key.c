/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:23:01 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/09 17:35:37 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <key.h>
#include <termcap.h>

int				key_is_up(const char *const buffer)
{
	char *const	arrow = tgetstr("up", NULL);

	for (int i = 0; arrow[i]; i++)
		ft_putnbr(arrow[i]);
	if (ft_memcmp(up, buffer, ft_strlen(arrow)) == 0)
		return (1);
	return (0);
}

int				key_is_down(const char *const buffer)
{
	(void)buffer;
}

int				key_is_right(const char *const buffer)
{
	(void)buffer;
}

int				key_is_enter(const char *const buffer)
{
	(void)buffer;
}

int				key_is_delete(const char *const buffer)
{
	(void)buffer;
}

int				key_is_ctrl_d(const char *const buffer)
{
	(void)buffer;
}

int				key_is_ctrl_c(const char *const buffer)
{
	(void)buffer;
}
