/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:06:40 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:41 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char *ft_strrchr(char *s, int c)
{
	char	*occ;
	int		i;

	i = 0;
	occ = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			occ = (char*)&s[i];
		++i;
		if ((s[i] == (char)c) && (c == 0))
			return ((char*)&s[i]);
	}
	if (occ == NULL)
		return (NULL);
	else
		return (occ);
}
