/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_prompt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/21 14:04:20 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/31 13:17:35 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <colors.h>
#include <unistd.h>

int				print_prompt(void)
{
//	char	dir[256];
//	char	*basename;

//	getcwd(dir, 255);
//	basename = ft_strrchr(dir, '/');
//	if (basename == NULL)
//		basename = dir;
//	else if (ft_strcmp(basename, "/"))
//		basename += 1;
	ft_putstr(BOLDNRM);
//	ft_putstr(basename);
	ft_putstr("$" CRES CGRE "> " CRES);
	// TODO : Compute prompt size
	return (3);
}
