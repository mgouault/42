/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 15:31:16 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:59:10 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_SYS_STAT_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

static void		ft_swap_dlst(t_lstf **tmp1, t_lstf **tmp2)
{
	(*tmp1)->next = (*tmp2)->next;
	if ((*tmp1)->next)
		(*tmp1)->next->prev = (*tmp1);
	if ((*tmp1)->prev)
		(*tmp1)->prev->next = (*tmp2);
	(*tmp2)->next = (*tmp1);
	(*tmp2)->prev = (*tmp1)->prev;
	(*tmp1)->prev = (*tmp2);
	*tmp1 = (*tmp2)->prev;
}

static int		ft_itr(t_lstf *tmp1, t_lstf *tmp2, int is_av)
{
	if (is_av == 1)
	{
		if ((S_ISDIR(tmp1->st->st_mode) == 1) &&
			(S_ISDIR(tmp2->st->st_mode) == 0))
			return (1);
	}
	else if ((g_option[4] == 1) && (is_av == 0) &&
		(tmp1->st->st_mtime != tmp2->st->st_mtime))
	{
		if (tmp1->st->st_mtime < tmp2->st->st_mtime)
			return (1);
	}
	else
	{
		if (ft_strcmp(tmp1->name, tmp2->name) > 0)
			return (1);
	}
	return (0);
}

static t_lstf	*ft_sort_lst_(t_lstf *read, t_lstf *start,
	int is_av)
{
	t_lstf	*tmp1;
	t_lstf	*tmp2;

	while (read && read->next)
	{
		if (ft_itr(read, read->next, is_av))
		{
			tmp1 = read;
			tmp2 = read->next;
			while (tmp1 && tmp2 && (ft_itr(tmp1, tmp2, is_av)))
				ft_swap_dlst(&tmp1, &tmp2);
			read = start;
		}
		else
			read = read->next;
	}
	return (start);
}

t_lstf			*ft_sort_lst(t_lstf *begin, int is_av)
{
	begin = ft_sort_lst_(begin, begin, is_av);
	if (g_option[2])
		while (begin->next)
			begin = begin->next;
	else
		while (begin->prev)
			begin = begin->prev;
	return (begin);
}
