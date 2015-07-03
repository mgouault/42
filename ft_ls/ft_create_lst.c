/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_lst.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 19:52:58 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:47:01 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_DIRENT_H
#define INC_SYS_STAT_H
#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

static char		*ft_makepath(char *name, char *path)
{
	char *tmp;
	char *tmp2;

	if (path[0] == 0)
	{
		if ((name[0] == '/') || (name[0] == '~'))
			tmp = ft_strdup(name);
		else
			tmp = ft_strjoin("./", name);
	}
	else
	{
		if ((path[0] == '/') && (path[1] == 0))
			tmp2 = ft_strdup("/");
		else
			tmp2 = ft_strjoin(path, "/");
		if (!tmp2)
			ft_error("", 1);
		tmp = ft_strjoin(tmp2, name);
		free(tmp2);
	}
	if (!tmp)
		ft_error("", 1);
	return (tmp);
}

static t_lstf	*ft_fill_lstf_(t_lstf *tmp, t_stat *addr)
{
	t_stat			*tmpstat;
	int				err;

	if (g_option[0] == 1)
		err = lstat(tmp->path, addr);
	else if ((g_option[0] == 0) && (g_option[4] == 0))
		err = stat(tmp->path, addr);
	else if ((g_option[0] == 0) && (g_option[4] == 1))
	{
		err = stat(tmp->path, addr);
		if (err == -1)
			return (ft_error_null(tmp->path));
		tmpstat = (t_stat *)malloc(sizeof(t_stat));
		err = lstat(tmp->path, tmpstat);
		if (err == -1)
			return (ft_error_null(tmp->path));
		addr->st_mtime = tmpstat->st_mtime;
		free(tmpstat);
	}
	if (err == -1)
		return (ft_error_null(tmp->path));
	tmp->st = addr;
	tmp->prev = NULL;
	tmp->next = NULL;
	return (tmp);
}

static t_lstf	*ft_fill_lstf(char *name, char *path)
{
	t_lstf			*tmp;
	t_stat			*addr;
	int				i;

	tmp = (t_lstf *)malloc(sizeof(t_lstf));
	addr = (t_stat *)malloc(sizeof(t_stat));
	if (!tmp || !addr)
		ft_error("", 1);
	if (!name)
		name = ".";
	if (name[0] == 0)
		ft_error_fts_open();
	tmp->name = ft_strdup(name);
	if (ft_strchr(path, '/'))
	{
		i = ft_i_strrchr(path, '/');
		++i;
		tmp->folder = ft_strsub(path, i, (ft_strlen(path) - i));
	}
	else
		tmp->folder = ft_strdup(".");
	tmp->path = ft_makepath(name, path);
	return (ft_fill_lstf_(tmp, addr));
}

t_lstf			*ft_crt_avlst(int *dir, char **av, t_lstf *begin, t_lstf *prev)
{
	t_lstf			*ptr;
	t_lstf			**next;
	int				i;

	i = 0;
	next = NULL;
	while (dir[i] > 0)
	{
		ptr = ft_fill_lstf(av[dir[i]], "");
		if (ptr != NULL)
		{
			ptr->prev = prev;
			prev = ptr;
			if (begin == NULL)
				begin = ptr;
			if (next != NULL)
				*next = ptr;
			next = &ptr->next;
		}
		++i;
	}
	free(dir);
	if (next != NULL)
		*next = NULL;
	return (begin);
}

t_lstf			*ft_crt_lst(DIR *op, char *path, t_lstf *begin, t_lstf *prev)
{
	t_lstf			*ptr;
	t_lstf			**next;
	struct dirent	*rp;

	next = NULL;
	while ((rp = readdir(op)) != NULL)
	{
		if ((g_option[1] == 1) || (rp->d_name[0] != '.') ||
			((g_option[3] == 1) && (ft_notadotlink(rp->d_name) == 1)))
		{
			ptr = ft_fill_lstf(rp->d_name, path);
			if (ptr == NULL)
				break ;
			ptr->prev = prev;
			prev = ptr;
			if (begin == NULL)
				begin = ptr;
			if (next != NULL)
				*next = ptr;
			next = &ptr->next;
		}
	}
	if (next != NULL)
		*next = NULL;
	return (begin);
}
