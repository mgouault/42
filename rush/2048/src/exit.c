/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 21:16:09 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 21:40:25 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

int	exit_prog(t_map **map, char *str)
{
	if (map)
		free_map(map);
	curs_set(1);
	endwin();
	if (*str != 0)
		ft_putendl_fd(str, 2);
	return (0);
}
