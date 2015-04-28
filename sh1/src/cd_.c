/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 20:10:11 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/15 19:46:49 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

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

char		*cleanpath(char *str)
{
	str = dot_slash(str);
	str = double_slash(str);
	str = dot_slash(str);
	return (str);
}

static char	*dot_dot_returnslash(char *path)
{
	free(path);
	path = ft_strdup("/");
	return (path);
}

char		*dot_dot(char *path, int i, char *tmp1, char *tmp2)
{
	while (path[++i])
	{
		if (path[i] == '.' && path[i + 1] == '.' &&
			path[i + 2] == '/' && path[i - 1] == '/')
		{
			if (i < 3)
				return (dot_dot_returnslash(path));
			else
			{
				tmp1 = ft_strsub(path, i + 2, ft_strlen(path) - (i + 2));
				i -= 2;
				while (path[i] != '/')
					--i;
				tmp2 = ft_strsub(path, 0, i);
				free(path);
				path = ft_strjoin(tmp2, tmp1);
				free(tmp1);
				free(tmp2);
				i = 0;
			}
		}
	}
	return (path);
}
