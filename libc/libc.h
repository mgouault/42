/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libc.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/08 20:01:27 by mgouault          #+#    #+#             */
/*   Updated: 2017/12/03 19:20:09 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBC_H
# define LIBC_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef enum
{
	FALSE = 0,
	TRUE
}	t_bool;

typedef struct s_list	t_list;

struct		s_list
{
	void	*content;
	size_t	content_size;
	t_list	*next;
};

#endif
