/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:53:55 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/21 20:16:27 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

static int	ft_strcnt(char const *s, char c)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] && s[i] != c)
		{
			++j;
			while (s[i] && s[i] != c)
				++i;
		}
		++i;
	}
	return (j);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		p;

	i = 0;
	p = 0;
	if (!s || !c)
		return (NULL);
	str = (char **)malloc(sizeof(char *) * (ft_strcnt(s, c) + 1));
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
	str[p] = 0;
	return (str);
}
