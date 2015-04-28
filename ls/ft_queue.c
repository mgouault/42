/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_queue.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 18:19:44 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:58:38 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

t_qlst	*ft_qstart_create(t_lstf *tmp, t_qlst *q_start)
{
	t_qlst *queue;
	t_qlst *q_tmp;

	queue = (t_qlst *)malloc(sizeof(t_qlst));
	if (!queue)
		return (0);
	queue->lst = tmp;
	queue->next = NULL;
	if (!q_start)
		q_start = queue;
	else
	{
		q_tmp = q_start;
		while (q_tmp->next)
			q_tmp = q_tmp->next;
		q_tmp->next = queue;
	}
	return (q_start);
}

void	ft_qstart_read(t_qlst *q_start)
{
	while (q_start)
	{
		if (ft_d_istoshow(g_option[1], q_start->lst->name) == 1)
			ft_putchar('\n');
		ft_rcsv_lst(q_start->lst);
		q_start = ft_free_qlst(q_start);
	}
}
