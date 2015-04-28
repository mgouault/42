/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 12:46:59 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/03 20:47:16 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	put_pixel_to_image(t_env *e, int x, int y, int color)
{
	int i;

	i = x * 4 + y * e->size_line;
	e->pimg[i] = (color & 0xFF);
	e->pimg[i + 1] = (color & 0xFF00) >> 8;
	e->pimg[i + 2] = (color & 0xFF0000) >> 16;
}

int		ft_update_img(t_env *e, void to_draw(t_env *e))
{
	e->img = mlx_new_image(e->mlx, S_W, S_H);
	e->pimg = mlx_get_data_addr(e->img, &(e->bpp), &(e->size_line), \
		&(e->endian));
	to_draw(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

void	ft_bzero_double(double *tab, int n)
{
	double *tmp;

	tmp = (double *)tab;
	++n;
	while (--n > 0)
	{
		*tmp = 0;
		++tmp;
	}
}

void	init_sierpinski(float v[8])
{
	v[0] = 10;
	v[1] = S_H - 10;
	v[2] = S_W - 10;
	v[3] = S_H - 10;
	v[4] = S_W / 2;
	v[5] = 10;
	v[6] = v[0];
	v[7] = v[1];
}

int		ft_rand(int seed)
{
	if (seed == 0)
		seed = 1425407431;
	return ((22695477 * seed + 1) % 2147483647);
}
