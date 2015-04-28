/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:15:05 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/14 13:28:04 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <libft.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <signal.h>
# include <termcap.h>
# include <termios.h>
# include <sys/ioctl.h>

typedef enum
{
	FALSE = 0,
	TRUE
}	t_bool;

enum
{
	K_NONE,
	K_ENTER,
	K_ESCAPE,
	K_SPACE,
	K_DELETE,
	K_UP,
	K_DOWN,
	K_PAGE_DOWN,
	K_PAGE_UP,
	K_END,
	VALID_SEARCH
};

typedef struct termios	t_term;
typedef struct s_lst	t_lst;
typedef struct s_var	t_var;

struct		s_lst
{
	char	*name;
	t_lst	*prev;
	t_lst	*next;
	t_lst	*loop;
	short	x;
	short	y;
	short	length;
	t_bool	selected;
	t_bool	cursor_on;
};

struct		s_var
{
	int		x;
	int		y;
	int		col;
	int		lin;
	int		max_len;
	t_lst	*link;
};

void		launch_select(void);
void		build_lst(char **av);
void		delete_link(t_lst *link);
void		print_lst(void);
void		wait_for_read(void);
void		select_all(short key);
t_lst		*dynamic_search(char **search, t_lst *link);
void		exit_tools(void);
void		error_exit(char *str);
void		proper_exit(t_lst *link);
int			ret_putchar(int c);
short		get_key(char *b);
void		free_lst(t_lst *link);
t_bool		madehome_strstr(char *s1, char *s2);
int			get_fd(void);
char		*get_envterm(void);
char		*get_buf(char *buf);
t_lst		*get_lst(t_lst *link);
void		catch_sigwinch(int sig);
void		catch_sigint(int sig);
void		catch_sigtstp(int sig);
void		catch_sigcont(int sig);
void		catch_exit(int sig);

#endif
