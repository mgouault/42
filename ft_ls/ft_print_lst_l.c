/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst_l.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 14:52:36 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:55:20 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_SYS_STAT_H
#define INC_TIME_H
#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

static char		*ft_printtime_(t_lstf *tmp)
{
	char *str_tmp;
	char *str_tmp2;
	char *str_tmp3;

	str_tmp = ctime(&tmp->st->st_mtime);
	if (!str_tmp)
		ft_error("", 1);
	str_tmp2 = ft_strsub(str_tmp, 4, 6);
	str_tmp = ft_strsub(str_tmp, 19, 5);
	if (!str_tmp)
		ft_error("", 1);
	str_tmp3 = ft_strjoin(" ", str_tmp);
	free(str_tmp);
	if (!str_tmp2 || !str_tmp3)
		ft_error("", 1);
	str_tmp = ft_strjoin(str_tmp2, str_tmp3);
	free(str_tmp2);
	free(str_tmp3);
	return (str_tmp);
}

void			ft_printtime(t_lstf *tmp)
{
	time_t	t_loc;
	char	*str_tmp;

	if (time(&t_loc) == -1)
		ft_error("", 1);
	if ((tmp->st->st_mtime > (t_loc - 15768000)) &&
		(tmp->st->st_mtime <= (t_loc + 60)))
		str_tmp = ft_strsub(ctime(&tmp->st->st_mtime), 4, 12);
	else
		str_tmp = ft_printtime_(tmp);
	if (!str_tmp)
		ft_error("", 1);
	ft_putstr(str_tmp);
	free(str_tmp);
	ft_putchar(' ');
}

static t_lstf	*ft_do_next(t_lstf *tmp, t_qlst **q_start, unsigned int *max_v)
{
	if (ft_istoshow(tmp) == 1)
		ft_print_lst_l_(tmp, max_v);
	if (g_option[3] && (S_ISDIR(tmp->st->st_mode) == 1) &&
		ft_notadotlink(tmp->name))
	{
		*q_start = ft_qstart_create(tmp, *q_start);
		if (g_option[2])
			tmp = tmp->prev;
		else
			tmp = tmp->next;
	}
	else
		tmp = ft_free_lst(tmp, g_option[2]);
	return (tmp);
}

void			ft_print_lst_l(t_lstf *begin, int file)
{
	t_lstf			*tmp;
	t_qlst			*q_start;
	unsigned int	max_v[6];

	ft_set_tab((int *)max_v, 6);
	tmp = begin;
	q_start = NULL;
	while (tmp != NULL)
		tmp = ft_pre_calc(tmp, max_v);
	tmp = begin;
	if ((max_v[5] == 1) && (file == 0) &&
		(ft_d_istoshow(g_option[1], tmp->folder) == 1))
	{
		ft_putstr("total ");
		ft_putnbr(max_v[0]);
		ft_putchar('\n');
	}
	while (tmp != NULL)
		tmp = ft_do_next(tmp, &q_start, max_v);
	ft_qstart_read(q_start);
}
