/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 21:24:28 by mgouault          #+#    #+#             */
/*   Updated: 2015/05/28 21:44:38 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

t_bool ft_isspace_str(char *str)
{
	unsigned int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isspace(str[i]))
			return (FALSE);
		i++;
	}
	return (TRUE);
}
