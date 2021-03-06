/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:42:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/02/10 15:13:16 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAXSIGNALS		31
# define SH_NAME		"minishell"
# define MSH_END		42
# define L_HASH			3000

# include <unistd.h>
#include <stdio.h>

typedef struct		s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_hash
{
	char			*cmd;
	char			*path;
	struct s_hash	*next;
}					t_hash;

typedef struct		s_cmd
{
	char			**av;
	int				*ipipe;
	int				*opipe;
	int				pipe;
	char			*routefd;
	char			r_prio;
	char			*infile;
	struct s_cmd	*next;
}					t_cmd;

typedef	struct		s_info
{
	char			*workdir;
	t_hash			**hash;
	t_cmd			*cmd;
	t_env			*env;
	int				l_win;
	int				h_win;
	int				*fd_b;
}					t_info;

typedef	struct s_pos	t_pos;
struct					s_pos
{
	int x;
	int y;
};

typedef	struct s_c	t_c;
struct				s_c
{
	char	c;
	int		cursor_on;
	t_pos	pos;
	t_c		*prev;
	t_c		*next;
};

void			add_to_history(char *line);
void			load_history(void);
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
int				print_prompt();
void			print_error(char *str);
char			*fetch_paths(unsigned int index);

void			free_split(char **av);

void			printenv();
int				setenv(char const *name, char const *value, int overwrite);
int				sh_unsetenv(char **av);
int				sh_getenv(char **av);
int				sh_launch_env(t_cmd *cmd, char **env);
int				sh_execute_env(t_cmd *cmd, char **env);
int				sh_execute(t_cmd *cmd);
int				cd(char **av);
void			pwd();
int				sh_exit(char **av);
int				sh_env(t_cmd *cmd);
int				sh_echo(char **av);
int				sh_pwd(char **av);

int				nb_args(char **av);
char			*ft_getenv(char *s);
int				is_dir(char *path);

int				check_for_signal(int status, char *cmd);

/*
** setenv.c :
*/
int				setenv(char const *name, char const *value, int overwrite);
int				sh_setenv(char **av);
t_env			*addenviron(char const *name, char const *value);

/*
** line_parse.c strsplitwq :
*/
t_cmd			*ft_line_parse(char *str);
void			ft_line_exploit(char *str, int start, int i, t_cmd **out);
char			**ft_strsplitwq(char *str);
char			**ft_replace_env(char **str, int *i);

/*
** ft_echo.c ft_echo2.c :
*/
int				ft_echo(char **av);
void			ft_putends(char const *s);
int				ft_otod(int octal);

/*
** ft_cd.c  ft_cd2.c :
*/
int				ft_cd(char **argv);
int				ft_cd_home(t_env *env);
int				ft_cd_option(char **argv, t_env *env);
int				ft_cd_error(char *str, int mode);
void			ft_cd_set_pwd(char *path, t_env *env);
int				ft_cd_lien(char *path, t_env *env);
int				ft_cd_spe(char *path, t_env *env);

/*
** ft_clear_path.c :
*/
char			*ft_clear_path(char *str, int mode);
char			*ft_clear_path_free(char *s, int m);

/*
** ft_tabtab.c :
*/
int				ft_tabtab_len(char **tab);
char			**ft_tabtab_frag(char **tab);
void			ft_tabtab_ifree(char ***tab, int i_free);
char			**ft_tabtab_icpy(char **origin, int i_cpy);
void			ft_tabtab_free(char **tab);

/*
** line_detect_pipe.c :
*/
void			ft_line_pipe(t_cmd *cmd, int i);
void			ft_line_redir(t_cmd *cmd, int i);
void			ft_free_cmd(t_cmd *cmd);
void			ft_line_detect_pipe(t_cmd *cmd);
void			ft_line_fdredir(t_cmd *cmd, int i);
char			*ft_strjoinfree(char *s1, char *s2, int mode);

/*
** hash :
*/
void			ft_hash_add(char *name, char *value);
t_hash			**ft_hash_init(void);
t_cmd			*ft_hash_check(t_info *info, t_cmd *cmd);
int				ft_hash_calc(char *str);
int				*ft_hash_eratho(int size);

/*
** ft_env.c :
*/
t_env			*ft_env_chr(t_env *list, char *str);
void			ft_env_stock(t_env *env, char *find, char *value);
void			ft_env_addend(t_env **liste, t_env *ajout);
char			**ft_env_to_char(t_env *env);

/*
** ft_init_info.c
*/
t_info			*ft_init_info(char **environ);
t_env			*ft_init_env(char **environ);
void			*singleton(void *data);
char			*ft_strdupfree(char *s1);
void	ft_reset_fd(void);

/*
** ft_erreur.c
*/
int				ft_erreur(char *str, int mode);

/*
** ft_pipe_close.c :
*/
void	ft_pipe_process(t_cmd *cmd,char **env);
t_cmd	*ft_next_to_pipe(t_cmd *cmd);
int		ft_open_redir(char *file);
void	exec_fd_redir(int fd, char *infile);
int		*ft_redir(char *file);
void	ft_pipe_redir(t_cmd *cmd,char **env, int fd);
void	ft_def_routefd(char	*str);

#endif
