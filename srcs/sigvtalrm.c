/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sigvtalrm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 11:43:17 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/22 11:43:27 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <msh_signals.h>

void			sigvtalrm(int signal)
{
	(void)signal;
	ft_putendl_fd(SH_NAME ": virtual time alarm", 2);
}
