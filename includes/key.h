/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 17:02:05 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/09 17:25:42 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

typedef	enum e_keycode t_keycode;
enum	e_keycode
{
	KEYCODE_UP,
	KEYCODE_DOWN,
	KEYCODE_RIGHT,
	KEYCODE_LEFT,
	KEYCODE_ENTER,
	KEYCODE_DELETE,
	KEYCODE_CTRL_D,
	KEYCODE_CTRL_C,
	KEYCODE_NONE
};

typedef	struct s_key	t_key;
struct					s_key
{
	t_keycode	keycode;
};

typedef	struct s_key_funcs	t_key_funcs;
struct						s_key_funcs
{
	t_keycode	keycode;
	int			(*f)(const char *const);
};

int				key_is_up(const char *const buffer);
int				key_is_down(const char *const buffer);
int				key_is_right(const char *const buffer);
int				key_is_left(const char *const buffer);
int				key_is_enter(const char *const buffer);
int				key_is_delete(const char *const buffer);
int				key_is_ctrl_d(const char *const buffer);
int				key_is_ctrl_c(const char *const buffer);

#endif