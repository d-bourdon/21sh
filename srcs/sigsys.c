/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigsys.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:36:31 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:37:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigsys(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": invalid system call", 2);
}
