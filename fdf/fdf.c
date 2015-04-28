/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:19:33 by mgouault          #+#    #+#             */
/*   Updated: 2015/01/03 20:22:16 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		ft_exit_fdf(t_env *e)
{
	int i;

	i = -1;
	while (e->map[++i].tab != NULL)
		free(e->map[i].tab);
	free(e->map);
	free(e->win);
	free(e->mlx);
	free(e);
	exit(EXIT_SUCCESS);
}

static int		ft_expose_hook(t_env *e)
{
	mlx_clear_window(e->mlx, e->win);
	ft_print_ls(e);
	return (0);
}

static void		ft_key_hook_(int keycode, t_env *e)
{
	if (keycode == 65451)
	{
		e->space_x += 2;
		e->space_y = e->space_x / 2;
	}
	if (keycode == 65453)
	{
		if (e->space_x >= 4)
		{
			e->space_x -= 2;
			e->space_y = e->space_x / 2;
		}
	}
	if (keycode == 65456)
	{
		if (e->color_map == 0)
			e->color_map = 1;
		else if (e->color_map == 1)
			e->color_map = 2;
		else
			e->color_map = 0;
	}
}

static int		ft_key_hook(int keycode, t_env *e)
{
	if (keycode == 65307 || keycode == 65451 || keycode == 65453 ||
		keycode == 65456 || keycode == 65361 || keycode == 65362 ||
		keycode == 65363 || keycode == 65364 || keycode == 65365 ||
		keycode == 65366)
	{
		if (keycode == 65451 || keycode == 65453 || keycode == 65456)
			ft_key_hook_(keycode, e);
		if (keycode == 65307)
			ft_exit_fdf(e);
		if (keycode == 65361)
			e->o_x -= 100;
		if (keycode == 65363)
			e->o_x += 100;
		if (keycode == 65362)
			e->o_y -= 100;
		if (keycode == 65364)
			e->o_y += 100;
		if (keycode == 65365)
			e->z *= 1.5;
		if (keycode == 65366)
			e->z *= 0.5;
		ft_expose_hook(e);
	}
	return (0);
}

int				main(int ac, char **av)
{
	t_env	*e;

	if (ac != 2)
		exit(EXIT_FAILURE);
	if (!(e = (t_env *)malloc(sizeof(t_env))))
		ft_error();
	e->map = ft_gather_data(av[1]);
	e->screen_width = 2560;
	e->screen_height = 1440;
	if (!(e->mlx = mlx_init()))
		ft_error();
	e->win = mlx_new_window(e->mlx, e->screen_width, e->screen_height, "FdF");
	e->o_x = e->screen_width / 2;
	e->o_y = e->screen_height / 8;
	e->space_x = 6;
	e->space_y = e->space_x / 2;
	e->color_map = 0;
	e->z = 1;
	mlx_key_hook(e->win, ft_key_hook, e);
	mlx_expose_hook(e->win, ft_expose_hook, e);
	mlx_loop(e->mlx);
	return (0);
}
