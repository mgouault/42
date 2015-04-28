/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:01:27 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/17 20:39:34 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef enum
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef struct s_list	t_list;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

/*
** INIT
*/
void		*ft_memalloc(size_t size);
void		*ft_memset(void *b, int c, size_t len);
void		ft_memdel(void **ap);
void		ft_bzero(void *s, size_t n);
/*
** STR
*/
char		**ft_strsplit(char *s, char c);
char		*ft_strdup(char *s1);
char		*ft_strjoin(char *s1, char *s2);
char		*ft_strsub(char *s, unsigned int start, size_t len);
char		*ft_strtrim(char *s);
char		*ft_strreplace(char *str, char *occ, char *replace);
/*
** INT
*/
char		*ft_itoa(int n);
int			ft_atoi(char *str);
/*
** COUNT
*/
size_t		ft_strlen(char *s);
int			ft_strcnt(char *s, char c);
/*
** CMP
*/
t_bool		ft_isalnum(int c);
t_bool		ft_isalpha(int c);
t_bool		ft_isascii(int c);
t_bool		ft_isdigit(int c);
t_bool		ft_isprint(int c);
t_bool		ft_strmatch(char *str, char *match);
t_bool		ft_strequ(char *s1, char *s2);
t_bool		ft_strnequ(char *s1, char *s2, size_t n);
int			ft_strcmp(char *s1, char *s2);
int			ft_strncmp(char *s1, char *s2, size_t n);
/*
** SEARCH
*/
char		*ft_strchr(char *s, int c);
char		*ft_strrchr(char *s, int c);
char		*ft_strstr(char *s1, char *s2);
char		*ft_strnstr(char *s1, char *s2, size_t n);
/*
** PRINT
*/
void		ft_putchar(char c);
void		ft_putchar_fd(char c, int fd);
void		ft_putendl(char *s);
void		ft_putendl_fd(char *s, int fd);
void		ft_putnbr(int n);
void		ft_putnbr_fd(int n, int fd);
void		ft_putstr(char *s);
void		ft_putstr_fd(char *s, int fd);

#endif
