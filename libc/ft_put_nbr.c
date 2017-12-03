/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:39:04 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:57:48 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

static void	ft_recurs(int number, int fd)
{
	if (number / 10 != 0)
		ft_putnbr_fd((number / 10), fd);
	ft_putchar_fd(ft_digit_to_char(number % 10), fd);
}

void		ft_putnbr_fd(int number, int fd)
{
	if (number == 0) {
		ft_putchar_fd('0', fd)
		return;
	}
	if (number < 0)
	{
		number *= -1;
		ft_putchar_fd('-', fd);
	}
	ft_recurs(number, fd);
}
