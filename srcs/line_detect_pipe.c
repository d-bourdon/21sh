/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_detect_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:51:43 by dbourdon          #+#    #+#             */
/*   Updated: 2017/01/31 17:53:58 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <stdlib.h>
#include <stdio.h> //norme

void	ft_line_pipe(t_cmd *cmd, int i)
{
	int		j;
	char	**cmd2;
	t_cmd	*ajout;

	j = 0;
	cmd2 = ft_tabtab_icpy(cmd->av, i + 1);
	ft_tabtab_ifree(&cmd->av, i);
	ajout = (t_cmd*)ft_memalloc(sizeof(t_cmd));
	ajout->av = cmd2;
	ajout->ipipe = NULL;
	ajout->opipe = NULL;
	ajout->pipe = 0;
	ajout->infile = NULL;
	ajout->routefd = NULL;
	ajout->next = cmd->next;
	cmd->next = ajout;
	cmd->pipe = 1;
	cmd->opipe = ajout->ipipe;
}

void	ft_line_fdredir(t_cmd *cmd, int i)
{
	char	*str;
	char	tmp[3];

	tmp[0] = ';';
	tmp[1] = cmd->r_prio + 48;
	tmp[2] = '|';
	str = ft_strjoin(tmp, cmd->av[i]);
	cmd->routefd = ft_strjoinfree(cmd->routefd, str, 3);
	cmd->av[i][0] = '\0';
	cmd->av = ft_tabtab_frag(cmd->av);
}

void	ft_line_redir(t_cmd *cmd, int i)
{
	cmd->r_prio = 1;
	cmd->infile = ft_strjoin(cmd->av[i], cmd->av[i + 1]);
	cmd->av[i][0] = '\0';
	cmd->av[i + 1][0] = '\0';
	cmd->av = ft_tabtab_frag(cmd->av);
}

void	ft_free_cmd(t_cmd *cmd)
{
	t_cmd	*tmp;
	while (cmd)
	{
		ft_tabtab_free(cmd->av);
		free(cmd->routefd);
		free(cmd->infile);
		tmp = cmd->next;
		free(cmd);
		cmd = tmp;
	}
	cmd = NULL;
}

void	ft_line_detect_pipe(t_cmd *cmd)
{
	t_cmd	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		tmp->r_prio = 0;
		while (tmp->av[i])
		{
			if (ft_strequ(tmp->av[i], "|"))
				ft_line_pipe(tmp, i);
			else if (ft_strstr(tmp->av[i], "<&") || ft_strstr(tmp->av[i], ">&"))
				ft_line_fdredir(tmp, i--);
			else if (ft_strequ(tmp->av[i], "<") || ft_strequ(tmp->av[i], ">") ||
			 ft_strequ(tmp->av[i], ">>") || ft_strequ(tmp->av[i], "<<"))
				ft_line_redir(tmp, i--);
			i++;
		}
		tmp = tmp->next;
	}
}
