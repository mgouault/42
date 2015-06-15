/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strreplace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 20:30:39 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/17 21:00:20 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char *ft_strreplace(char *str, char *occ, char *replace)
{
	char	*s1;
	char	*s2;
	char	*tmp;
	int		i;

	i = ft_strstr(str, occ) - str;
	s1 = ft_strsub(str, 0, i);
	s2 = ft_strsub(str, i + ft_strlen(occ), \
		ft_strlen(str) - (i + ft_strlen(occ)));
	tmp = ft_strjoin(s1, replace);
	free(s1);
	s1 = ft_strjoin(tmp, s2);
	free(tmp);
	free(s2);
	return (s1);
}
