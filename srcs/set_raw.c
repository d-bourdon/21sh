/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_raw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 16:38:35 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/09 16:43:05 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termcap.h>
#include <termios.h>

struct termios	g_attr_save;

void			set_raw(void)
{
	struct termios	attr;

	tcgetattr(STDIN_FILENO, &attr);
	tcgetattr(STDIN_FILENO, &g_attr_save);
	attr.c_lflag &= ~(ECHO | ICANON);
	attr.c_cc[VTIME] = 0;
	attr.c_cc[VMIN] = 1;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &attr);
}

void			unset_raw(void)
{
	tcsetattr(STDIN_FILENO, TCSADRAIN, &g_attr_save);
}
