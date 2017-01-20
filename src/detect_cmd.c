/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detect_cmd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 13:00:50 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/20 18:46:44 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "21sh.h"

int		ft_detect_builtin(t_cmd *cmd, t_info *info)
{
	t_cmd	*tmp;

	tmp = cmd;
	while (tmp)
	{
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