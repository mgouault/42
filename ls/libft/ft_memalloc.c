/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:25 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/14 17:25:10 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void *ft_memalloc(size_t size)
{
	void *s;

	s = malloc(size);
	if (!s)
		return (NULL);
	s = ft_memset(s, 0, size);
	return (s);
}
