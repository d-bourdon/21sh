/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 11:40:55 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/03 13:19:05 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <ft_errno.h>
#include <fcntl.h>

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

int		*ft_redir(char *file)
{
	int		*fd;

	if (file == NULL)
		return (NULL);
	fd = (int*)ft_memalloc(sizeof(int) * 2);
	if (file[0] == '<')
		fd[1] = dup(STDIN_FILENO);
	if (file[0] == '>')
		fd[1] = dup(STDOUT_FILENO);
	fd[0] = ft_open_redir(file);
	exec_fd_redir(fd[0], file);
	return (fd);
}

int		ft_open_redir(char *file)
{
	int		fd;

	fd = 0;
	if (file[0] == '>' && file[1] == '>')
		fd = open(file + 2, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (file[0] == '>')
		fd = open(file + 1, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	else if (file[0] == '<' && file[1] == '<')
		fd = 0;
	else if (file[0] == '<')
		fd = open(file + 1, O_RDONLY, 0644);
	if (fd == -1)
		g_errno = FT_ENOENT;
	return (fd);
}

void	exec_fd_redir(int fd, char *infile)
{
	if (infile == NULL)
		return ;
	if (infile[0] == '<')
		dup2(fd, STDIN_FILENO);
	else if (infile[0] == '>')
		dup2(fd, STDOUT_FILENO);
}