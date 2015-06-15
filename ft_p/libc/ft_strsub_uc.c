/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_uc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:47:23 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/04 16:18:02 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

unsigned char	*ft_strsub_uc(unsigned char *s, unsigned int start, size_t len)
{
	unsigned char	*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (unsigned char *)ft_memalloc(len * sizeof(unsigned char) + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = 0;
	return (str);
}
