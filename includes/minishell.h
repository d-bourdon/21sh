/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyagci <oyagci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:42:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/25 16:53:19 by oyagci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAXSIGNALS		31
# define SH_NAME		"minishell"
# define MSH_END		42

# include <unistd.h>

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

int				check_for_signal(int status, char *cmd);

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

/*
** ft_clear_path.c :

** char			*ft_clear_path(char *str, int mode)
** char			*ft_clear_path_free(char *s, int m)
*/

#endif