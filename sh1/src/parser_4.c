/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 22:54:13 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:12:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void	lama_(char *sub, t_var *v, char **line)
{
	char	b[2];
	int		i;

	i = 0;
	while (sub && sub[i])
	{
		b[0] = sub[i];
		b[1] = 0;
		print_char(line, b, v, v->cursor - v->begin);
		i++;
	}
	if (sub)
		free(sub);
}

static void	lama(DIR *od, t_chur chur, t_var *v, char **line)
{
	struct dirent	*rd;
	struct stat		st;
	char			*sub;
	short			col;

	col = getsing_col(-1);
	sub = NULL;
	if (chur.dir[ft_strlen(chur.dir) - 1] != '/' && \
		stat(chur.dir, &st) == 0 && S_ISDIR(st.st_mode))
		sub = ft_strdup("/");
	else
	{
		while ((rd = readdir(od)))
		{
			if (ft_strnstr(rd->d_name, chur.tmp, ft_strlen(chur.tmp)) && \
				((rd->d_name[0] != '.' && chur.tmp[0] != '.') || \
					(rd->d_name[0] == '.' && chur.tmp[0] == '.')))
			{
				sub = ft_strsub(rd->d_name, ft_strlen(chur.tmp), \
					ft_strlen(rd->d_name) - ft_strlen(chur.tmp));
				break ;
			}
		}
	}
	lama_(sub, v, line);
}

static void	completion_(int i, int j, t_var *v, char **line)
{
	DIR		*od;
	t_chur	chur;

	chur.dir = NULL;
	if (j > 0)
	{
		chur.dir = ft_strsub(*line, i + 1, j - i);
		chur.tmp = ft_strsub(*line, j + 1, v->cursor - j);
		od = opendir(chur.dir);
		free(chur.dir);
	}
	else
	{
		chur.tmp = ft_strsub(*line, i + 1, v->cursor - i);
		od = opendir(".");
	}
	chur.dir = ft_strsub(*line, i + 1, v->cursor - i);
	if (od)
		lama(od, chur, v, line);
	if (od && closedir(od) == -1)
		error_exit("closedir error");
	free(chur.dir);
	free(chur.tmp);
}

void		completion(char **line, t_var *v)
{
	int i;
	int j;

	i = v->cursor - v->begin;
	j = i;
	while (i > 0 && (*line)[i] != ' ')
		i--;
	if (i == 0)
		return ;
	while (j > 0 && (*line)[j] != '/')
		j--;
	completion_(i, j, v, line);
}

void		erase_n_print(t_var *v, char *line)
{
	short col;

	col = getsing_col(-1);
	while (v->cursor > v->begin)
	{
		v->cursor--;
		if (v->cursor % col == 0 && v->cursor >= col)
		{
			tputs(tgetstr("up", NULL), 0, ret_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 0, ret_putchar);
	}
	tputs(tgetstr("ce", NULL), 0, ret_putchar);
	ft_putstr(line);
	v->cursor += ft_strlen(line);
	v->end = v->cursor;
}
