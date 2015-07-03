/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:28:50 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 22:18:22 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static short	count_free_cases(t_map **map)
{
	short free_cases;
	short x;
	short y;

	free_cases = 0;
	y = 0;
	while (y < 4)
	{
		x = 0;
		while (x < 4)
		{
			if (map[y][x].value == 0)
				++free_cases;
			++x;
		}
		++y;
	}
	if (free_cases == 1)
		return (2);
	return (free_cases);
}

short			pop_number(t_map **map)
{
	short	free_cases;
	short	random_case;
	short	x;
	short	y;
	time_t	var_time;

	free_cases = count_free_cases(map);
	if ((var_time = time(NULL)) == -1)
		return (-1);
	srand(var_time);
	random_case = rand() % free_cases;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (map[y][x].value == 0)
			{
				if (random_case == 0)
					map[y][x].value = ((rand() + x + y) % 10) < 9 ? 2 : 4;
				--random_case;
			}
	}
	return (0);
}
