/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lst_l_.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 16:57:12 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 20:05:46 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_PWD_H
#define INC_GRP_H
#define INC_SYS_STAT_H
#define INC_SYS_TYPES_H
#define INC_UNISTD_H
#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

static int		ft_do_getmode(t_lstf *tmp)
{
	char	*str_tmp;
	int		islink;

	islink = 0;
	str_tmp = ft_getmode(tmp->st->st_mode);
	if (!str_tmp)
		ft_error("", 1);
	if (str_tmp[0] == 'l')
		islink = 1;
	ft_putstr(str_tmp);
	free(str_tmp);
	ft_putstr("  ");
	return (islink);
}

static void		ft_print_id(t_lstf *tmp, int maxuid, int maxgid)
{
	struct passwd	*pwd;
	struct group	*grp;
	char			*str_tmp;

	if ((pwd = getpwuid(tmp->st->st_uid)) != NULL)
		str_tmp = ft_strdup(pwd->pw_name);
	else
		str_tmp = ft_itoa(tmp->st->st_uid);
	if (g_option[5] == 0)
		ft_print_str(str_tmp, maxuid);
	free(str_tmp);
	if ((grp = getgrgid(tmp->st->st_gid)) != NULL)
		str_tmp = ft_strdup(grp->gr_name);
	else
		str_tmp = ft_itoa(tmp->st->st_gid);
	ft_print_str(str_tmp, maxgid);
	free(str_tmp);
}

static void		ft_printsize(t_lstf *tmp, unsigned int maxsize)
{
	if (S_ISBLK(tmp->st->st_mode) || S_ISCHR(tmp->st->st_mode))
		ft_print_mkdev(major(tmp->st->st_rdev), minor(tmp->st->st_rdev));
	else if (!ft_strcmp(tmp->folder, "dev") || !ft_strcmp(tmp->folder, "fd"))
		ft_print_unit((unsigned int)tmp->st->st_size, 8);
	else
		ft_print_unit((unsigned int)tmp->st->st_size, (int)ft_nbrcnt(maxsize));
}

static void		ft_printname(t_lstf *tmp, int islink)
{
	char *str_tmp;

	ft_putstr(tmp->name);
	if (islink)
	{
		ft_putstr(" -> ");
		if (!ft_strcmp(tmp->folder, "dev") || !ft_strcmp(tmp->folder, "fd"))
		{
			if (!(str_tmp = (char *)malloc(4 + 1)))
				ft_error("", 1);
			islink = readlink(tmp->path, str_tmp, (4 + 1));
		}
		else
		{
			if (!(str_tmp = (char *)malloc(tmp->st->st_size + 1)))
				ft_error("", 1);
			islink = readlink(tmp->path, str_tmp, (tmp->st->st_size + 1));
		}
		if (islink == -1)
			ft_error("", -1);
		str_tmp[islink] = 0;
		ft_putstr(str_tmp);
		free(str_tmp);
	}
	ft_putchar('\n');
}

void			ft_print_lst_l_(t_lstf *tmp, unsigned int *max_v)
{
	int islink;

	islink = ft_do_getmode(tmp);
	ft_print_unit((unsigned int)tmp->st->st_nlink, (int)ft_nbrcnt(max_v[2]));
	ft_print_id(tmp, max_v[3], max_v[4]);
	ft_printsize(tmp, max_v[1]);
	ft_printtime(tmp);
	ft_printname(tmp, islink);
}
