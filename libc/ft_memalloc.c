/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:25 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/16 20:50:13 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void *ft_memalloc(size_t size)
{
	void *ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		ft_putendl_fd("malloc error", 2);
		exit(EXIT_FAILURE);
	}
	ptr = ft_memset(ptr, 0, size);
	return (ptr);
}
