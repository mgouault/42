/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 10:36:35 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 15:21:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int			g_sock;
int			g_csock;

static int	(*get_func(char *cmd))(char *, char *, char *)
{
	if (ft_strequ(cmd, "ls") || ft_strequ(cmd, "cd") || \
		ft_strequ(cmd, "pwd"))
		return (&c_exec_cmd);
	else if (ft_strequ(cmd, "quit"))
		return (&exec_quit);
	else if (ft_strequ(cmd, "get"))
		return (&c_exec_get);
	else if (ft_strequ(cmd, "put"))
		return (&c_exec_put);
	else
		return (&exec_notfound);
}

static int	process(void)
{
	int		(*func)(char *, char *, char *);
	char	**input;
	char	*buf;
	int		r;

	while (TRUE)
	{
		ft_putstr("$ > ");
		if ((r = get_next_line(0, &buf)) == -1)
			return (ft_error("gnl() error"));
		else if (r == 0)
			buf = ft_strdup("quit");
		input = ft_strsplit(buf, ' ');
		func = get_func(input[0]);
		if (func(input[0], input[1], input[2]) == -1)
			return (-1);
		ft_free_bistr(input);
		if (ft_strequ(buf, "quit"))
		{
			free(buf);
			break ;
		}
		free(buf);
	}
	return (0);
}

static int	new_sock(int port, char *addr, t_protoent *proto, t_hostent *h_e)
{
	t_sockaddr_in	s_in;

	if (!(proto = getprotobyname("tcp")))
		return (ft_error("getprotobyname() error"));
	if ((g_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (ft_error("socket() error"));
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	if (!(h_e = gethostbyname(addr)))
		return (ft_error("gethostbyname() error"));
	if (!(addr = inet_ntoa(*((struct in_addr **)h_e->h_addr_list)[0])))
		return (ft_error("inet_ntoa() error"));
	if ((s_in.sin_addr.s_addr = inet_addr(addr)) == (unsigned int)-1)
	{
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (ft_error("inet_addr() error"));
	}
	if (connect(g_sock, (const t_sockaddr *)&s_in, sizeof(s_in)) == -1)
	{
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (ft_error("connect() error"));
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 3)
		return (ft_error("Usage: ./client <machine> <port>"));
	if (new_sock(ft_atoi(av[2]), av[1], NULL, NULL) == -1)
		return (-1);
	ft_printf("Connection enabled\n");
	g_csock = g_sock;
	if (process() == -1)
	{
		ft_printf("Connection closed\n");
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (-1);
	}
	if (close(g_sock) == -1)
		return (ft_error("close() error"));
	return (0);
}
