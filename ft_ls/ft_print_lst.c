/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 19:31:10 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 20:06:57 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_SYS_STAT_H
#define INC_LIBFT_H
#define INC_STRING_H
#include "ft_ls.h"

extern int *g_option;

void		ft_print_unit(unsigned int unit, int maxunit)
{
	int len;

	len = (int)ft_nbrcnt(unit);
	while (len < maxunit)
	{
		ft_putchar(' ');
		++len;
	}
	ft_ns_putnbr(unit);
	ft_putchar(' ');
}

void		ft_print_mkdev(int major, int minor)
{
	int len;

	len = (int)ft_nbrcnt(major);
	while (len < 3)
	{
		ft_putchar(' ');
		++len;
	}
	ft_putnbr(major);
	ft_putstr(", ");
	len = (int)ft_nbrcnt(minor);
	while (len < 3)
	{
		ft_putchar(' ');
		++len;
	}
	ft_putnbr(minor);
	ft_putchar(' ');
}

void		ft_print_str(char *str, int maxstr)
{
	int len;

	len = ft_strlen(str);
	ft_putstr(str);
	while (len < maxstr)
	{
		ft_putchar(' ');
		++len;
	}
	ft_putstr("  ");
}

static void	ft_print_with_n(char *str)
{
	ft_putstr(str);
	ft_putchar('\n');
}

void		ft_print_lst(t_lstf *begin)
{
	t_lstf *tmp;
	t_qlst *q_start;

	tmp = begin;
	q_start = NULL;
	while (tmp)
	{
		if (ft_istoshow(tmp))
			ft_print_with_n(tmp->name);
		if (g_option[3] && (S_ISDIR(tmp->st->st_mode) == 1) &&
			ft_notadotlink(tmp->name))
		{
			q_start = ft_qstart_create(tmp, q_start);
			if (g_option[2])
				tmp = tmp->prev;
			else
				tmp = tmp->next;
		}
		else
			tmp = ft_free_lst(tmp, g_option[2]);
	}
	ft_qstart_read(q_start);
}
