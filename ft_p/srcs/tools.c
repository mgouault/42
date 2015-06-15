/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 15:06:08 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 16:46:23 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

extern int	g_csock;

static int	cmd_send(unsigned char *data, unsigned int size)
{
	unsigned char	buf[TRAM_SIZE + 1];
	int				r_r;
	int				r_s;

	if ((r_s = send(g_csock, data, size, 0)) == -1)
		return (ft_error("send() error"));
	if ((r_r = recv(g_csock, buf, TRAM_SIZE, 0)) == -1)
		return (ft_error("recv() error"));
	buf[r_r] = 0;
	if (!ft_strequ((char *)buf, "OK"))
		return (ft_error("transmission error"));
	return (r_s);
}

int			ft_send(unsigned char *data, unsigned int size)
{
	unsigned char	*tmp;
	int				r_s;

	tmp = (unsigned char *)ft_itoa(size);
	if (cmd_send(tmp, ft_strlen_uc(tmp)) == -1)
		return (-1);
	free(tmp);
	while (TRUE && size > 0)
	{
		if ((r_s = cmd_send(data, (size < TRAM_SIZE) ? size : TRAM_SIZE)) == -1)
			return (-1);
		tmp = data;
		data = ft_strsub_uc(data, r_s, size - r_s);
		free(tmp);
		size -= r_s;
		if (size == 0)
			break ;
	}
	if (send(g_csock, "WAIT", 4, 0) == -1)
		return (ft_error("send() error"));
	return (0);
}

static int	cmd_recv(unsigned char **buf)
{
	int	r_r;

	if ((r_r = recv(g_csock, *buf, TRAM_SIZE, 0)) == -1)
		return (ft_error("recv() error"));
	(*buf)[r_r] = 0;
	if (send(g_csock, "OK", 2, 0) == -1)
		return (ft_error("send() error"));
	return (r_r);
}

static int	ftporc(unsigned char **data, unsigned char *buf, int r_r, int size)
{
	unsigned char	*tmp;
	unsigned int	total;

	total = 0;
	while (TRUE && size > 0)
	{
		buf = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
			(TRAM_SIZE + 1));
		if ((r_r = cmd_recv(&buf)) == -1)
			return (-1);
		tmp = *data;
		*data = ft_strjoin_uc(*data, buf, total, r_r);
		free(tmp), free(buf);
		total += r_r;
		size -= r_r;
		if (!size)
			break ;
	}
	return (0);
}

int			ft_recv(unsigned char **data, unsigned int *total)
{
	unsigned char	*buf;
	int				size;
	int				r_r;

	buf = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (TRAM_SIZE + 1));
	if (cmd_recv(&buf) == -1)
		return (-1);
	size = ft_atoi((char *)buf);
	if (total)
		*total = size;
	free(buf);
	*data = (unsigned char *)ft_strdup("");
	if (ftporc(data, buf, 0, size) == -1)
		return (-1);
	buf = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
			(TRAM_SIZE + 1));
	if ((r_r = recv(g_csock, buf, TRAM_SIZE, 0)) == -1)
		return (ft_error("recv() error"));
	buf[r_r] = 0;
	if (!ft_strequ((char *)buf, "WAIT"))
		return (ft_error("transmission error"));
	return (0);
}
