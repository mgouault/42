/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 20:20:39 by mgouault          #+#    #+#             */
/*   Updated: 2015/01/25 23:27:25 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdf	*ft_free_link(t_fdf *link)
{
	t_fdf *next;

	next = link->next;
	free(link);
	return (next);
}

void	ft_error(void)
{
	perror("");
	exit(EXIT_FAILURE);
}
