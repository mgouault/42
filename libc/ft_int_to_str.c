/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_to_str.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/07 13:54:01 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:41:31 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static int	ft_count_char_for_int(int number)
{
	int	count;

	count = 0;
	if (number < 0)
	{
		count++;
		number *= -1;
	}
	while (number > 0)
	{
		number /= 10;
		count++;
	}
	return (count);
}

static char	*ft_fill_str_with_int(char *res, int number)
{
	while (number > 0)
	{
		*res = ft_digit_to_char(number % 10);
		number /= 10;
		res--;
	}
}

char		*ft_int_to_str(int number)
{
	char	*str;
	int		i;

	i = ft_count_char_for_int(number);
	str = (char *)ft_malloc_str(i);
	str += i - 1;
	if (number == 0)
	{
		str[0] = '0';
		return (str);
	}
	if (number < 0)
	{
		number *= -1;
		str[0] = '-';
	}
	ft_fill_str_with_int(str, number);
	return (str);
}
