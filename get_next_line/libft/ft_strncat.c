/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:05:19 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:37 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char *ft_strncat(char *s1, const char *s2, size_t n)
{
	int				i;
	unsigned int	k;

	i = 0;
	k = 0;
	while (s1[i])
		++i;
	while (s2[k] && k < n)
	{
		s1[i] = (char)s2[k];
		++i;
		++k;
	}
	s1[i] = '\0';
	return (s1);
}
