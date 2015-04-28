/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:51:16 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/16 15:22:44 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

char *ft_strdup(const char *s1)
{
	char	*str;
	int		i;

	i = -1;
	str = (char *)malloc(ft_strlen(s1) * sizeof(char) + 1);
	if (!str)
		return (NULL);
	while (s1[++i])
		str[i] = s1[i];
	str[i] = 0;
	return (str);
}
