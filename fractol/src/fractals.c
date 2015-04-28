/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 19:53:29 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/03 22:54:42 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

void	draw_mandelbrot(t_env *e)
{
	double	v[6];
	int		i[3];

	i[1] = -1;
	while (++i[1] < S_W)
	{
		i[2] = -1;
		while (++i[2] < S_H)
		{
			v[0] = 1.5 * (i[1] - S_W / 2) / (0.5 * e->zoom * S_W) + e->move_x;
			v[1] = (i[2] - S_H / 2) / (0.5 * e->zoom * S_H) + e->move_y;
			ft_bzero_double(&(v[2]), 4);
			i[0] = -1;
			while (++i[0] < e->max_i)
			{
				v[4] = v[2];
				v[5] = v[3];
				v[2] = v[4] * v[4] - v[5] * v[5] + v[0];
				v[3] = 2 * v[4] * v[5] + v[1];
				if ((v[2] * v[2] + v[3] * v[3]) > e->max_l)
					break ;
			}
			put_pixel_to_image(e, i[1], i[2], pow(i[0], e->color_coeff));
		}
	}
}

void	draw_julia(t_env *e)
{
	double	v[4];
	int		i[3];

	i[1] = -1;
	while (++i[1] < S_W)
	{
		i[2] = -1;
		while (++i[2] < S_H)
		{
			v[0] = 1.5 * (i[1] - S_W / 2) / (0.5 * e->zoom * S_W) + e->move_x;
			v[1] = (i[2] - S_H / 2) / (0.5 * e->zoom * S_H) + e->move_y;
			i[0] = -1;
			while (++i[0] < e->max_i)
			{
				v[2] = v[0];
				v[3] = v[1];
				v[0] = v[2] * v[2] - v[3] * v[3] + e->c1;
				v[1] = 2 * v[2] * v[3] + e->c2;
				if ((v[0] * v[0] + v[1] * v[1]) > e->max_l)
					break ;
			}
			put_pixel_to_image(e, i[1], i[2], pow(i[0], e->color_coeff));
		}
	}
}

void	draw_ship(t_env *e)
{
	double	v[6];
	int		i[3];

	i[1] = -1;
	while (++i[1] < S_W)
	{
		i[2] = -1;
		while (++i[2] < S_H)
		{
			v[0] = 1.5 * (i[1] - S_W / 2) / (0.5 * e->zoom * S_W) + e->move_x;
			v[1] = (i[2] - S_H / 2) / (0.5 * e->zoom * S_H) + e->move_y;
			ft_bzero_double(&(v[2]), 4);
			i[0] = -1;
			while (++i[0] < e->max_i)
			{
				v[4] = v[2];
				v[5] = v[3];
				v[2] = v[4] * v[4] - v[5] * v[5] + v[0];
				v[3] = 2 * fabs(v[4]) * fabs(v[5]) + v[1];
				if ((v[2] * v[2] + v[3] * v[3]) > e->max_l)
					break ;
			}
			put_pixel_to_image(e, i[1], i[2], pow(i[0], e->color_coeff));
		}
	}
}

void	draw_modulo(t_env *e)
{
	int i[5];

	i[0] = 0;
	while (i[0] < S_W)
	{
		i[1] = 0;
		while (i[1] < S_H)
		{
			i[5] = 1;
			i[3] = 0;
			i[4] = e->mod_n;
			while (i[3] < e->max_r)
			{
				if (!((i[0] / i[5]) % 3 == 1 && (i[1] / i[5]) % 3 == 1))
					++i[4];
				i[5] *= 3;
				++i[3];
			}
			if (i[4] == e->max_r)
				put_pixel_to_image(e, i[0], i[1], 0xFFFFFF);
			++i[1];
		}
		++i[0];
	}
}

void	draw_sierpinski(t_env *e)
{
	float	v[8];
	int		i[2];

	init_sierpinski(v);
	i[0] = -1;
	i[1] = 0;
	while (++i[0] < e->max_i * 80)
	{
		put_pixel_to_image(e, v[6], v[7], 0xFFFFFF), i[1] = ft_rand(i[1]);
		if (abs(i[1] % 3) == 0)
		{
			v[6] = (v[6] + v[0]) / 2.0;
			v[7] = (v[7] + v[1]) / 2.0;
		}
		else if (abs(i[1] % 3) == 1)
		{
			v[6] = (v[6] + v[2]) / 2.0;
			v[7] = (v[7] + v[3]) / 2.0;
		}
		else if (abs(i[1] % 3) == 2)
		{
			v[6] = (v[6] + v[4]) / 2.0;
			v[7] = (v[7] + v[5]) / 2.0;
		}
	}
}
