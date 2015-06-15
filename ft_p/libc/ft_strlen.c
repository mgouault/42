/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/03 18:56:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/05/28 15:04:14 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

size_t ft_rec_strlen(char *s, size_t i)
{
	if (s[i] == 0)
		return (i);
	return (ft_rec_strlen(s, i + 1));
}

size_t ft_strlen(char *s)
{
	return (ft_rec_strlen(s, 0));
}
