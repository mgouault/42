/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 13:19:33 by mgouault          #+#    #+#             */
/*   Updated: 2015/01/03 20:21:24 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "get_next_line.h"
# include "libft/libft.h"
# include <string.h>
# include <mlx.h>
# include <math.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_fdf
{
	int				*tab;
	int				length;
	struct s_fdf	*next;
}					t_fdf;

typedef struct		s_val
{
	int				x0;
	int				y0;
	int				x1;
	int				y1;
	int				z;
}					t_val;

typedef struct		s_env
{
	int				screen_width;
	int				screen_height;
	int				o_x;
	int				o_y;
	int				space_x;
	int				space_y;
	int				color_map;
	float			z;
	void			*mlx;
	void			*win;
	t_fdf			*map;
}					t_env;

t_fdf				*ft_gather_data(char *name);
t_fdf				*ft_free_link(t_fdf *link);
void				ft_print_ls(t_env *e);
void				ft_error(void);

#endif
