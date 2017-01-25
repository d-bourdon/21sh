/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:29:55 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:05:00 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_errno.h>

int	g_errno = 0;

char	*ft_strerror(int errno)
{
	static char	*str[] = { FT_STR_EUNDEF, FT_STR_EACCES, FT_STR_ENOENT,
		FT_STR_ENOTDIR, FT_STR_ENOMEM, FT_STR_ENOCMD };

	return (str[errno]);
}

void	ft_perror(char *str)
{
	ft_putendl_fd(str, 2);
}
