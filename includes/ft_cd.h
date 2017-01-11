/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:58:05 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/11 11:01:50 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CD_H
# define FT_CD_H

# include "libft.h"
# include "ft_env.h"
# include "21sh.h"

/*
** ft_cd.c :
*/
int		ft_cd(char **argv, t_env *env);
int		ft_cd_home(t_env *env);
int		ft_cd_option(char **argv, t_env *env);
int		ft_cd_error(char *str, int mode);
void	ft_cd_set_pwd(char *path, t_env *env);

/*
** ft_cd2.c :
*/
int		ft_cd_lien(char *path, t_env *env);
int		ft_cd_spe(char *path, t_env *env);
/*
** ft_clear_path.c :
*/

char	*ft_clear_path(char *str, int mode);
char	*ft_clear_path_free(char *s, int m);

#endif
