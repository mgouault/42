/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/17 19:36:12 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:31:05 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void resize(int sig)
{
	t_win	win;
	short	i;
	short	end;
	short	col;
	char	*line;

	ioctl(0, TIOCGWINSZ, &win);
	col = (short)win.ws_col;
	getsing_col(col);
	tputs(tgetstr("rc", NULL), 0, ret_putchar);
	tputs(tgetstr("cd", NULL), 0, ret_putchar);
	end = prompt();
	line = getsing_line(NULL);
	ft_putstr(line);
	end += ft_strlen(line) + 1;
	i = getsing_cursor(-1);
	while (--end > i)
		if (end % col == 0 && end >= col)
		{
			tputs(tgetstr("up", NULL), 0, ret_putchar);
			tputs(tgoto(tgetstr("ch", NULL), 0, end), 0, ret_putchar);
		}
		else
			tputs(tgetstr("le", NULL), 0, ret_putchar);
	(void)sig;
}

void catch_sigint(int sig)
{
	(void)sig;
}
