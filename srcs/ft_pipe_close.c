/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:40:55 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/01 14:53:29 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>

void	ft_pipe_process(t_cmd *cmd,char **env)
{
	int		pdes[2];
	pid_t	child;

	pipe(pdes);
	child = fork();
	if ((int)child == -1)
		printf("Errorn\n");
	else if ((int)child == 0)
	{
		dup2(pdes[1], STDOUT_FILENO);
		close(pdes[0]);
		try_execve(cmd->av[0], cmd->av, env);
	}
	dup2(pdes[0], STDIN_FILENO);
	close(pdes[1]);
	wait(NULL);
	sh_execute(cmd->next);
	return ;
}

t_cmd	*ft_next_to_pipe(t_cmd *cmd)
{
	while (cmd && cmd->pipe)
		cmd = cmd->next;
	cmd = cmd->next;
	return (cmd);
}