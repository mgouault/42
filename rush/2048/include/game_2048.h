/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 20:47:49 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 23:23:12 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include <libft.h>
# include <stdlib.h>
# include <signal.h>
# include <time.h>
# include <curses.h>

enum
{
	UP = 1,
	DOWN,
	LEFT,
	RIGHT
};

enum
{
	WIN_VALUE = 2048
};

typedef struct	s_map
{
	int			value;
	bool		merged;
}				t_map;

typedef struct	s_var
{
	short		x;
	short		y;
	short		col;
	short		lin;
}				t_var;

void			print_map(t_map **map, t_var v, int score);
short			calc_map(t_map **map, int key, int *score);
void			merge(t_map *steady, t_map *moving, bool *action_done);
void			moves(t_map **map, int key, bool *action_done);
short			pop_number(t_map **map);
int				exit_prog(t_map **map, char *str);
void			free_map(t_map **map);
short			count_pow(int n);

#endif
