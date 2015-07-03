/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 15:38:33 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 20:49:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static void	move_up(t_map **map, bool *action_done)
{
	short i;
	short y;
	short x;

	x = 0 - 1;
	while (++x < 4)
	{
		y = 1 - 1;
		while (++y < 4)
		{
			if (map[y][x].value != 0)
			{
				i = y;
				while (i > 0 && map[i - 1][x].value == 0)
				{
					*action_done = TRUE;
					map[i - 1][x].value = map[i][x].value;
					map[i][x].value = 0;
					--i;
				}
				if (i > 0)
					merge(&map[i - 1][x], &map[i][x], action_done);
			}
		}
	}
}

static void	move_down(t_map **map, bool *action_done)
{
	short i;
	short y;
	short x;

	x = 0 - 1;
	while (++x < 4)
	{
		y = 2 + 1;
		while (--y > -1)
		{
			if (map[y][x].value != 0)
			{
				i = y;
				while (i < 3 && map[i + 1][x].value == 0)
				{
					*action_done = TRUE;
					map[i + 1][x].value = map[i][x].value;
					map[i][x].value = 0;
					++i;
				}
				if (i < 3)
					merge(&map[i + 1][x], &map[i][x], action_done);
			}
		}
	}
}

static void	move_left(t_map **map, bool *action_done)
{
	short i;
	short y;
	short x;

	y = 0 - 1;
	while (++y < 4)
	{
		x = 1 - 1;
		while (++x < 4)
		{
			if (map[y][x].value != 0)
			{
				i = x;
				while (i > 0 && map[y][i - 1].value == 0)
				{
					*action_done = TRUE;
					map[y][i - 1].value = map[y][i].value;
					map[y][i].value = 0;
					--i;
				}
				if (i > 0)
					merge(&map[y][i - 1], &map[y][i], action_done);
			}
		}
	}
}

static void	move_right(t_map **map, bool *action_done)
{
	short i;
	short y;
	short x;

	y = 0 - 1;
	while (++y < 4)
	{
		x = 2 + 1;
		while (--x > -1)
		{
			if (map[y][x].value != 0)
			{
				i = x;
				while (i < 3 && map[y][i + 1].value == 0)
				{
					*action_done = TRUE;
					map[y][i + 1].value = map[y][i].value;
					map[y][i].value = 0;
					++i;
				}
				if (i < 3)
					merge(&map[y][i + 1], &map[y][i], action_done);
			}
		}
	}
}

void		moves(t_map **map, int key, bool *action_done)
{
	if (key == UP)
		move_up(map, action_done);
	if (key == DOWN)
		move_down(map, action_done);
	if (key == LEFT)
		move_left(map, action_done);
	if (key == RIGHT)
		move_right(map, action_done);
}
