/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_uc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 20:46:45 by mgouault          #+#    #+#             */
/*   Updated: 2015/05/28 20:53:27 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

unsigned char	**ft_strsplit_uc(unsigned char *s, unsigned char c)
{
	unsigned char	**str;
	int				i;
	int				j;
	int				p;

	i = 0;
	p = 0;
	if (!s || !c)
		return (NULL);
	if (!(str = (unsigned char **)ft_memalloc(sizeof(char *) * \
		(ft_strcnt_uc(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		while (s[i] && s[i] == c)
			++i;
		j = i;
		while (s[j] && s[j] != c)
			++j;
		if (i < j)
			str[p++] = ft_strsub_uc(s, i, j - i);
		i = j;
	}
	str[p] = NULL;
	return (str);
}
