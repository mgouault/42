/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_bistr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:49:01 by mgouault          #+#    #+#             */
/*   Updated: 2015/05/28 19:51:19 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

void ft_free_bistr(char **bistr)
{
	unsigned int i;

	i = 0;
	while (bistr[i])
	{
		free(bistr[i]);
		i++;
	}
	free(bistr);
}
