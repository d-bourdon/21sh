/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/04 10:26:32 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/08 15:03:30 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>

char	*ft_getenv(char *env)
{
	char	*current;
	char	**envp;

	current = NULL;
	envp = g_environ;
	while (*envp != 0)
	{
		if (ft_strncmp(*envp, env, ft_strlen(env)) == 0
				&& (*envp)[ft_strlen(env)] == '=')
		{
			current = ft_strchr(*envp, '=') + 1;
			return (current);
		}
		envp += 1;
	}
	return (NULL);
}
