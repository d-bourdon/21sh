/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/09 14:57:46 by dbourdon          #+#    #+#             */
/*   Updated: 2017/02/10 15:16:43 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>
#include <libft.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/wait.h>
#include <ft_errno.h>
#include <fcntl.h>
#include <stdlib.h>

static int	route_verif_exec(int *fd)
{
	int		ret;

	ret = fcntl(fd[2], F_GETFL);
	if (fd[1] == 1 && ret != -1) //<
	{
		if (ret & O_RDONLY || ret & O_RDWR)
			dup2(fd[2], fd[0]);
		else
			return (0);
	}
	else if (fd[1] == 2 && ret != -1) //>
	{
		if (ret & O_WRONLY || ret & O_RDWR)
			dup2(fd[2], fd[0]);
		else
			return (0);
	}
	else
		return (0);
	return (1);
}

static int	*route_detect(char *str)
{
	int		i;
	int		*tab;

	i = 0;
	tab = (int*)ft_memalloc(sizeof(int) * 3);
	if (str[i] == '<' || str[i] == '>')
		tab[0] = (tab[i] == '<')? 0 : 1 ;
	else
		tab[0] = ft_atoi(str);
	while (str[i] && str[i] != '&')
		i++;
	tab[1] = (str[i - 1] == '<')? 1: 2;
	if (str[i + 1])
	{
		if (str[i + 1] == '-')
			tab[2] = -1;
		else
			tab[2] = ft_atoi(str + i);
		return (tab);
	}
	free(tab);
	return (NULL);
}

void	ft_def_routefd(char	*str)
{
	char	**tab;
	int		i;
	int		*fd;
	int		ret;

	if (!str)
		return ;
	i = 0;
	ret = 0;
	tab = ft_strsplit(str, ' ');
	while (tab && tab[i])
	{
		if ((fd = route_detect(tab[i])) != NULL)
		{
			if (fd[2] == -1)
				close(fd[0]);
			else
				ret = route_verif_exec(fd);
		}
		if (ret == 0)
		{
			free(fd);
			ft_tabtab_free(tab);
			g_errno = FT_ENOSYN;
			return ;
		}
		free(fd);
		i++;
	}
	ft_tabtab_free(tab);
}

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

void	ft_pipe_redir(t_cmd *cmd,char **env, int fd)
{
	pid_t	child;
	int		tmp;
	int		tmp2;
	int		tmp3;

	tmp = dup(fd);
	tmp2 = dup(STDOUT_FILENO);
	tmp3 = dup(STDIN_FILENO);
	exec_fd_redir(fd, cmd->infile);
	child = fork();
	if (child == -1)
		printf("Errorn\n"); //norme
	else if (child == 0)
	{
		dup2(fd, STDOUT_FILENO);
		try_execve(cmd->av[0], cmd->av, env);
		return ;
	}
	wait(NULL);
	close(fd);
	dup2(tmp3, STDIN_FILENO);
	dup2(tmp2, STDOUT_FILENO);
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
		fd = open(file + 2, O_RDWR | O_CREAT | O_APPEND, 0644);
	else if (file[0] == '>')
		fd = open(file + 1, O_RDWR | O_CREAT | O_TRUNC, 0644);
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