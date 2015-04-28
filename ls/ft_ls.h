/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 19:43:31 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 20:19:00 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# ifdef INC_DIRENT_H
#  include <dirent.h>
# endif

# ifdef INC_SYS_STAT_H
#  undef INC_SYS_STAT_H
#  include <sys/stat.h>
# endif

# ifdef INC_SYS_TYPES_H
#  undef INC_SYS_TYPES_H
#  include <sys/types.h>
# endif

# ifdef INC_TIME_H
#  undef INC_TIME_H
#  include <time.h>
# endif

# ifdef INC_PWD_H
#  undef INC_PWD_H
#  include <pwd.h>
# endif

# ifdef INC_GRP_H
#  undef INC_GRP_H
#  include <grp.h>
# endif

# ifdef INC_UNISTD_H
#  undef INC_UNISTD_H
#  include <unistd.h>
# endif

# ifdef INC_STDLIB_H
#  undef INC_STDLIB_H
#  include <stdlib.h>
# endif

# ifdef INC_STRING_H
#  undef INC_STRING_H
#  include <string.h>
# endif

# ifdef INC_STDIO_H
#  undef INC_STDIO_H
#  include <stdio.h>
# endif

# ifdef INC_LIBFT_H
#  undef INC_LIBFT_H
#  include "libft.h"
# endif

typedef struct stat	t_stat;

typedef struct		s_lstf
{
	char			*name;
	char			*path;
	char			*folder;
	struct stat		*st;
	struct s_lstf	*prev;
	struct s_lstf	*next;
}					t_lstf;

typedef struct		s_qlst
{
	struct s_lstf	*lst;
	struct s_qlst	*next;
}					t_qlst;

# ifdef INC_DIRENT_H
#  undef INC_DIRENT_H

t_lstf				*ft_crt_lst(DIR *op, char *path, t_lstf *begin,
	t_lstf *prev);

# endif

t_lstf				*ft_crt_avlst(int *dir, char **av, t_lstf *begin,
	t_lstf *prev);
t_lstf				*ft_sort_lst(t_lstf *begin, int is_av);
t_lstf				*ft_free_lst(t_lstf *list, int prev);
t_lstf				*ft_pre_calc(t_lstf *tmp, unsigned int *max_v);
t_qlst				*ft_qstart_create(t_lstf *tmp, t_qlst *q_start);
t_qlst				*ft_free_qlst(t_qlst *queue);
void				ft_rcsv_lst(t_lstf *input);
void				ft_error(char *str, int do_exit);
void				ft_error_ilg_opt(int error);
void				ft_strerror(char *str);
void				ft_error_fts_open(void);
void				ft_if_input(t_lstf *input, int many_folders);
void				ft_readonedir(char *path);
char				*ft_getmode(int mode);
void				ft_ns_putnbr(unsigned int n);
void				ft_print_unit(unsigned int unit, int maxunit);
void				ft_print_mkdev(int major, int minor);
void				ft_print_str(char *str, int maxstr);
void				ft_qstart_read(t_qlst *q_start);
void				ft_set_tab(int *tab, int size);
void				ft_print_lst_l_(t_lstf *tmp, unsigned int *max_v);
void				ft_printtime(t_lstf *tmp);
void				*ft_error_null(char *str);
void				ft_print_lst(t_lstf *begin);
void				ft_print_lst_l(t_lstf *begin, int file);
unsigned int		ft_nbrcnt(unsigned int n);
int					ft_notadotlink(char *name);
int					ft_d_istoshow(int if_a, char *str);
int					ft_istoshow(t_lstf *tmp);

#endif
