/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sh_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 14:54:47 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/03 14:56:10 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

int	sh_pwd(char **av)
{
	(void)av;
	ft_putendl(ft_getenv("PWD"));
	return (1);
}