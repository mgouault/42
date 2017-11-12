/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:05:54 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/17 13:45:33 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

t_bool	ft_strnequ(char *s1, char *s2, size_t n)
{
	int i;

	if (!s1 || !s2)
		return (FALSE);
	i = -1;
	while ((s1[++i] || s2[i]) && i < (int)n)
		if (s1[i] != s2[i])
			return (FALSE);
	return (TRUE);
}
