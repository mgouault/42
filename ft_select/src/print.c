/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:54:49 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/13 22:55:04 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void		print_name(t_lst *link, int x, int y)
{
	tputs(tgoto(tgetstr("cm", NULL), x, y), 0, ret_putchar);
	if (link->selected)
		tputs(tgetstr("mr", NULL), 0, ret_putchar);
	if (link->cursor_on)
		tputs(tgetstr("us", NULL), 0, ret_putchar);
	tputs(link->name, 0, ret_putchar);
	if (link->cursor_on)
		tputs(tgetstr("ue", NULL), 0, ret_putchar);
	if (link->selected)
		tputs(tgetstr("me", NULL), 0, ret_putchar);
	link->x = x;
	link->y = y;
}

static t_var	init_print_var(void)
{
	t_var			v;
	struct winsize	win;

	ioctl(0, TIOCGWINSZ, &win);
	v.lin = (int)win.ws_row - 1;
	v.col = (int)win.ws_col - 1;
	v.link = get_lst(NULL);
	v.x = 0;
	v.y = 0;
	v.max_len = 0;
	tputs(tgetstr("cl", NULL), 0, ret_putchar);
	return (v);
}

void			print_lst(void)
{
	t_var v;

	v = init_print_var();
	while (v.link)
	{
		print_name(v.link, v.x, v.y);
		v.max_len = (v.max_len < v.link->length) ? v.link->length : v.max_len;
		if (v.y + 1 > v.lin)
		{
			v.y = 0;
			v.x += v.max_len + 8;
			v.max_len = 0;
			if (v.x + v.link->length > v.col)
			{
				tputs(tgetstr("cl", NULL), 0, ret_putchar);
				tputs(tgoto(tgetstr("cm", NULL), \
					v.col / 2 - 8, v.lin / 2), 0, ret_putchar);
				tputs("Window too small.", 0, ret_putchar);
				break ;
			}
		}
		else
			v.y += 1;
		v.link = v.link->next;
	}
}
