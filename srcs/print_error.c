/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:25:37 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/04 10:25:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <ft_errno.h>

void	print_error(char *s)
{
	ft_putstr_fd("minishell: ", 2);
	ft_perror(s);
}