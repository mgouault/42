/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/22 23:20:23 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:50:05 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

t_line			*update_history(t_line *history, char *line)
{
	t_line	*cmd;
	int		i;

	i = 0;
	while (line && (line[i] || line[0] == 0))
	{
		if (line[i] != 0 && line[i] != ' ' && line[i] != '\t')
			break ;
		if (line[0] == 0 || line[i + 1] == 0)
			return (history);
		i++;
	}
	while (history && history->next)
		history = history->next;
	cmd = (t_line *)ft_memalloc(sizeof(t_line));
	cmd->line = ft_strdup(line);
	cmd->prev = history;
	cmd->next = NULL;
	if (history)
		history->next = cmd;
	else
		history = cmd;
	while (history && history->prev)
		history = history->prev;
	return (history);
}

t_line			*history_dup(t_line *history)
{
	t_line *new;
	t_line *prev;
	t_line **next;

	prev = NULL;
	next = NULL;
	new = NULL;
	while (history)
	{
		new = (t_line *)ft_memalloc(sizeof(t_line));
		new->line = ft_strdup(history->line);
		new->prev = prev;
		prev = new;
		if (next)
			*next = new;
		next = &(new->next);
		history = history->next;
	}
	if (next)
		*next = NULL;
	return (new);
}

void			endline(short cursor)
{
	int		i;
	int		n;
	short	col;

	col = getsing_col(-1);
	i = -1;
	n = (cursor / col) + 1;
	while (++i < n)
		tputs(tgetstr("do", NULL), 0, ret_putchar);
}

static short	gekie_(char *b)
{
	if (b[0] == 27 && b[1] == 91 && \
		(b[2] == 51 || b[2] == 53 || b[2] == 54) && b[3] == 126 && b[4] == 0)
		return (K_TILDE);
	else if (b[0] == 12 && b[1] == 0)
		return (K_CLEAR);
	else if (b[0] == 4 && b[1] == 0)
		return (K_EOF);
	else if (b[0] == 27 && b[1] == 27 && b[2] == 91 && \
		b[3] >= 65 && b[3] <= 68 && b[4] == 0)
		return (K_PUTE);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 49 && \
		b[3] == 59 && b[4] == 50 && b[5] >= 65 && b[5] <= 68 && b[6] == 0)
		return (K_PUTE);
	else
		return (K_NONE);
}

short			gekie(char *b)
{
	if (b[0] == 9 && b[1] == 0)
		return (K_TAB);
	else if (b[0] == 10 && b[1] == 0)
		return (K_ENTER);
	else if (b[0] == 127 && b[1] == 0)
		return (K_DELETE);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 72 && b[3] == 0)
		return (K_HOME);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 70 && b[3] == 0)
		return (K_END);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 65 && b[3] == 0)
		return (K_UP);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 66 && b[3] == 0)
		return (K_DOWN);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 68 && b[3] == 0)
		return (K_LEFT);
	else if (b[0] == 27 && b[1] == 91 && b[2] == 67 && b[3] == 0)
		return (K_RIGHT);
	else
		return (gekie_(b));
}
