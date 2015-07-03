/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 14:22:50 by avanhoeg          #+#    #+#             */
/*   Updated: 2015/03/01 23:10:20 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static bool		check_defeat(t_map **map, short x, short y)
{
	bool	action_done;
	t_map	**fake_map;

	if (!(fake_map = (t_map **)malloc(sizeof(t_map *) * 4)))
		return (NULL);
	while (++y < 4)
	{
		if (!(fake_map[y] = (t_map *)malloc(sizeof(t_map) * 4)))
			return (NULL);
		x = -1;
		while (++x < 4)
		{
			fake_map[y][x].value = map[y][x].value;
			fake_map[y][x].merged = map[y][x].merged;
		}
	}
	action_done = FALSE;
	moves(fake_map, UP, &action_done);
	moves(fake_map, DOWN, &action_done);
	moves(fake_map, LEFT, &action_done);
	moves(fake_map, RIGHT, &action_done);
	free_map(fake_map);
	if (action_done)
		return (FALSE);
	return (TRUE);
}

static short	check_status(t_map **map, int *score)
{
	short	y;
	short	x;
	bool	status;

	status = TRUE;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (map[y][x].merged)
				*score += map[y][x].value;
			if (map[y][x].value == 0)
				status = FALSE;
		}
	}
	status = (!status) ? FALSE : check_defeat(map, -1, -1);
	if (*score >= WIN_VALUE)
		return (1);
	else if (status)
		return (-1);
	return (0);
}

static void		reinit_merge(t_map **map)
{
	short y;
	short x;

	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			map[y][x].merged = FALSE;
			++x;
		}
		++y;
	}
}

short			calc_map(t_map **map, int key, int *score)
{
	bool	action_done;
	short	status;
	t_var	v;

	action_done = FALSE;
	moves(map, key, &action_done);
	if (action_done)
	{
		if (pop_number(map) == -1)
			return (-2);
		print_map(map, v, *score);
	}
	status = check_status(map, score);
	reinit_merge(map);
	return (status);
}
