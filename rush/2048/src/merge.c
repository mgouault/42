/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/28 18:28:57 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/01 20:34:49 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <game_2048.h>

void		merge(t_map *steady, t_map *moving, bool *action_done)
{
	if (steady->value == moving->value && steady->merged != TRUE \
		&& steady->value < 131072)
	{
		*action_done = TRUE;
		steady->value = steady->value * 2;
		moving->value = 0;
		steady->merged = TRUE;
	}
}
