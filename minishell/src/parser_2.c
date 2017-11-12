/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 23:20:12 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:49:33 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void		reprint_line_(int i, t_var *v, short col)
{
	while (i > 1)
	{
		if ((i + v->cursor) % col == 1 && (i + v->cursor) > col)
		{
			tputs(tgetstr("up", NULL), 0, ret_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 0, ret_putchar);
		i--;
	}
}

static void		reprint_line(char *line, t_var *v)
{
	short	col;
	short	pos;
	int		i;

	tputs(tgetstr("ce", NULL), 0, ret_putchar);
	tputs(tgetstr("cd", NULL), 0, ret_putchar);
	col = getsing_col(-1);
	pos = v->cursor - v->begin;
	i = 0;
	while (line[pos + i])
	{
		ft_putchar(line[pos + i]);
		i++;
		if ((v->cursor + i - 1) % col == 0)
			tputs(tgetstr("do", NULL), 0, ret_putchar);
	}
	reprint_line_(i, v, col);
}

void			print_char(char **line, char *b, t_var *v, short pos)
{
	char	*tmp;
	char	*tmp2;
	short	col;

	col = getsing_col(-1);
	if (v->cursor == v->end)
	{
		tmp = *line;
		*line = ft_strjoin(*line, b);
	}
	else
	{
		tmp = ft_strsub(*line, 0, pos);
		tmp2 = ft_strsub(*line, pos, ft_strlen(*line) - pos);
		free(*line);
		*line = ft_bigjoin("%s%s%s", tmp, b, tmp2);
		free(tmp2);
	}
	free(tmp);
	reprint_line(*line, v);
	v->cursor++;
	v->end++;
}

static void		delete_char_(t_var *v, short col, char **line)
{
	if (v->cursor % col == 0 && v->cursor >= col)
	{
		tputs(tgetstr("up", NULL), 0, ret_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
	}
	else
		tputs(tgetstr("le", NULL), 0, ret_putchar);
	reprint_line(*line, v);
	if (v->cursor != v->end)
	{
		if (v->cursor % col == 0 && v->cursor >= col)
		{
			tputs(tgetstr("up", NULL), 0, ret_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 0, ret_putchar);
	}
}

void			delete_char(char **line, t_var *v, short pos)
{
	char	*tmp;
	char	*tmp2;
	short	col;

	col = getsing_col(-1);
	if (v->cursor == v->end)
	{
		tmp = *line;
		*line = ft_strsub(*line, 0, ft_strlen(*line) - 1);
	}
	else
	{
		tmp = ft_strsub(*line, 0, pos - 1);
		tmp2 = ft_strsub(*line, pos, ft_strlen(*line) - pos);
		free(*line);
		*line = ft_strjoin(tmp, tmp2);
		free(tmp2);
	}
	free(tmp);
	v->cursor--;
	v->end--;
	delete_char_(v, col, line);
}
