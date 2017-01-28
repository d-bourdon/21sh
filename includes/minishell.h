/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbourdon <dbourdon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/20 09:42:13 by oyagci            #+#    #+#             */
/*   Updated: 2017/01/28 17:17:29 by dbourdon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define MAXSIGNALS		31
# define SH_NAME		"minishell"
# define MSH_END		42
# define L_HASH			3000

# include <unistd.h>

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
}					t_info;

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

int				ft_cd(char **argv);
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
void			ft_hash_add(char *name, char *value, int hash, t_hash **table);
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

/*
** ft_erreur.c
*/
int				ft_erreur(char *str, int mode);

#endif
