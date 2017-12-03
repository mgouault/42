/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mallocstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/03 19:02:37 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:19:47 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libc.h>

char	*ft_malloc_str(int size)
{
	char	*res;

	res = (char *)malloc((size_t)(size * sizeof(char) + 1));
	if (!res)
		exit(EXIT_FAILURE);
	return (res);
}
