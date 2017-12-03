/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:02:26 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:19:01 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int		ft_str_to_int(char *str)
{
	static char	whitespace[7] = " \f\r\v\n\t";
	int			i;
	int			res;
	int			sign;

	i = 0;
	while (str[i] && ft_char_in_str(whitespace, str[i]))
		++i;
	sign = 1;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	res = 0;
	while (str[i] && ft_is_digit(str[i]))
	{
		res *= 10;
		res += ft_char_to_digit(str[i]);
		++i;
	}
	return (res * sign);
}
