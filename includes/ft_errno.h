/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errno.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/22 14:21:15 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/10 12:14:04 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERRNO_H
# define FT_ERRNO_H

# define FT_EUNDEF		0
# define FT_EACCES		1
# define FT_ENOENT		2
# define FT_ENOTDIR		3
# define FT_ENOMEM		4
# define FT_ENOCMD		5
# define FT_ENOSYN		6

# define FT_STR_EUNDEF	"undefined error"
# define FT_STR_EACCES	"access denied"
# define FT_STR_ENOENT	"no such file or directory"
# define FT_STR_ENOTDIR	"not a directory"
# define FT_STR_UNKNOWN	"unknown error"
# define FT_STR_ENOMEM	"cannot allocate memory"
# define FT_STR_ENOCMD	"command not found"
# define FT_STR_ENOSYN	"erreur de syntaxe shell"

extern int	g_errno;

char	*ft_strerror(int errno);
void	ft_perror(char *str);

#endif
