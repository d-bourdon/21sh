/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:00:50 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/19 15:16:50 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_detect_builtin(t_cmd *cmd, t_info *info)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (ft_strcmp(tmp->av[0], "exit") == 0)
		{
			printf("\nexit !!!\n");
			tputs(tgetstr("ei", NULL), 1, my_outc);
			tcsetattr(0, TCSADRAIN, &(info->b_term));
			exit(0);
		}
		else if (ft_strcmp(tmp->av[0], "cd") == 0)
		{
			printf("cd %s - |%s|\n", tmp->av[0], tmp->av[1]);
			ft_cd(tmp->av, info->env);
		}
		printf("-> so %s == %s | ft_strcmp -> %d\n",tmp->av[0], "cd", ft_strcmp(tmp->av[0], "cd"));
		tmp = tmp->next;
	}
	return (1);
}