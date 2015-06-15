/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_p.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/27 13:48:06 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 16:18:00 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_P_H
# define FT_P_H

# include <unistd.h>
# include <stdlib.h>
# include <libc.h>

# include <fcntl.h>
# include <netdb.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/socket.h>
# include <arpa/inet.h>

# define TRAM_SIZE 8

typedef struct hostent		t_hostent;
typedef struct protoent		t_protoent;
typedef struct sockaddr		t_sockaddr;
typedef struct sockaddr_in	t_sockaddr_in;

int		ft_send(unsigned char *data, unsigned int size);
int		ft_recv(unsigned char **data, unsigned int *total);
int		ft_error(char *str);
int		confirm_exec(int *r, char *error, int if_put);
int		request_exec(char *cmd, unsigned char *input);
int		exec_notfound(char *cmd, char *input, char *opt);
int		exec_quit(char *cmd, char *input, char *opt);
int		c_exec_cmd(char *cmd, char *input, char *opt);
int		c_exec_get(char *cmd, char *input, char *opt);
int		c_exec_put(char *cmd, char *input, char *opt);
int		s_exec_cmd(unsigned char *cmd, unsigned char *arg, int r);
int		s_exec_get(unsigned char *cmd, unsigned char *arg, int r);
int		s_exec_put(unsigned char *cmd, unsigned char *arg, int r);
int		s_ls(char *arg);
char	*resolve_path(char *path, t_bool *restricted);

#endif
