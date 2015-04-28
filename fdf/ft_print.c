/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 23:22:16 by mgouault          #+#    #+#             */
/*   Updated: 2015/01/03 19:54:11 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		ft_get_color(int z, int color_map)
{
	if (color_map == 1)
	{
		if (z <= 0)
			return (0x0033FF);
		else if ((z > 0) && (z <= 1))
			return (0xFFFF99);
		else if ((z > 1) && (z <= 30))
			return (0x009966);
		else if ((z > 30) && (z <= 70))
			return (0x5B4B00);
		else if (z > 70)
			return (0xFFFFFF);
		else
			return (0);
	}
	else if (color_map == 2)
		return (0x00CC66 + (0x00FF00 * z));
	return (0xFFFFFF);
}

static void		ft_fill_int_v(t_env *e, t_val pos, int *v)
{
	v[6] = pos.x0 * e->space_x;
	v[8] = pos.y0 * e->space_y;
	v[7] = pos.x1 * e->space_x;
	v[9] = pos.y1 * e->space_y;
	v[0] = abs(v[7] - v[6]);
	v[2] = v[6] < v[7] ? 1 : -1;
	v[1] = abs(v[9] - v[8]);
	v[3] = v[8] < v[9] ? 1 : -1;
	v[4] = (v[0] > v[1] ? v[0] : -v[1]) / 2;
}

static void		ft_draw_line(t_env *e, t_val pos, int *v)
{
	if (!v)
		ft_error();
	ft_fill_int_v(e, pos, v);
	while (1)
	{
		if ((v[6] + e->o_x) >= 0 && (v[6] + e->o_x) <= e->screen_width &&
			(v[8] + e->o_y) >= 0 && (v[8] + e->o_y) <= e->screen_height)
			mlx_pixel_put(e->mlx, e->win, (v[6] + e->o_x), (v[8] + e->o_y),
				ft_get_color(pos.z, e->color_map));
		if ((v[6] == v[7]) && (v[8] == v[9]))
			break ;
		v[5] = v[4];
		if (v[5] > -v[0])
			v[4] -= v[1];
		if (v[5] > -v[0])
			v[6] += v[2];
		if (v[5] < v[1])
			v[4] += v[0];
		if (v[5] < v[1])
			v[8] += v[3];
	}
	free(v);
}

static void		ft_print_ls_(t_env *e, t_val pos, int x, int y)
{
	pos.x0 = x - y;
	pos.y0 = (x + y) - (int)(e->map[y].tab[x] * e->z);
	pos.z = e->map[y].tab[x];
	if ((x + 1) < e->map[y].length)
	{
		pos.x1 = (x + 1) - y;
		pos.y1 = ((x + 1) + y) - (int)(e->map[y].tab[x + 1] * e->z);
		ft_draw_line(e, pos, (int *)ft_memalloc(sizeof(int) * 10));
	}
	if ((e->map[y + 1].tab != NULL) && (x < e->map[y + 1].length))
	{
		pos.x1 = x - (y + 1);
		pos.y1 = (x + (y + 1)) - (int)(e->map[y + 1].tab[x] * e->z);
		ft_draw_line(e, pos, (int *)ft_memalloc(sizeof(int) * 10));
	}
}

void			ft_print_ls(t_env *e)
{
	int		y;
	int		x;
	t_val	pos;

	y = 0;
	while (e->map[y].tab != NULL)
	{
		x = 0;
		while (x < e->map[y].length)
		{
			ft_print_ls_(e, pos, x, y);
			++x;
		}
		++y;
	}
}
