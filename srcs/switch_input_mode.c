/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   switch_input_mode.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 11:41:03 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/08 11:49:36 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <termios.h>
#include <termcap.h>

int		switch_input_mode(void)
{
	struct termios			tattr;
	static struct termios	tattr_save;
	static int				saved = 0;
	static int				state = 0;

	if (saved == 0)
	{
		tcgetattr(STDIN_FILENO, &tattr_save);
		saved = 1;
	}
	if (state == 0)
	{
		tcgetattr(STDIN_FILENO, &tattr);
		tattr.c_lflag &= ~(ECHO | ICANON);
		tattr.c_cc[VTIME] = 0;
		tattr.c_cc[VMIN] = 1;
		tcsetattr(STDIN_FILENO, 0, &tattr);
	}
	else
		tcsetattr(STDIN_FILENO, 0, &tattr_save);
	return (0);
}
