/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   21sh.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/05 17:03:23 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/05 18:37:12 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_H
# define SH_H

# include "libft.h"
# include "ft_env.h"
# include "ft_cd.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <signal.h>

typedef	struct s_info
{
	char		*workdir;
	t_env		*env;
}				t_info;

/*
** main.c :
*/
void	*singleton(void *data);

/*
** ft_init.c :
*/
void	ft_freetabtab(char **tab);
t_env	*ft_init_env(char **environ);
t_info	*ft_init_info(char **environ);

#endif
