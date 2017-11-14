/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:06:49 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:43 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	*ft_strstr(char *s1, char *s2)
{
	int i;
	int j;
	int k;

	i = -1;
	if (s2[0] == '\0')
		return ((char*)s1);
	while (s1[++i])
	{
		if (s1[i] == s2[0])
		{
			j = 0;
			k = i;
			while (s1[k] == s2[j])
			{
				++k;
				++j;
				if (s2[j] == '\0')
					return ((char*)&s1[i]);
			}
		}
	}
	return (NULL);
}
