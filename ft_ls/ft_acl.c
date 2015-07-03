/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_acl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/07 17:53:10 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:42:22 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_SYS_STAT_H
#define INC_STDLIB_H
#define INC_STRING_H
#include "ft_ls.h"

static char	ft_gettype(int mode)
{
	char c;

	if (S_ISDIR(mode) == 1)
		c = 'd';
	else if (S_ISLNK(mode) == 1)
		c = 'l';
	else if (S_ISFIFO(mode) == 1)
		c = 'p';
	else if (S_ISBLK(mode) == 1)
		c = 'b';
	else if (S_ISCHR(mode) == 1)
		c = 'c';
	else if (S_ISSOCK(mode) == 1)
		c = 's';
	else
		c = '-';
	return (c);
}

static char ft_getmode_(char c, int mode, int pl)
{
	if (pl == 1)
	{
		if (04000 & mode)
			c = 'S';
		if ((00100 & mode) && (04000 & mode))
			c = 's';
	}
	else if (pl == 2)
	{
		if (02000 & mode)
			c = 'S';
		if ((00010 & mode) && (02000 & mode))
			c = 's';
	}
	else if (pl == 3)
	{
		if (01000 & mode)
			c = 'T';
		if ((00001 & mode) && (01000 & mode))
			c = 't';
	}
	return (c);
}

char		*ft_getmode(int mode)
{
	char *str;

	str = (char *)malloc(sizeof(char) * 10 + 1);
	if (!str)
		return (NULL);
	str[0] = ft_gettype(mode);
	str[1] = 00400 & mode ? 'r' : '-';
	str[2] = 00200 & mode ? 'w' : '-';
	str[3] = 00100 & mode ? 'x' : '-';
	str[3] = ft_getmode_(str[3], mode, 1);
	str[4] = 00040 & mode ? 'r' : '-';
	str[5] = 00020 & mode ? 'w' : '-';
	str[6] = 00010 & mode ? 'x' : '-';
	str[6] = ft_getmode_(str[6], mode, 2);
	str[7] = 00004 & mode ? 'r' : '-';
	str[8] = 00002 & mode ? 'w' : '-';
	str[9] = 00001 & mode ? 'x' : '-';
	str[9] = ft_getmode_(str[9], mode, 3);
	str[10] = 0;
	return (str);
}
