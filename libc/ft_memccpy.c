/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:17:26 by mgouault          #+#    #+#             */
/*   Updated: 2017/11/14 19:56:52 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void *ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	int				i;
	int				j;
	unsigned char	*s1;
	unsigned char	*s2;

	s1 = (unsigned char*)dst;
	s2 = (unsigned char*)src;
	i = 0;
	j = 0;
	while (n > 0)
	{
		s1[i] = s2[j];
		if (s2[j] == (unsigned char)c)
		{
			++i;
			return (&s1[i]);
		}
		++i;
		++j;
		--n;
	}
	return (NULL);
}
