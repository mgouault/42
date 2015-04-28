/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:29:28 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/13 20:58:32 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

t_lst	*get_lst(t_lst *link)
{
	static t_lst	*actual_lst = NULL;

	if (link)
	{
		while (link && link->prev)
			link = link->prev;
		actual_lst = link;
	}
	return (actual_lst);
}

int		get_fd(void)
{
	static int		actual_fd = -1;

	if (actual_fd == -1)
	{
		if ((actual_fd = open("/dev/tty", O_WRONLY)) == -1)
			error_exit("open error");
	}
	return (actual_fd);
}

char	*get_envterm(void)
{
	static char		*actual_envterm = NULL;

	if (!actual_envterm)
	{
		if (!(actual_envterm = getenv("TERM")))
			error_exit("getenv error");
	}
	return (actual_envterm);
}

char	*get_buf(char *buf)
{
	static char		*actual_buf = NULL;

	if (buf)
	{
		if (actual_buf)
			free(actual_buf);
		actual_buf = ft_strdup(buf);
	}
	return (actual_buf);
}
