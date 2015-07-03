/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pre_calc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 14:28:07 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 20:13:45 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_PWD_H
#define INC_GRP_H
#define INC_SYS_STAT_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

static void ft_calc_maxid(t_lstf *tmp, unsigned int *max_v)
{
	struct passwd	*pwd;
	struct group	*grp;

	if ((pwd = getpwuid(tmp->st->st_uid)) != NULL)
	{
		if (max_v[3] < (unsigned int)ft_strlen(pwd->pw_name))
			max_v[3] = (unsigned int)ft_strlen(pwd->pw_name);
	}
	else
	{
		if (max_v[3] < ft_nbrcnt(tmp->st->st_uid))
			max_v[3] = ft_nbrcnt(tmp->st->st_uid);
	}
	if ((grp = getgrgid(tmp->st->st_gid)) != NULL)
	{
		if (max_v[4] < (unsigned int)ft_strlen(grp->gr_name))
			max_v[4] = (unsigned int)ft_strlen(grp->gr_name);
	}
	else
	{
		if (max_v[4] < ft_nbrcnt(tmp->st->st_gid))
			max_v[4] = ft_nbrcnt(tmp->st->st_gid);
	}
}

static void ft_calc_preprint(t_lstf *tmp, unsigned int *max_v)
{
	max_v[0] += (unsigned int)tmp->st->st_blocks;
	if (max_v[1] < (unsigned int)tmp->st->st_size)
		max_v[1] = (unsigned int)tmp->st->st_size;
	if (max_v[2] < (unsigned int)tmp->st->st_nlink)
		max_v[2] = (unsigned int)tmp->st->st_nlink;
}

t_lstf		*ft_pre_calc(t_lstf *tmp, unsigned int *max_v)
{
	if (ft_istoshow(tmp) == 1)
	{
		max_v[5] = 1;
		ft_calc_preprint(tmp, max_v);
		ft_calc_maxid(tmp, max_v);
	}
	if (g_option[2])
		tmp = tmp->prev;
	else
		tmp = tmp->next;
	return (tmp);
}
