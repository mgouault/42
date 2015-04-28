/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 19:26:07 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/13 23:01:05 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static t_lst	*dynamic_search_(t_lst *link, char *search)
{
	t_lst	*tmp;
	char	*str;

	str = ft_strdup(search);
	if (!madehome_strstr(link->name, str))
	{
		tmp = get_lst(NULL);
		while (tmp)
		{
			if (madehome_strstr(tmp->name, str))
				break ;
			tmp = tmp->next;
		}
		link = (tmp) ? tmp : link;
	}
	free(str);
	return (link);
}

t_lst			*dynamic_search(char **search, t_lst *link)
{
	char *buf;
	char *free_tmp;

	buf = get_buf(NULL);
	link->cursor_on = FALSE;
	if (*search)
	{
		free_tmp = *search;
		*search = ft_strjoin(*search, buf);
		free(free_tmp);
	}
	else
		*search = ft_strdup(buf);
	link = dynamic_search_(link, *search);
	link->cursor_on = TRUE;
	print_lst();
	return (link);
}

void			delete_link(t_lst *link)
{
	if (!link->next && !link->prev)
		proper_exit(link);
	if (link->loop && link->next && !link->prev)
	{
		link->loop->loop = link->next;
		link->next->loop = link->loop;
		link->next->prev = NULL;
	}
	else if (link->loop && !link->next && link->prev)
	{
		link->loop->loop = link->prev;
		link->prev->loop = link->loop;
		link->prev->next = NULL;
	}
	else if (!link->loop && link->next && link->prev)
	{
		link->prev->next = link->next;
		link->next->prev = link->prev;
	}
	free(link->name);
	free(link);
}

static t_lst	*build_lst_(t_lst *link, t_lst *tmp, t_lst *loop)
{
	while (link)
	{
		link->next = tmp;
		if (!tmp)
		{
			link->loop = loop;
			loop = link;
		}
		tmp = link;
		if (!link->prev)
			link->loop = loop;
		link = link->prev;
	}
	return (tmp);
}

void			build_lst(char **av)
{
	t_lst	*link;
	t_lst	*tmp;
	t_lst	*loop;
	int		i;

	i = 0;
	tmp = NULL;
	loop = NULL;
	while (av[++i])
	{
		if (!(link = (t_lst *)malloc(sizeof(t_lst))))
			error_exit("malloc error");
		if (!loop)
			loop = link;
		link->name = ft_strdup(av[i]);
		link->length = ft_strlen(link->name);
		link->prev = tmp;
		link->loop = NULL;
		link->selected = FALSE;
		link->cursor_on = FALSE;
		tmp = link;
	}
	tmp = build_lst_(link, NULL, loop);
	tmp->cursor_on = TRUE;
	(void)get_lst(tmp);
}
