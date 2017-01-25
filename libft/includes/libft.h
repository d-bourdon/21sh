/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/03 10:52:16 by oyagci            #+#    #+#             */
/*   Updated: 2016/12/09 12:43:18 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include "libft_str.h"
# include "libft_mem.h"
# include "libft_list.h"
# include "get_next_line.h"
# include "ft_getopt.h"

unsigned int		ft_abs(int nb);

int					ft_atoi(char *str);
char				*ft_itoa(int n);

void				ft_putchar(char c);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr(char *s);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl(char *s);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr(int c);
void				ft_putnbr_fd(int c, int fd);

#endif
