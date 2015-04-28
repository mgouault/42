/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/14 14:03:41 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/18 14:57:12 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static char	*ft_strdup_free(char *s, char *to_free)
{
	s = ft_strdup((char *)s);
	free(to_free);
	return (s);
}

static char	*ft_strjoin_free(char *s1, char *s2)
{
	char *tmp;

	tmp = s1;
	s1 = ft_strjoin((char *)s1, (char *)s2);
	free(tmp);
	return (s1);
}

static char	*get_next_line_(char *haz_rid, char **line, int ret)
{
	int	i;

	i = ft_strchr(haz_rid, '\n') - haz_rid;
	if (ft_strchr(haz_rid, '\n') == haz_rid && ret == 0)
		*line = ft_strdup(haz_rid);
	else
		*line = ft_strsub(haz_rid, 0, i);
	if (!(*line))
		return (NULL);
	haz_rid = ft_strdup_free(&haz_rid[i + 1], haz_rid);
	return (haz_rid);
}

int			get_next_line(int fd, char **line)
{
	static char	*haz_rid = NULL;
	char		buf[BUFF_SIZE + 1];
	int			ret;

	ret = 1;
	if (!line)
		return (-1);
	if (!haz_rid)
		haz_rid = ft_strdup("");
	while ((ret > 0) && !ft_strchr((char *)haz_rid, '\n'))
	{
		ret = read(fd, buf, BUFF_SIZE);
		buf[ret] = 0;
		if (!(haz_rid = ft_strjoin_free(haz_rid, buf)))
			return (-1);
	}
	if (ret >= 0 && haz_rid[0] != 0)
		if (!(haz_rid = get_next_line_(haz_rid, line, ret)))
			return (-1);
	if (ret > 0)
		return (1);
	return (ret);
}
