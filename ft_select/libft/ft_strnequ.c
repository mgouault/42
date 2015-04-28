/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:05:54 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:39 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	if (!s1 || !s2)
		return (0);
	i = -1;
	while ((s1[++i] || s2[i]) && i < (int)n)
		if (s1[i] != s2[i])
			return (0);
	return (1);
}
