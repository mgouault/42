/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:19:33 by mgouault          #+#    #+#             */
/*   Updated: 2015/01/03 20:20:45 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_strsplit_fdf(char *s, int *tab)
{
	int		i;
	int		j;
	int		x;
	char	*str;

	i = 0;
	x = -1;
	while (s[i])
	{
		while (s[i] && (ft_isdigit(s[i]) == 0))
			++i;
		j = i;
		while (s[j] && (ft_isdigit(s[j]) == 1))
			++j;
		if (i < j)
		{
			if (!(str = ft_strsub(s, i, j - i)))
				ft_error();
			tab[++x] = ft_atoi(str);
			if (s[i - 1] == '-')
				tab[x] *= -1;
			free(str);
		}
		i = j;
	}
}

static int		ft_strcnt_fdf(char *s)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && (ft_isdigit(s[i]) == 1))
		{
			++j;
			while (s[i] && (ft_isdigit(s[i]) == 1))
				++i;
		}
		else
			++i;
	}
	return (j);
}

static t_fdf	*ft_create_map(int y, t_fdf *start)
{
	int		i;
	t_fdf	*map;
	t_fdf	*tmp;

	i = 0;
	if (!(map = (t_fdf *)malloc(sizeof(t_fdf) * (y + 1))))
		ft_error();
	while (start)
	{
		map[i].length = start->length;
		map[i].tab = start->tab;
		map[i].next = NULL;
		++i;
		start = ft_free_link(start);
	}
	if (!(tmp = (t_fdf *)malloc(sizeof(t_fdf))))
		ft_error();
	map[i] = *tmp;
	map[i].length = 0;
	map[i].tab = NULL;
	map[i].next = NULL;
	return (map);
}

static int		ft_gather_data_(t_fdf **start, int fd, int *ret, int y)
{
	t_fdf	*link;
	t_fdf	**next;
	char	*line;

	next = NULL;
	while ((*ret = get_next_line(fd, &line)) > 0)
	{
		if (!(link = (t_fdf *)malloc(sizeof(t_fdf))))
			ft_error();
		link->length = ft_strcnt_fdf(line);
		if (!(link->tab = (int *)malloc(sizeof(int) * link->length)))
			ft_error();
		ft_strsplit_fdf(line, link->tab);
		free(line);
		if (*start == NULL)
			*start = link;
		if (next != NULL)
			*next = link;
		next = &link->next;
		++y;
	}
	if (next != NULL)
		*next = NULL;
	return (y);
}

t_fdf			*ft_gather_data(char *name)
{
	int		fd;
	int		ret;
	int		y;
	t_fdf	*start;

	start = NULL;
	if ((fd = open(name, O_RDONLY)) == -1)
		ft_error();
	ret = 1;
	y = ft_gather_data_(&start, fd, &ret, 0);
	if (ret == -1)
		ft_error();
	if ((close(fd)) == -1)
		ft_error();
	return (ft_create_map(y, start));
}
