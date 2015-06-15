/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_uc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:47:23 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/04 16:31:24 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

unsigned char	*ft_strjoin_uc(unsigned char *s1, unsigned char *s2, \
	unsigned int s1_size, unsigned int s2_size)
{
	unsigned char	*str;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	str = (unsigned char *)ft_memalloc(sizeof(unsigned char) * \
		(s1_size + s2_size) + 1);
	if (!str)
		return (NULL);
	while (i < s1_size)
	{
		str[i] = s1[i];
		++i;
	}
	j = 0;
	while (j < s2_size)
	{
		str[i] = s2[j];
		++i;
		++j;
	}
	str[i] = 0;
	return (str);
}
