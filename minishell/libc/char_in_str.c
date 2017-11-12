/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_in_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 19:28:57 by mgouault          #+#    #+#             */
/*   Updated: 2017/11/12 19:29:11 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

t_bool	char_in_str(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (TRUE);
		i++;
	}
	return (FALSE);
}
