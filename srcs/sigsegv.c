/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigsegv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:36:06 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:26:39 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigsegv(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": segmentation fault", 2);
}
