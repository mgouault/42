/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:53:55 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/21 20:16:50 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char		**ft_strsplit(char *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	if (!s || !c)
		return (NULL);
	str = (char **)ft_memalloc(sizeof(char *) * (ft_strcnt(s, c) + 1));
	if (!str)
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		j = i;
		while (s[j] && s[j] != c)
			++j;
		if (i < j)
			str[p++] = ft_strsub(s, i, j - i);
		i = j;
	}
	str[p] = NULL;
	return (str);
}
