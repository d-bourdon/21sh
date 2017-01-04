/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:58:05 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/04 11:23:35 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include "libft.h"
# include "env.h"

/*
** ft_cd.c :
*/

int		ft_cd(char **argv, void *env);
void	ft_cd_home(t_env *env);
int		ft_cd_option(char **argv, t_env *env);
void	ft_cd_error(char *str, int mode);

#endif