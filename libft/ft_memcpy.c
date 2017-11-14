/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:17:43 by mgouault          #+#    #+#             */
/*   Updated: 2017/11/14 19:56:52 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	int		i;
	char	*str1;
	char	*str2;

	str1 = (char*)dst;
	str2 = (char*)src;
	i = 0;
	while (n > 0)
	{
		str1[i] = str2[i];
		++i;
		--n;
	}
	return (dst);
}
