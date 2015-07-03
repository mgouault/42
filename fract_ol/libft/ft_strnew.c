/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:36 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:40 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char *ft_strnew(size_t size)
{
	char *s;

	s = (char *)malloc(size * sizeof(char) + 1);
	if (!s)
		return (NULL);
	s = ft_memset(s, 0, size + 1);
	return (s);
}
