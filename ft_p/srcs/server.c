/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/21 10:36:35 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 15:35:27 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int			g_sock;
int			g_csock;
char		*g_pwd;

static int	get_func(unsigned char *data)
{
	unsigned char	**input;
	short			r;
	int				ret;

	input = ft_strsplit_uc(data, ' ');
	r = 0;
	ret = 0;
	if (ft_strequ((char *)input[0], "ls") || ft_strequ((char *)input[0], "cd")\
		|| ft_strequ((char *)input[0], "pwd"))
		r = s_exec_cmd(input[0], input[1], ret);
	else if (ft_strequ((char *)input[0], "get"))
		r = s_exec_get(input[0], input[1], ret);
	else if (ft_strequ((char *)input[0], "put"))
		r = s_exec_put(input[0], input[1], ret);
	free(input);
	return (r);
}

static int	new_client(void)
{
	unsigned char *data;

	ft_printf("Client %d connection enabled\n", g_csock);
	g_pwd = ft_strdup("/");
	while (TRUE)
	{
		if (ft_recv(&data, NULL) == -1)
			exit(EXIT_FAILURE);
		if (ft_strequ((char *)data, "quit"))
			break ;
		if (get_func(data) == -1)
			exit(EXIT_FAILURE);
		free(data);
	}
	free(data);
	ft_printf("Client %d connection closed\n", g_csock);
	if (close(g_csock) == -1)
		exit(ft_error("close() error"));
	exit(EXIT_SUCCESS);
}

static int	process(void)
{
	t_sockaddr_in	cs_in;
	unsigned int	cslen;
	pid_t			pid;

	cslen = (int)sizeof(cs_in);
	if (chdir("shared") == -1)
	{
		if (mkdir("shared", 0700) == -1)
			return (ft_error("mkdir() error"));
		else
		{
			if (chdir("shared") == -1)
				return (ft_error("chdir() error"));
		}
	}
	while (TRUE)
	{
		if ((g_csock = accept(g_sock, (t_sockaddr *)&cs_in, &cslen)) == -1)
			return (ft_error("accept() error"));
		if ((pid = fork()) == -1)
			return (ft_error("fork() error"));
		else if (pid == 0)
			new_client();
	}
	return (0);
}

static int	new_sock(int port)
{
	t_protoent		*proto;
	t_sockaddr_in	s_in;

	if (!(proto = getprotobyname("tcp")))
		return (ft_error("getprotobyname() error"));
	if ((g_sock = socket(PF_INET, SOCK_STREAM, proto->p_proto)) == -1)
		return (ft_error("socket() error"));
	s_in.sin_family = AF_INET;
	s_in.sin_port = htons(port);
	s_in.sin_addr.s_addr = htonl(INADDR_ANY);
	if (bind(g_sock, (const t_sockaddr *)&s_in, sizeof(s_in)) == -1)
	{
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (ft_error("bind() error"));
	}
	return (0);
}

int			main(int ac, char **av)
{
	if (ac != 2)
		return (ft_error("Usage: ./server <port>"));
	if (new_sock(ft_atoi(av[1])) == -1)
		return (-1);
	if (listen(g_sock, 4) == -1)
	{
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (ft_error("listen() error"));
	}
	if (process() == -1)
	{
		if (close(g_sock) == -1)
			return (ft_error("close() error"));
		return (-1);
	}
	if (close(g_sock) == -1)
		return (ft_error("close() error"));
	return (0);
}
