/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/21 19:53:18 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:51:45 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_DIRENT_H
#define INC_SYS_STAT_H
#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

extern int *g_option;

void			ft_readonedir(char *path)
{
	DIR		*op;
	t_lstf	*start;

	if ((op = opendir(path)) == NULL)
		ft_error(path, 0);
	else
	{
		start = ft_crt_lst(op, path, NULL, NULL);
		if (closedir(op) == -1)
			ft_error("", 1);
		if (start)
		{
			start = ft_sort_lst(start, 0);
			if (g_option[0])
				ft_print_lst_l(start, 0);
			else
				ft_print_lst(start);
		}
	}
}

static t_lstf	*ft_readfiles(t_lstf *start)
{
	t_lstf	*tmp1;
	t_lstf	*tmp2;

	tmp1 = start;
	while ((tmp1->next != NULL) && (S_ISDIR(tmp1->next->st->st_mode) == 0))
		tmp1 = tmp1->next;
	tmp2 = tmp1->next;
	tmp1->next = NULL;
	if (g_option[0])
		ft_print_lst_l(start, 1);
	else
		ft_print_lst(start);
	start = tmp2;
	if (start)
		ft_putchar('\n');
	return (start);
}

void			ft_if_input(t_lstf *input, int many_folders)
{
	input = ft_sort_lst(input, 0);
	input = ft_sort_lst(input, 1);
	if (input->next)
		many_folders = 1;
	while (input)
	{
		if (S_ISDIR(input->st->st_mode) == 1)
		{
			if (many_folders)
			{
				ft_putstr(input->name);
				ft_putstr(":\n");
			}
			ft_readonedir(input->name);
			if (many_folders && input->next)
				ft_putchar('\n');
			input = input->next;
		}
		else
			input = ft_readfiles(input);
	}
}

static void		ft_putpath_rcsv(t_lstf *input)
{
	char	*tmp;
	int		i;

	if (ft_strchr(input->path, '/'))
	{
		i = ft_i_strrchr(input->path, '/');
		++i;
		tmp = ft_strsub(input->path, i, (ft_strlen(input->path) - i));
	}
	else
		tmp = ft_strdup(input->path);
	if (!tmp)
		ft_error("", 1);
	if ((g_option[1] == 1) || (tmp[0] != '.'))
	{
		ft_putstr(input->path);
		ft_putstr(":\n");
	}
	free(tmp);
}

void			ft_rcsv_lst(t_lstf *input)
{
	DIR		*op;
	t_lstf	*start;

	ft_putpath_rcsv(input);
	if ((op = opendir(input->path)) == NULL)
		ft_error(input->path, 0);
	else
	{
		start = ft_crt_lst(op, input->path, NULL, NULL);
		if (closedir(op) == -1)
			ft_error("", 1);
		if (start)
		{
			start = ft_sort_lst(start, 0);
			if (g_option[0])
				ft_print_lst_l(start, 0);
			else
				ft_print_lst(start);
		}
	}
}
