/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:55:09 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/13 17:19:02 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void ft_lstdelone(t_list **alst, void (*del)(void *, size_t))
{
	if (alst && *alst)
	{
		if (alst[0]->content && alst[0]->content_size && (*del))
			del(alst[0]->content, alst[0]->content_size);
		free(alst[0]);
		alst[0] = NULL;
	}
}
