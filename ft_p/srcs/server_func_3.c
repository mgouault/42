/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/03 14:37:38 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/03 22:26:03 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

static char	*dot_slash(char *str)
{
	char	*tmp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	tmp = (char *)ft_memalloc(sizeof(char) * size + 1);
	i = -1;
	j = 0;
	while (++i < size)
		if (str[i] == '.' && str[i + 1] == '/' && str[i - 1] == '/')
		{
			str[i] = 0;
			str[i + 1] = 0;
		}
	i = -1;
	while (++i < size)
		if (str[i] != 0)
			tmp[j++] = str[i];
	tmp[j] = 0;
	free(str);
	return (tmp);
}

static char	*double_slash(char *str)
{
	char	*tmp;
	int		size;
	int		i;
	int		j;

	size = ft_strlen(str);
	tmp = (char *)ft_memalloc(sizeof(char) * size + 1);
	i = -1;
	j = 0;
	while (++i < size)
		if (str[i] == '/' && str[i + 1] == '/')
			str[i] = 0;
	i = -1;
	while (++i < size)
		if (str[i] != 0)
			tmp[j++] = str[i];
	tmp[j] = 0;
	free(str);
	return (tmp);
}

static char	*dot_dot(char *path, t_bool *restricted, int i)
{
	char	*tmp1;
	char	*tmp2;

	while (path[++i])
		if (path[i] == '.' && path[i + 1] == '.' && \
			path[i + 2] == '/' && path[i - 1] == '/' && i < 3)
		{
			if (restricted)
				*restricted = TRUE;
			free(path);
			return (ft_strdup("/"));
		}
		else if (path[i] == '.' && path[i + 1] == '.' && \
			path[i + 2] == '/' && path[i - 1] == '/' && i >= 3)
		{
			tmp1 = ft_strsub(path, i + 2, ft_strlen(path) - (i + 2));
			i -= 2;
			while (path[i] != '/')
				--i;
			tmp2 = ft_strsub(path, 0, i), free(path);
			path = ft_strjoin(tmp2, tmp1), free(tmp1), free(tmp2);
			i = 0;
		}
	return (path);
}

char		*resolve_path(char *path, t_bool *restricted)
{
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
		path = tmp;
	}
	path = dot_slash(path);
	path = double_slash(path);
	path = dot_slash(path);
	path = dot_dot(path, restricted, 0);
	if (path[ft_strlen(path) - 1] == '/' && ft_strlen(path) > 1)
	{
		tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
		free(path);
		path = tmp;
	}
	return (path);
}
