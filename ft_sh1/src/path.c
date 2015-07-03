/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:47:16 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 18:43:31 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static char		*replace_home_(char *arg, char *home, int i)
{
	char	*tmp;

	if (i == 0 && arg[i + 1] == 0)
		arg = ft_strdup(home);
	else if (i == 0 && arg[i + 1] != 0)
	{
		tmp = ft_strsub(arg, i + 1, ft_strlen(arg) - (i - 1));
		arg = ft_strjoin(home, tmp);
		free(tmp);
	}
	return (arg);
}

char			**replace_home(char **arg, char *home)
{
	int		i;
	int		j;

	if (ft_strequ(home, "HOME_NOT_FOUND") == 0)
	{
		j = 1;
		while (arg[j])
		{
			i = 0;
			while (arg[j][i])
			{
				if (arg[j][i] == '~')
					arg[j] = replace_home_(arg[j], home, i);
				++i;
			}
			++j;
		}
	}
	free(home);
	return (arg);
}

char			*replace_home_lite(char *tmp1)
{
	char	*home;
	char	*tmp2;

	home = get_home();
	if (ft_strnequ(tmp1, home, ft_strlen(home)) && \
		(ft_strequ(home, "HOME_NOT_FOUND") == 0))
	{
		tmp2 = ft_strsub(tmp1, ft_strlen(home), ft_strlen(tmp1) \
			- ft_strlen(home));
		free(tmp1);
		tmp1 = ft_strjoin("~", tmp2);
		free(tmp2);
	}
	free(home);
	return (tmp1);
}

static int		try_path(char *cmd)
{
	if (access(cmd, X_OK) == 0)
		return (1);
	else if (access(cmd, F_OK) == 0)
	{
		ft_putstr_fd("ft_minishell1: permission denied: ", 2);
		ft_putendl_fd(cmd, 2);
		return (-1);
	}
	else
		return (0);
}

char			*search_binpath(char *cmd)
{
	char	**bins;
	char	*tmp;
	int		i;
	int		ret;

	i = -1;
	if (!(bins = get_binpath()))
		return (NULL);
	while (bins[++i])
	{
		tmp = ft_strjoin(bins[i], cmd);
		if ((ret = try_path(tmp)) == 1)
		{
			free_bistr(bins);
			return (tmp);
		}
		else if (ret == -1)
		{
			free_bistr(bins);
			return (NULL);
		}
		free(tmp);
	}
	free_bistr(bins);
	return (NULL);
}
