/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:17:48 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/16 15:22:21 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	int		j;
	char	*tmp;
	char	*str1;
	char	*str2;

	str1 = (char*)dst;
	str2 = (char*)src;
	i = 0;
	j = -1;
	tmp = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (!tmp)
		return (NULL);
	while (++j < (int)len)
		tmp[j] = str2[j];
	tmp[j] = 0;
	while (len > 0)
	{
		str1[i] = tmp[i];
		++i;
		--len;
	}
	return (dst);
}
