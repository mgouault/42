/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/03 00:44:27 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/03 22:54:51 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fractol.h>

static int		expose_hook(t_env *e)
{
	if (e->id == 1)
		ft_update_img(e, draw_mandelbrot);
	if (e->id == 2)
		ft_update_img(e, draw_julia);
	if (e->id == 3)
		ft_update_img(e, draw_ship);
	if (e->id == 4)
		ft_update_img(e, draw_modulo);
	if (e->id == 5)
		ft_update_img(e, draw_sierpinski);
	return (0);
}

int				loop_hook(t_env *e)
{
	if (e->event == 1)
		expose_hook(e);
	e->event = 0;
	return (0);
}

int				exposed(t_env *e)
{
	e->event = 1;
	return (0);
}
