/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:53:48 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/16 20:06:59 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static char	*ft_strempty(void)
{
	char *str;

	str = (char *)ft_memalloc(1);
	if (!str)
		return (NULL);
	*str = 0;
	return (str);
}

static int	ft_j_nb(char *s)
{
	int j;

	j = ft_strlen(s) - 1;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		--j;
	return (j);
}

static int	ft_i_nb(char *s)
{
	int i;

	i = 0;
	while (s[i] && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		++i;
	return (i);
}

char		*ft_strtrim(char *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	k = 0;
	if (!s)
		return (NULL);
	i = ft_i_nb(s);
	j = ft_j_nb(s);
	if (j < i)
		str = ft_strempty();
	if ((j < i) && str)
		return (str);
	str = (char *)ft_memalloc(sizeof(char) * (j - i) + 1);
	if (!str)
		return (NULL);
	while (s[i] && i <= j)
	{
		str[k] = s[i];
		++k;
		++i;
	}
	str[k] = 0;
	return (str);
}
