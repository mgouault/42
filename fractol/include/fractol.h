/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 13:47:16 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/03 22:47:50 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <libft.h>

# define S_H 600
# define S_W 900

typedef struct	s_env
{
	int			id;
	double		zoom;
	double		move_x;
	double		move_y;
	int			max_i;
	int			max_r;
	int			max_l;
	int			mod_n;
	double		c1;
	double		c2;
	void		*mlx;
	void		*win;
	void		*img;
	char		*pimg;
	int			bpp;
	int			endian;
	int			size_line;
	int			event;
	short		color_coeff;
	short		freeze;
}				t_env;

void			draw_mandelbrot(t_env *e);
void			draw_julia(t_env *e);
void			draw_modulo(t_env *e);
void			draw_sierpinski(t_env *e);
void			draw_ship(t_env *e);
void			put_pixel_to_image(t_env *e, int x, int y, int color);
int				ft_update_img(t_env *ret, void f(t_env *ret));
int				button_hook(int button, int x, int y, t_env *e);
int				key_hook(int keycode, t_env *e);
int				motion_hook(int x, int y, t_env *e);
int				loop_hook(t_env *e);
int				exposed(t_env *e);
void			ft_bzero_double(double *tab, int n);
void			init_sierpinski(float v[8]);
int				ft_rand(int seed);

#endif
