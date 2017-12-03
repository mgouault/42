/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_in_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:28:59 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 20:03:47 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

t_bool	ft_str_in_array(char **array, char *str)
{
	int	i;

	i = 0;
	while (array[i])
	{
		if (ft_str_equ(array[i], str))
			return (TRUE);
		i++;
	}
	return (FALSE);
}
