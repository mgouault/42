/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:25:02 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/01 23:33:26 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static void		echo_putnbr(int n)
{
	if (n / 10 != 0)
		echo_putnbr(n / 10);
	addch((n % 10) + '0');
}

static void		movecursor_number(t_var v, int number)
{
	move(((((v.y + 2) * v.lin) - ((v.y + 1) * v.lin)) / 2) + \
		((v.y + 1) * v.lin), \
		((((v.x + 2) * v.col) - ((v.x + 1) * v.col)) / 2) + \
		((v.x + 1) * v.col) - count_pow(number));
	if (number != 0)
		echo_putnbr(number);
}

static void		draw_lines(t_var v)
{
	if (v.x == 3)
	{
		mvvline((v.y + 1) * v.lin, (v.x + 2) * v.col, '|', \
			((v.y + 2) * v.lin) - ((v.y + 1) * v.lin));
		mvaddch((v.y + 1) * v.lin, (v.x + 2) * v.col, '+');
	}
	if (v.y == 3)
	{
		mvhline((v.y + 2) * v.lin, (v.x + 1) * v.col, '-', \
			((v.x + 2) * v.col) - ((v.x + 1) * v.col));
		mvaddch((v.y + 2) * v.lin, (v.x + 1) * v.col, '+');
	}
}

static void		print_stuff(int score)
{
	mvaddstr((LINES / 9), (COLS / 7), "Press N for new game");
	mvaddstr((LINES / 9), (COLS / 7) * 4 + 4, "Score:");
	move((LINES / 9), (COLS / 7) * 4 + 12);
	echo_putnbr(score);
	mvaddstr((LINES / 6) * 5 + 1, (COLS / 7) * 4 + 4, "Goal:");
	move((LINES / 6) * 5 + 1, (COLS / 7) * 4 + 10);
	echo_putnbr(WIN_VALUE);
}

void			print_map(t_map **map, t_var v, int score)
{
	clear();
	v.col = COLS / 6;
	v.lin = LINES / 6;
	v.y = -1;
	while (++v.y < 4)
	{
		v.x = -1;
		while (++v.x < 4)
		{
			movecursor_number(v, map[v.y][v.x].value);
			mvvline((v.y + 1) * v.lin, (v.x + 1) * v.col, '|', \
				((v.y + 2) * v.lin) - ((v.y + 1) * v.lin));
			mvhline((v.y + 1) * v.lin, (v.x + 1) * v.col, '-', \
				((v.x + 2) * v.col) - ((v.x + 1) * v.col));
			mvaddch((v.y + 1) * v.lin, (v.x + 1) * v.col, '+');
			draw_lines(v);
		}
	}
	mvaddch(5 * v.lin, 5 * v.col, '+');
	print_stuff(score);
	refresh();
}
