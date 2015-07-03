/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:53:38 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:43 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;

	i = 0;
	if (!s)
		return (NULL);
	str = (char *)malloc(len * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s[start] && (i < len))
	{
		str[i] = s[start];
		++i;
		++start;
	}
	str[i] = 0;
	return (str);
}
