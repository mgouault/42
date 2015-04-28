/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_lst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 12:52:19 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:48:32 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_STDLIB_H
#define INC_STRING_H
#include "ft_ls.h"

t_lstf	*ft_free_lst(t_lstf *list, int prev)
{
	t_lstf *next;

	if (prev)
		next = list->prev;
	else
		next = list->next;
	free(list->name);
	free(list->path);
	free(list->folder);
	free(list->st);
	list->prev = NULL;
	list->next = NULL;
	free(list);
	return (next);
}

t_qlst	*ft_free_qlst(t_qlst *queue)
{
	t_qlst *next;

	next = queue->next;
	queue->next = NULL;
	(void)ft_free_lst(queue->lst, 0);
	free(queue);
	return (next);
}
