/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/12 16:55:09 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/14 17:24:50 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list *ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;
	char	*str;
	char	*tmp;

	str = (char *)content;
	new = (t_list *)malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (str == NULL || content_size == 0)
	{
		new->content = NULL;
		new->content_size = 0;
	}
	else
	{
		tmp = malloc(sizeof(*tmp) * content_size);
		if (!tmp)
			return (NULL);
		tmp = ft_memcpy(tmp, str, content_size);
		new->content = tmp;
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
