/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_detect_pipe.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 13:51:43 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/10 14:53:30 by dbourdon         ###   ########.fr       */
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

	printf("av i %s\n", cmd->av[i]);
	str = ft_strjoin(" ", cmd->av[i]);
	if (cmd->routefd != NULL)
		cmd->routefd = ft_strjoinfree(cmd->routefd, str, 3);
	else
		cmd->routefd = str;
	printf("cmd->routefd %s\n", cmd->routefd);
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
			tmp->av = ft_replace_env(tmp->av, &i);
			i++;
		}
		printf("out cmd->routefd %s\n", tmp->routefd);
		//ft_tabtab_frag(tmp->av);
		tmp = tmp->next;
	}
}
