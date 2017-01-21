/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:00:50 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/21 15:59:43 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_detect_builtin(t_cmd *cmd, t_info *info)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		tmp = ft_hash_check(info, tmp);
		printf("Av[0] %s\n", tmp->av[0]);
		ft_hash_add("cd", "/bin/lol", ft_hash_calc(tmp->av[0]), info->hash);
		tmp = ft_hash_check(info, tmp);
		printf("Av[0] %s\n", tmp->av[0]);
		//printf("hash = %d\n", ft_hash_calc(tmp->av[0]));
		if (ft_strequ(tmp->av[0], "exit"))
		{
			printf("\nexit !!!\n");
			tputs(tgetstr("ei", NULL), 1, my_outc);
			tcsetattr(0, TCSADRAIN, &(info->b_term));
			exit(0);
		}
		else if (ft_strequ(tmp->av[0], "cd"))
		{
			printf("cd %s - |%s|\n", tmp->av[0], tmp->av[1]);
			ft_cd(tmp->av, info->env);
		}
		tmp = tmp->next;
	}
	return (1);
}