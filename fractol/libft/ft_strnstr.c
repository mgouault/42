/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:05:10 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/12 21:38:41 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	j;
	size_t	i;
	int		k;
	char	*tmp1;
	char	*tmp2;

	tmp1 = (char *)s1;
	tmp2 = (char *)s2;
	i = ft_strlen(tmp1);
	j = ft_strlen(tmp2);
	if (j == 0)
		return (tmp1);
	if ((k = n - j + 1) > (int)i)
		k = i - j + 1;
	if (n > j)
		n = j;
	while (k > 0)
	{
		if (ft_strncmp(tmp1, tmp2, n) == 0)
			return (tmp1);
		tmp1++;
		k--;
	}
	return (NULL);
}
