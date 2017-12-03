/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:55:09 by mgouault          #+#    #+#             */
/*   Updated: 2017/11/14 19:52:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;
	t_list *next_tmp;

	if (alst && *alst)
	{
		tmp = alst[0];
		while (tmp)
		{
			if (tmp->content && tmp->content_size && (*del))
				del(tmp->content, tmp->content_size);
			next_tmp = tmp->next;
			free(tmp);
			tmp = next_tmp;
		}
		alst[0] = NULL;
	}
}
