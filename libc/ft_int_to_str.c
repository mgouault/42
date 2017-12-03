/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:54:01 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:18:44 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static int	ft_count_char_for_int(int number) {
	int	count;

	count = 0;
	if (number < 0) {
		count++;
		number *= -1;
	}
	while (number > 0) {
		number /= 10;
		count++;
	}
	return (count);
}

char		*ft_int_to_str(int n)
{
	char	*res;
	int		i;

	i = ft_count_char_for_int(n);
	res = (char *)ft_malloc_str(i);
	res[i] = NULL;
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
