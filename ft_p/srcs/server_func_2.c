/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 20:29:11 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 16:48:16 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

extern char	*g_pwd;

static int	check_ftp(char *cmd, unsigned char *arg, int *r, int fd)
{
	struct stat	st;
	char		*error;

	error = NULL;
	if (ft_strequ(cmd, "get"))
	{
		if ((fd = open((char *)arg, O_RDONLY)) == -1)
			error = ft_strdup("can't access file");
		else if (fstat(fd, &st) == -1)
			error = ft_strdup("fstat() error");
		else if (S_ISDIR(st.st_mode) == 1)
			error = ft_strdup("target is a directory");
		if (fd > -1 && close(fd) == -1)
			return (ft_error("close() error"));
	}
	if (confirm_exec(r, error, ft_strequ(cmd, "put")) == -1)
		return (-1);
	return (0);
}

static int	s_exec_get_(int fd, unsigned char **data, unsigned int *size)
{
	unsigned char	buf[1024 + 1];
	unsigned char	*tmp;
	int				r;

	while ((r = read(fd, buf, 1024)) > 0)
	{
		buf[r] = 0;
		tmp = *data;
		*data = ft_strjoin_uc(*data, buf, *size, r);
		*size += r;
		free(tmp);
	}
	return (r);
}

int			s_exec_get(unsigned char *cmd, unsigned char *arg, int r)
{
	unsigned char	*data;
	unsigned int	size;
	int				fd;

	if (check_ftp((char *)cmd, arg, &r, 0) == -1)
		return (-1);
	if (!r)
		return (0);
	size = 0;
	data = (unsigned char *)ft_strdup("");
	if ((fd = open((char *)arg, O_RDONLY)) == -1)
		return (ft_error("open() error"));
	if ((r = s_exec_get_(fd, &data, &size)) == -1)
		return (ft_error("read() error"));
	if (close(fd) == -1)
		return (ft_error("close() error"));
	if (ft_send(data, size) == -1)
		return (-1);
	return (0);
}

int			s_exec_put(unsigned char *cmd, unsigned char *arg, int r)
{
	unsigned char	*data;
	int				fd;
	unsigned int	size;

	if (check_ftp((char *)cmd, arg, &r, 0) == -1)
		return (-1);
	if (!r)
		return (0);
	if ((fd = open((char *)arg, O_WRONLY | O_CREAT | O_TRUNC, 0700)) == -1)
		return (ft_error("open() error"));
	if (ft_recv(&data, &size) == -1)
		return (-1);
	if (write(fd, data, size) == -1)
		return (ft_error("write() error"));
	free(data);
	if (close(fd) == -1)
		return (ft_error("close() error"));
	if (ft_send((unsigned char *)ft_strdup("OK"), 2) == -1)
		return (-1);
	return (0);
}

int			s_ls(char *arg)
{
	DIR				*od;
	struct dirent	*rd;
	unsigned char	*data;
	unsigned char	*tmp;

	if (!(od = opendir(".")))
		return (ft_error("opendir() error"));
	data = (unsigned char *)ft_strdup("");
	while ((rd = readdir(od)))
		if ((rd->d_name && rd->d_name[0] != '.') || \
			(arg && ft_strequ(arg, "-a")))
		{
			tmp = (unsigned char *)ft_strjoin((char *)data, rd->d_name);
			free(data);
			data = (unsigned char *)ft_strjoin((char *)tmp, "\n");
			free(tmp);
		}
	if (closedir(od) == -1)
		return (ft_error("closedir() error"));
	if (!*data)
		free(data), data = (unsigned char *)ft_strdup("EMPTY_SCUMBAG4242");
	if (ft_send(data, ft_strlen_uc(data)) == -1)
		return (-1);
	return (0);
}
