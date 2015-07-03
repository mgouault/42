/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 22:54:13 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:53:25 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char			**to_up(char **line, char ***tmp, t_var *v, t_line **history)
{
	if (!*tmp)
		*tmp = line;
	else if (*tmp && (*history)->prev)
		*history = (*history)->prev;
	line = &((*history)->line);
	erase_n_print(v, *line);
	return (line);
}

char			**to_down(char **line, char ***tmp, t_var *v, t_line **history)
{
	if ((*history)->next)
	{
		*history = (*history)->next;
		line = &((*history)->line);
	}
	else if (!(*history)->next && *tmp)
	{
		line = *tmp;
		*tmp = NULL;
	}
	erase_n_print(v, *line);
	return (line);
}

void			to_left(t_var *v)
{
	short col;

	col = getsing_col(-1);
	v->cursor--;
	if (v->cursor % col == 0 && v->cursor >= col)
	{
		tputs(tgetstr("up", NULL), 0, ret_putchar);
		tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
	}
	else
		tputs(tgetstr("le", NULL), 0, ret_putchar);
}

void			to_right(t_var *v)
{
	short col;

	col = getsing_col(-1);
	if (v->cursor % col == 0)
		tputs(tgetstr("do", NULL), 0, ret_putchar);
	else
		tputs(tgetstr("nd", NULL), 0, ret_putchar);
	v->cursor++;
}

void			do_clear(t_var *v, char **line)
{
	int		i;
	short	col;

	col = getsing_col(-1);
	tputs(tgetstr("cl", NULL), 0, ret_putchar);
	tputs(tgetstr("sc", NULL), 0, ret_putchar);
	i = prompt();
	i += ft_strlen(*line);
	ft_putstr(*line);
	while (i > v->cursor)
	{
		i--;
		if (i % col == 0 && i >= col)
		{
			tputs(tgetstr("up", NULL), 0, ret_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, col), 0, ret_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 0, ret_putchar);
	}
}
