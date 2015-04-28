/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:54:01 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/16 15:21:22 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

static char	*ft_int_min(int n)
{
	char	*res;
	int		i;

	i = 11;
	res = (char *)malloc(sizeof(char) * 11 + 1);
	if (!res)
		return (NULL);
	++n;
	n = -n;
	res[0] = '-';
	while (n > 0)
	{
		res[--i] = (n % 10) + '0';
		n /= 10;
	}
	res[10] = 8 + '0';
	res[11] = 0;
	return (res);
}

static int	ft_nbrcnt(int n)
{
	int		res;

	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		++res;
		n = -n;
	}
	while (n > 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

static char	*ft_allocnbstr(int n, int nbr_char)
{
	char	*res;

	if (n < 0)
		res = (char *)malloc((nbr_char + 1) * sizeof(char) + 1);
	else
		res = (char *)malloc(nbr_char * sizeof(char) + 1);
	if (!res)
		return (NULL);
	return (res);
}

char		*ft_itoa(int n)
{
	char	*res;
	int		i;

	if (n == -2147483648)
		res = ft_int_min(n);
	if ((n == -2147483648) && (res))
		return (res);
	i = ft_nbrcnt(n);
	res = ft_allocnbstr(n, i);
	if (!res)
		return (NULL);
	res[i] = 0;
	if (n < 0)
	{
		n = -n;
		res[0] = '-';
	}
	if (n == 0)
		res[0] = '0';
	while (n > 0)
	{
		res[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (res);
}
