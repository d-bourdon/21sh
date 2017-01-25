/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigfpe.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:34:52 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:36:03 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigfpe(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": floating point exception", 2);
}
