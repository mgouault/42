/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 17:43:56 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 16:13:26 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

static int	error_message(char *cmd, unsigned char *input, char *msg)
{
	ft_printf("ERROR: %s %s: %s\n", cmd, input, msg);
	return (0);
}

static int	available_exec(char *cmd, unsigned char *input, int fd)
{
	struct stat	st;
	char		*error;

	if (!input)
		return (error_message(cmd, (unsigned char *)"", "no target"));
	if (ft_strchr((char *)input, '/'))
		return (error_message(cmd, input, "invalid target name"));
	if (ft_strequ(cmd, "put"))
	{
		error = NULL;
		if ((fd = open((char *)input, O_RDONLY)) == -1)
			return (error_message(cmd, input, "can't access file"));
		else if (fstat(fd, &st) == -1)
			error = "fstat() error";
		else if (S_ISDIR(st.st_mode) == 1)
			error = "target is a directory";
		if (close(fd) == -1)
			return (ft_error("close() error"));
		else if (error)
			return (error_message(cmd, input, error));
	}
	return (1);
}

int			c_exec_get(char *cmd, char *input, char *opt)
{
	unsigned char	*data;
	short			r;
	int				fd;
	unsigned int	size;

	if ((r = available_exec(cmd, (unsigned char *)input, 0)) == -1)
		return (-1);
	else if (r == 0)
		return (0);
	r = request_exec(cmd, (unsigned char *)input), (void)opt;
	if (r < 1)
		return ((r == 0) ? 0 : -1);
	if ((fd = open(input, O_WRONLY | O_CREAT | O_TRUNC, 0700)) == -1)
		return (ft_error("open() error"));
	if (ft_send((unsigned char *)ft_strdup("GO"), 2) == -1)
		return (-1);
	size = 0;
	if (ft_recv(&data, &size) == -1)
		return (-1);
	if (write(fd, data, size) == -1)
		return (ft_error("write() error"));
	free(data);
	if (close(fd) == -1)
		return (ft_error("close() error"));
	return (0);
}

static int	c_exec_put_(unsigned char **data, unsigned char *input, \
	unsigned char *buf, unsigned int *size)
{
	unsigned char	*tmp;
	int				fd;
	int				r;

	if ((fd = open((char *)input, O_RDONLY)) == -1)
		return (ft_error("open() error"));
	while ((r = read(fd, buf, 1024)) > 0)
	{
		buf[r] = 0;
		tmp = *data;
		*data = ft_strjoin_uc(*data, buf, *size, r);
		*size += r;
		free(tmp);
	}
	if (r == -1)
		return (ft_error("read() error"));
	if (close(fd) == -1)
		return (ft_error("close() error"));
	return (0);
}

int			c_exec_put(char *cmd, char *input, char *opt)
{
	unsigned char	buf[1024 + 1];
	unsigned char	*data;
	int				r;
	unsigned int	size;

	(void)opt;
	if ((r = available_exec(cmd, (unsigned char *)input, 0)) == -1)
		return (-1);
	else if (r == 0)
		return (0);
	data = (unsigned char *)ft_strdup("");
	r = request_exec(cmd, (unsigned char *)input);
	if (r < 1)
		return ((r == 0) ? 0 : -1);
	size = 0;
	if (c_exec_put_(&data, (unsigned char *)input, buf, &size) == -1)
		return (-1);
	if (ft_send(data, size) == -1)
		return (-1);
	if (ft_recv(&data, NULL) == -1)
		return (-1);
	if (!ft_strequ((char *)data, "OK"))
		ft_putendl_fd("server put error", 2);
	free(data);
	return (0);
}
