/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:18:12 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/13 22:55:01 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

int		ret_putchar(int c)
{
	return (write(get_fd(), &c, 1));
}

void	free_lst(t_lst *link)
{
	t_lst *next;

	while (link && link->prev)
		link = link->prev;
	while (link)
	{
		next = link->next;
		free(link->name);
		free(link);
		link = next;
	}
}

short	get_key(char *b)
{
	short key;

	key = K_NONE;
	if (b[0] == 27 && b[1] == 91 && b[2] == 65 && b[3] == 0)
		key = K_UP;
	else if (b[0] == 27 && b[1] == 91 && b[2] == 66 && b[3] == 0)
		key = K_DOWN;
	else if (b[0] == 32 && b[1] == 0)
		key = K_SPACE;
	else if ((b[0] == 27 && b[1] == 91 && \
		b[2] == 51 && b[3] == 126 && b[4] == 0) || (b[0] == 127 && b[1] == 0))
		key = K_DELETE;
	else if (b[0] == 10 && b[1] == 0)
		key = K_ENTER;
	else if (b[0] == 27 && b[1] == 0)
		key = K_ESCAPE;
	else if (b[0] == 27 && b[1] == 91 && b[2] == 54 && b[3] == 126 && b[4] == 0)
		key = K_PAGE_DOWN;
	else if (b[0] == 27 && b[1] == 91 && b[2] == 53 && b[3] == 126 && b[4] == 0)
		key = K_PAGE_UP;
	else if (b[0] == 27 && b[1] == 91 && b[2] == 70 && b[3] == 0)
		key = K_END;
	else if (ft_isprint(b[0]) && b[1] == 0)
		key = VALID_SEARCH;
	return (key);
}

t_bool	madehome_strstr(char *s1, char *s2)
{
	int i;

	if (!s1 || !s2 || !(*s1) || !(*s2))
		return (FALSE);
	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s2[i + 1] == 0)
			return (TRUE);
		i++;
	}
	return (FALSE);
}

void	select_all(short key)
{
	t_lst *link;

	link = get_lst(NULL);
	while (link)
	{
		link->selected = (key == K_PAGE_DOWN) ? TRUE : FALSE;
		link = link->next;
	}
	print_lst();
}
