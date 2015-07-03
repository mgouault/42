/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 00:42:08 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/04 20:39:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

int				button_hook(int button, int x, int y, t_env *e)
{
	(void)x;
	(void)y;
	if (button == 4 || button == 5)
	{
		if (button == 5)
			e->zoom /= 1.01;
		if (button == 4)
			e->zoom *= 1.01;
		e->event = 1;
	}
	return (0);
}

int				motion_hook(int x, int y, t_env *e)
{
	if (e->id == 2 && e->freeze == 0)
	{
		e->c1 = (-0.7 + (0.002 * (x - (S_W / 7) * 6))) / e->zoom;
		e->c2 = (0.27015 + (0.001 * (y - (S_H / 7) * 5))) / e->zoom;
		e->event = 1;
	}
	return (0);
}

static void		key_hook_3(int keycode, t_env *e)
{
	if (keycode == 65288)
		e->max_l++;
	if (keycode == 65535)
		e->max_l = e->max_l > 0 ? e->max_l - 1 : e->max_l;
	if (keycode == 32)
		e->freeze = e->freeze == 0 ? 1 : 0;
	e->event = 1;
}

static void		key_hook_2(int keycode, t_env *e)
{
	if (keycode == 65365)
	{
		e->max_i *= 2;
		e->max_r = e->max_r < 6 ? e->max_r + 1 : e->max_r;
	}
	if (keycode == 65366)
	{
		e->max_i = e->max_i > 2 ? e->max_i / 2 : e->max_i;
		e->max_r = e->max_r > 2 ? e->max_r - 1 : e->max_r;
	}
	if (keycode == 65360)
	{
		e->color_coeff = e->color_coeff < 8 ? e->color_coeff + 1 : 1;
		e->mod_n = e->mod_n < 6 ? e->mod_n + 1 : e->mod_n;
	}
	if (keycode == 65367)
	{
		e->color_coeff = e->color_coeff > 1 ? e->color_coeff - 1 : 8;
		e->mod_n = e->mod_n > 0 ? e->mod_n - 1 : e->mod_n;
	}
	key_hook_3(keycode, e);
}

int				key_hook(int keycode, t_env *e)
{
	if (keycode == 32 || keycode == 65307 || keycode == 65451 ||
		keycode == 65535 || keycode == 65288 || keycode == 65453 ||
		(keycode >= 65360 && keycode <= 65367))
	{
		if (keycode == 65307)
		{
			mlx_destroy_window(e->mlx, e->win);
			free(e);
			exit(EXIT_SUCCESS);
		}
		if (keycode == 65451)
			e->zoom *= 1.01;
		if (keycode == 65453)
			e->zoom /= 1.01;
		if (keycode == 65361)
			e->move_x -= 0.003;
		if (keycode == 65363)
			e->move_x += 0.003;
		if (keycode == 65362)
			e->move_y -= 0.003;
		if (keycode == 65364)
			e->move_y += 0.003;
		key_hook_2(keycode, e);
	}
	return (0);
}
