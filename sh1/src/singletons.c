/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/15 17:06:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:02:04 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static t_pid	*getsing_pidpile_(t_pid **actual_pile, t_bool use, int search)
{
	t_pid *next;
	t_pid *ret;

	if ((*actual_pile)->pid == search)
	{
		ret = *actual_pile;
		if (use)
			*actual_pile = (*actual_pile)->next;
		return (ret);
	}
	next = *actual_pile;
	while (next && next->next && next->next->pid != search)
		next = next->next;
	if (next->next)
	{
		ret = next->next;
		if (use)
			next->next = next->next->next;
	}
	else
		return (NULL);
	return (ret);
}

t_pid			*getsing_pidpile(int pid, char *cmd, t_bool use, int search)
{
	static t_pid	*actual_pile = NULL;
	t_pid			*tmp;
	t_pid			*ret;

	if (pid > -1)
	{
		tmp = (t_pid *)ft_memalloc(sizeof(t_pid));
		tmp->pid = pid;
		tmp->next = actual_pile;
		tmp->cmd = ft_strdup(cmd);
		actual_pile = tmp;
	}
	if (!actual_pile)
		return (NULL);
	if (search > -1)
		ret = getsing_pidpile_(&actual_pile, use, search);
	else
	{
		ret = actual_pile;
		if (use)
			actual_pile = actual_pile->next;
	}
	return (ret);
}

short			getsing_cursor(short cursor)
{
	static short	actual_cursor = -1;

	if (cursor > -1)
		actual_cursor = cursor;
	return (actual_cursor);
}

char			*getsing_line(char *line)
{
	static char		*actual_line = NULL;

	if (line)
		actual_line = line;
	return (actual_line);
}

short			getsing_col(short col)
{
	static short	actual_col = -1;

	if (col > -1)
		actual_col = col;
	return (actual_col);
}
