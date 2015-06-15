/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_uc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:47:23 by mgouault          #+#    #+#             */
/*   Updated: 2015/05/28 19:47:54 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

size_t	ft_rec_strlen_uc(unsigned char *s, size_t i)
{
	if (s[i] == 0)
		return (i);
	return (ft_rec_strlen_uc(s, i + 1));
}

size_t	ft_strlen_uc(unsigned char *s)
{
	return (ft_rec_strlen_uc(s, 0));
}
