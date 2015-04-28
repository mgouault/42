/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:04:31 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:29 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strchr(const char *s, int c)
{
	int i;

	i = -1;
	while (s[++i] || c == 0)
		if (s[i] == (char)c)
			return ((char*)&s[i]);
	return (NULL);
}
