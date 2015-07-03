/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:53:01 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 23:15:16 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

static t_map	**init_map(int score)
{
	short	x;
	short	y;
	t_map	**map;
	t_var	v;

	if (!(map = (t_map **)malloc(sizeof(t_map *) * 4)))
		return (NULL);
	y = -1;
	while (++y < 4)
	{
		if (!(map[y] = (t_map *)malloc(sizeof(t_map) * 4)))
			return (NULL);
		x = -1;
		while (++x < 4)
		{
			map[y][x].value = 0;
			map[y][x].merged = FALSE;
		}
	}
	if (pop_number(map) == -1)
		return (NULL);
	if (pop_number(map) == -1)
		return (NULL);
	print_map(map, v, score);
	return (map);
}

static int		input_key(int ret)
{
	if (ret == 259)
		return (UP);
	else if (ret == 258)
		return (DOWN);
	else if (ret == 260)
		return (LEFT);
	else if (ret == 261)
		return (RIGHT);
	else
		return (ret);
}

static t_map	**init_prog(int score)
{
	t_map **map;

	if (WIN_VALUE > 3932156 || WIN_VALUE % 2 != 0)
	{
		ft_putendl_fd("game_2048: Error invalid WIN_VALUE.", 2);
		return (NULL);
	}
	if (!initscr())
		return (NULL);
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);
	if (!(map = init_map(score)))
	{
		(void)exit_prog(NULL, "game_2048: Error malloc()");
		return (NULL);
	}
	if (COLS < 48 || LINES < 12)
	{
		(void)exit_prog(map, "game_2048: Window too small. Exiting");
		return (NULL);
	}
	return (map);
}

static short	second_main(short status, int key, t_map **map, int *score)
{
	t_var v;

	if (key == KEY_RESIZE)
		print_map(map, v, *score);
	if ((status == 0 || status == 1) \
		&& (key == UP || key == DOWN || key == LEFT || key == RIGHT))
		if ((status = calc_map(map, key, score)) == -2)
			return (-2);
	if ((status == 1 || status == -1) && (key == KEY_RESIZE ||
		key == UP || key == DOWN || key == LEFT || key == RIGHT))
	{
		if (status == 1)
			mvaddstr((LINES / 6) * 5 + 1, COLS / 2 - 5, "You win!");
		else if (status == -1)
			mvaddstr((LINES / 6) * 5 + 1, COLS / 2 - 5, "You lose!");
		refresh();
	}
	return (status);
}

int				main(void)
{
	short	status;
	int		key;
	int		score;
	t_map	**map;

	status = 0;
	score = 0;
	if (!(map = init_prog(score)))
		return (0);
	while ((key = input_key(getch())) != 27)
	{
		if (COLS < 48 || LINES < 12)
			return (exit_prog(map, "game_2048: Window too small. Exiting"));
		if ((status = second_main(status, key, map, &score)) == -2)
			return (exit_prog(map, "game_2048: Error time()"));
		if (key == 110)
		{
			free_map(map);
			status = 0;
			score = 0;
			if (!(map = init_map(score)))
				return (exit_prog(NULL, "game_2048: Error malloc() or time()"));
		}
	}
	return (exit_prog(map, ""));
}
