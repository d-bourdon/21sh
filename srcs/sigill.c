/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigill.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:33:00 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:36:16 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigill(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": illegal hardware instruction", 2);
}
