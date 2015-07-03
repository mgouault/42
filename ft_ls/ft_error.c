/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:24:20 by mgouault          #+#    #+#             */
/*   Updated: 2014/12/13 19:47:10 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define INC_STDIO_H
#define INC_STDLIB_H
#define INC_STRING_H
#define INC_LIBFT_H
#include "ft_ls.h"

void			*ft_error_null(char *str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (str[0] == 0)
		perror("ft_ls: ");
	else
	{
		i = ft_i_strrchr(str, '/');
		++i;
		tmp2 = ft_strsub(str, i, ft_strlen(str) - i);
		if (!tmp2)
			perror("");
		tmp = ft_strjoin("ft_ls: ", tmp2);
		if (!tmp)
			perror("");
		free(tmp2);
		perror(tmp);
		free(tmp);
	}
	return (NULL);
}

void			ft_error(char *str, int do_exit)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	if (str[0] == 0)
		perror("ft_ls: ");
	else
	{
		i = ft_i_strrchr(str, '/');
		++i;
		tmp2 = ft_strsub(str, i, ft_strlen(str) - i);
		if (!tmp2)
			perror("");
		tmp = ft_strjoin("ft_ls: ", tmp2);
		if (!tmp)
			perror("");
		free(tmp2);
		perror(tmp);
		free(tmp);
	}
	if (do_exit == 1)
		exit(EXIT_FAILURE);
}

void			ft_error_ilg_opt(int error)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd((char)error, 2);
	ft_putstr_fd("\nusage: ft_ls [-Raglrt] [file ...]\n", 2);
	exit(EXIT_FAILURE);
}

void			ft_error_fts_open(void)
{
	ft_putstr_fd("ft_ls: fts_open: No such file or directory\n", 2);
	exit(EXIT_FAILURE);
}
