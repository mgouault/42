/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 20:29:32 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/13 22:46:21 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		stop_enter(t_lst *link)
{
	int		notfirst;

	notfirst = 0;
	while (link->prev)
		link = link->prev;
	while (link)
	{
		if (link->selected)
		{
			if (notfirst)
				ft_putchar_fd(' ', 1);
			ft_putstr_fd(link->name, 1);
			notfirst = 1;
		}
		link = link->next;
	}
	proper_exit(get_lst(NULL));
}

static t_lst	*get_next(t_lst *link, short key)
{
	t_lst *next;

	link->cursor_on = FALSE;
	if (key == K_UP)
		next = (link->prev) ? link->prev : link->loop;
	else if (key == K_DELETE)
		next = (link->next) ? link->next : link->prev;
	else
		next = (link->next) ? link->next : link->loop;
	if (next)
		next->cursor_on = TRUE;
	return (next);
}

static t_lst	*stuff_actions(t_lst *link, int key)
{
	t_lst	*next;

	if (key == K_SPACE)
		link->selected = (link->selected) ? FALSE : TRUE;
	else if (key == K_DELETE)
		delete_link(link);
	next = get_next(link, key);
	if (key == K_DELETE)
		(void)get_lst(next);
	print_lst();
	return (next);
}

static short	get_read(void)
{
	char	buf[7];
	int		ret;
	short	key;

	ft_bzero(buf, 7);
	ret = read(0, buf, 7);
	buf[ret] = 0;
	(void)get_buf(buf);
	key = get_key(buf);
	return (key);
}

void			wait_for_read(void)
{
	t_lst	*link;
	short	key;
	char	*search;

	search = NULL;
	link = get_lst(NULL);
	while (link->cursor_on != TRUE)
		link = (!link->next) ? link->loop : link->next;
	while (42)
	{
		key = get_read();
		if (key == K_ENTER)
			stop_enter(link);
		else if (key == K_ESCAPE)
			proper_exit(link);
		else if (key == K_SPACE || key == K_UP || key == K_DOWN || \
			key == K_DELETE)
			link = stuff_actions(link, key);
		else if (key == K_PAGE_DOWN || key == K_PAGE_UP)
			select_all(key);
		if (key == VALID_SEARCH)
			link = dynamic_search(&search, link);
		else if ((key == K_END || key != VALID_SEARCH) && search)
			free(search), search = NULL;
	}
}
