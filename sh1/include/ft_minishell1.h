/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:50:36 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:53:22 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <libc.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <dirent.h>
# include <sys/param.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <signal.h>
# include <termcap.h>
# include <termios.h>
# include <fcntl.h>
# include <sys/ioctl.h>

enum
{
	K_NONE,
	K_TAB,
	K_ENTER,
	K_DELETE,
	K_HOME,
	K_END,
	K_UP,
	K_DOWN,
	K_LEFT,
	K_RIGHT,
	K_TILDE,
	K_CLEAR,
	K_EOF,
	K_PUTE
};

typedef struct winsize	t_win;
typedef struct termios	t_term;
typedef struct s_env	t_env;
typedef struct s_line	t_line;
typedef struct s_var	t_var;
typedef struct s_pid	t_pid;
typedef struct s_chur	t_chur;

struct		s_env
{
	char	*name;
	char	*value;
	t_env	*next;
};

struct		s_line
{
	char	*line;
	t_line	*prev;
	t_line	*next;
};

struct		s_var
{
	short	begin;
	short	end;
	short	cursor;
	short	key;
};

struct		s_pid
{
	pid_t	pid;
	char	*cmd;
	t_pid	*next;
};

struct		s_chur
{
	char	*dir;
	char	*tmp;
};

char		*do_tilde(char *b);
char		**to_down(char **line, char ***tmp, t_var *v, t_line **history);
char		**to_up(char **line, char ***tmp, t_var *v, t_line **history);
void		do_clear(t_var *v, char **line);
void		to_right(t_var *v);
void		to_left(t_var *v);
void		completion(char **line, t_var *v);
void		erase_n_print(t_var *v, char *line);
void		delete_char(char **line, t_var *v, short pos);
void		print_char(char **line, char *b, t_var *v, short pos);
void		endline(short cursor);
short		gekie(char *b);
int			getsing_emptyenv(int status);
void		catch_sigint(int sig);
void		free_pid(t_pid *pid);
void		ft_wait(pid_t pid, char *cmd);
void		ft_fg(char *name);
void		return_value(int ret, char *cmd);
t_pid		*getsing_pidpile(int pid, char *cmd, t_bool use, int search);
int			getsing_returnvalue(int value);
short		getsing_cursor(short cursor);
char		*getsing_line(char *line);
short		getsing_col(short col);
char		*infin_join(char **arg);
int			getsing_ttyfd(int ttyfd);
char		**empty_cmd(char *input);
t_line		*history_dup(t_line *history);
t_bool		ft_isdigit_str(char *str);
void		try_exit(char *str, t_bool eof);
/*
** ENV
*/
t_env		*getsing_hiddenenv(t_env *env);
t_env		*getsing_env(t_env *start);
t_env		*search_env(char *name, t_bool hidden);
t_env		*evdup(char **env);
char		**make_bistr(t_env *link);
void		add_env(char *name, char *value);
void		replace_env(char *name, char *new_value);
void		delete_env(char *name);
void		ft_env(char *cmd, char **arg);
void		ft_setenv(char *name, char *value);
void		ft_unsetenv(char *name);
void		ft_echo_var(char *name);
/*
** EXECVE
*/
void		ft_execve(char *tmp1, char **arg, t_env *link);
void		choose_exec(char **arg, t_env *link);
char		**get_binpath(void);
char		*search_binpath(char *cmd);
void		bin_notfound(char *cmd);
/*
** CD
*/
char		*dot_dot(char *path, int i, char *tmp1, char *tmp2);
char		*resolve_path(char *path);
char		*cleanpath(char *str);
char		*get_oldpwd(void);
char		*get_pwd(int ifabs);
char		*get_resolved_target(char *target, int ifabs);
char		*get_target(char *target, char *target2);
void		update_env_oldpwd(void);
void		update_env_pwd(char *target);
int			get_access(char *path);
void		absolute_cd(char *target);
int			read_cd_opt(char **target, char **target2, int opt, char **arg);
void		change_dir(char **arg);
/*
** SIGNAL
*/
void		resize(int sig);
/*
** TOOLS
*/
void		error_exit(char *str);
void		exec_cmd(char **arg);
char		**arg_split(char *arg);
char		*get_home(void);
char		*get_user(void);
char		**replace_home(char **arg, char *home);
char		*replace_home_lite(char *tmp1);
void		init_shell(void);
/*
** FREE
*/
void		free_link(t_env *link);
void		free_ev(void);
void		free_bistr(char **str);
/*
** AUX
*/
int			get_next_line(int fd, char **line);
int			ft_printf(char *format, ...);
char		*ft_bigjoin(char *format, ...);
/*
** TERMCAPS
*/
int			ret_putchar(int c);
void		fast_exit(char *str);
/*
** PARSER
*/
t_line		*update_history(t_line *history, char *line);
void		exit_term(void);
void		init_term(void);
short		prompt(void);
char		*parser(t_line *history);

#endif
