/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:02:26 by mgouault          #+#    #+#             */
/*   Updated: 2014/11/14 15:13:02 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

int ft_atoi(char *str)
{
	int i;
	int res;
	int sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\r' || str[i] == '\v'
		|| str[i] == '\n' || str[i] == '\t')
		++i;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		++i;
	}
	while ((str[i] >= '0' && str[i] <= '9') && str[i])
	{
		res = res * 10 + (str[i] - '0');
		++i;
	}
	return (res * sign);
}
