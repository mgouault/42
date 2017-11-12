/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:53:55 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/21 20:11:59 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	**ft_strsplit(char *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = -1;
	if (!s || !c || !(str = (char **)ft_memalloc(sizeof(char *) * \
		(ft_strcnt(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			j = i;
			while (s[j] && s[j] != c)
				j++;
			str[++p] = ft_strsub(s, i, j - i);
			i = j;
		}
		if (s[i])
			i++;
	}
	str[++p] = NULL;
	return (str);
}
