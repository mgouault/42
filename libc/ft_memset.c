/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:17:53 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:24 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void	*ft_memset(void *b, int c, size_t len)
{
	int		i;
	char	*str;

	str = (char *)b;
	i = 0;
	while (len > 0)
	{
		str[i] = (unsigned char)c;
		++i;
		--len;
	}
	return (b);
}
