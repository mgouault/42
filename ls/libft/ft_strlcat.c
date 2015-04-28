/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:04:58 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:35 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	t_dest;
	size_t	t_src;
	size_t	i;
	size_t	j;
	size_t	k;

	t_dest = ft_strlen(dest);
	t_src = ft_strlen((char*)src);
	i = 0;
	j = t_dest;
	k = size - t_dest - 1;
	if (size > t_dest)
	{
		while (i < k)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = '\0';
		return (t_dest + t_src);
	}
	return (t_src + size);
}
