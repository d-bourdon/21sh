/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigusr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:44:35 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/22 11:44:46 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigusr1(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": user defined signal 1", 2);
}

void			sigusr2(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": user defined signal 2", 2);
}
