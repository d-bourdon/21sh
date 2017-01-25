/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:42:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/25 18:53:44 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAXSIGNALS		31
# define SH_NAME		"minishell"
# define MSH_END		42

# include <unistd.h>

typedef struct	s_cmd
{
	char		**av;
	int			*ipipe;
	int			*opipe;
	struct s_cmd	*next;
}				t_cmd;

extern char		**g_environ;

int				minishell(void);
unsigned int	count_arguments(char *command_line);
int				is_quote(int c);
int				is_unescaped_quote(unsigned int i, char *s);
char			**parse_args(char *line);
char			*which(char *cmd);
int				exec_cmd(char *cmd);
int				try_execve(char *cmd, char **av, char **envp);
int				try_chdir(char *path);
int				subve(char const *path, char *const *av, char *const *envp);
int				wrap_execve(const char *path, char *const *argv,
								char *const *envp);
pid_t			wrap_fork();
int				switch_input_mode(void);
void			autocomplete(char *line, char *c, size_t *cur_pos);
int				put(int c);
int				ft_get_command_line(char **command_line);

char			**parse_args(char *line);
void			print_prompt();
void			print_error(char *str);
char			*fetch_paths(unsigned int index);

void			free_split(char **av);

void			printenv();
int				setenv(char const *name, char const *value, int overwrite);
int				sh_unsetenv(char **av);
int				sh_getenv(char **av);
int				sh_launch_env(char **av, char **env);
int				sh_launch(char **av);
int				sh_execute_env(char **av, char **env);
int				sh_execute(char **av);
int				cd(char **av);
void			pwd();
int				sh_exit(char **av);
int				sh_env(char **av);
int				sh_setenv(char **av);
int				sh_echo(char **av);
int				sh_pwd(char **av);

int				nb_args(char **av);
char			*ft_getenv(char *s);
int				is_dir(char *path);

int				check_for_signal(int status);
void			sighup(int signal);
void			sigint(int signal);
void			sigquit(int signal);
void			sigill(int signal);
void			sigtrap(int signal);
void			sigabrt(int signal);
void			sigemt(int signal);
void			sigfpe(int signal);
void			sigkill(int signal);
void			sigbus(int signal);
void			sigsegv(int signal);
void			sigsys(int signal);
void			sigpipe(int signal);
void			sigalrm(int signal);
void			sigterm(int signal);
void			sigurg(int signal);
void			sigstop(int signal);
void			sigtstp(int signal);
void			sigcont(int signal);
void			sigchld(int signal);
void			sigttin(int signal);
void			sigttou(int signal);
void			sigio(int signal);
void			sigxcpu(int signal);
void			sigxfsz(int signal);
void			sigvtalrm(int signal);
void			sigprof(int signal);
void			sigwinch(int signal);
void			siginfo(int signal);
void			sigusr1(int signal);
void			sigusr2(int signal);
void			sigint_parent(int signal);

/*
** line_parse.c strsplitwq :
*/
t_cmd			*ft_line_parse(char *str);
void			ft_line_exploit(char *str, int start, int i, t_cmd **out);
char			**ft_strsplitwq(char *str);


/*
** ft_echo.c ft_echo2.c :
*/
int				ft_echo(char **av);
void			ft_putends(char const *s);
int				ft_otod(int octal);

/*
** ft_cd.c  ft_cd2.c :

int				ft_cd(char **argv, t_env *env);
int				ft_cd_home(t_env *env);
int				ft_cd_option(char **argv, t_env *env);
int				ft_cd_error(char *str, int mode);
void			ft_cd_set_pwd(char *path, t_env *env);
int				ft_cd_lien(char *path, t_env *env);
int				ft_cd_spe(char *path, t_env *env);


** ft_clear_path.c :

** char			*ft_clear_path(char *str, int mode)
** char			*ft_clear_path_free(char *s, int m)
*/

#endif
