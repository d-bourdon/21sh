/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigxcpu.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:42:30 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/22 11:42:47 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigxcpu(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": cpu limit exceeded", 2);
}
