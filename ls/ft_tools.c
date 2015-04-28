/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 17:52:30 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 20:06:01 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

unsigned int	ft_nbrcnt(unsigned int n)
{
	unsigned int res;

	res = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		++res;
	}
	return (res);
}

int				ft_d_istoshow(int if_a, char *str)
{
	if (if_a == 1)
		return (1);
	else if ((str[0] == '.') && (str[1] == 0))
		return (1);
	else if (str[0] != '.')
		return (1);
	return (0);
}

int				ft_istoshow(t_lstf *tmp)
{
	if (g_option[1] == 1)
		return (1);
	else if ((g_option[3] == 0) && (tmp->name[0] != '.'))
		return (1);
	else if ((g_option[3] == 1) && (tmp->name[0] != '.'))
		return (ft_d_istoshow(g_option[1], tmp->folder));
	return (0);
}

void			ft_ns_putnbr(unsigned int n)
{
	if (n / 10 != 0)
		ft_ns_putnbr(n / 10);
	ft_putchar((n % 10) + '0');
}

int				ft_notadotlink(char *name)
{
	if (name[0] == '.')
	{
		if ((name[1] > 0) && name[1] != '.')
			return (1);
		else
			return (0);
	}
	else
		return (1);
}
