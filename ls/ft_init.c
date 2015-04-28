/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 17:00:37 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/27 15:25:13 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

int *g_option;

void			ft_set_tab(int *tab, int size)
{
	int i;

	i = 0;
	while (size > 0)
	{
		tab[i] = 0;
		++i;
		--size;
	}
}

static int		ft_fill_g_option(char *av)
{
	int j;

	j = 0;
	if (ft_strchr(av, 'a'))
		g_option[1] = 1;
	if (ft_strchr(av, 'r'))
		g_option[2] = 1;
	if (ft_strchr(av, 'R'))
		g_option[3] = 1;
	if (ft_strchr(av, 't'))
		g_option[4] = 1;
	if (ft_strchr(av, 'g'))
		g_option[5] = 1;
	if ((g_option[5] == 1) || ft_strchr(av, 'l'))
		g_option[0] = 1;
	while (av[++j])
	{
		if (!((av[j] == 'a') || (av[j] == 'r') || (av[j] == 'R') ||
			(av[j] == 't') || (av[j] == 'g') || (av[j] == 'l') ||
			(av[j] == '1')))
		{
			return ((int)av[j]);
		}
	}
	return (-1);
}

static int		ft_read_g_option(char **av, int i, int ac)
{
	int error;

	error = -1;
	while (i <= (ac - 1))
	{
		if ((av[i][0] == '-') && (av[i][1] != '-') && (av[i][1] != 0))
		{
			error = ft_fill_g_option(av[i]);
			if (error != -1)
				ft_error_ilg_opt(error);
			++i;
		}
		else
			break ;
	}
	return (i);
}

static t_lstf	*ft_readargv(int ac, char **av, int i, int j)
{
	int *dir;
	int ifmin;

	ifmin = 0;
	dir = (int *)malloc(sizeof(int) * ac - 1);
	if (!dir)
		ft_error("", 1);
	dir = ft_memset(dir, 0, ac - 1);
	i = ft_read_g_option(av, i, ac);
	while (i <= (ac - 1))
	{
		if ((ft_strequ(av[i], "--") == 1) && (ifmin == 0))
		{
			dir[j++] = ++i;
			ifmin = 1;
		}
		else
			dir[j++] = i;
		++i;
	}
	if (dir[0] > 0)
		return (ft_crt_avlst(dir, av, NULL, NULL));
	ft_readonedir(".");
	return (NULL);
}

int				main(int ac, char **av)
{
	t_lstf	*input;

	g_option = (int *)malloc(sizeof(int) * 6);
	if (!g_option)
		ft_error("", 1);
	ft_set_tab(g_option, 6);
	input = ft_readargv(ac, av, 1, 0);
	if (input != NULL)
		ft_if_input(input, 0);
	free(g_option);
	return (0);
}
