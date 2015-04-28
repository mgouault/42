/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:47:12 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 19:25:20 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int		get_access(char *path)
{
	struct stat	st;
	int			ret;

	if (!path)
	{
		ft_putendl_fd("cd: no path given.", 2);
		return (0);
	}
	ret = stat(path, &st);
	if (ret == 0 && access(path, R_OK) == 0 && S_ISDIR(st.st_mode) == 1)
		return (1);
	else if (ret == -1 && access(path, F_OK) == -1)
		ft_putstr_fd("cd: no such file or directory: ", 2);
	else if (ret == -1)
		ft_putstr_fd("cd: unknow stat error: ", 2);
	else if (ret == 0 && S_ISDIR(st.st_mode) == 0)
		ft_putstr_fd("cd: not a directory: ", 2);
	else if (ret == 0 && S_ISDIR(st.st_mode) == 1)
		ft_putstr_fd("cd: permission denied: ", 2);
	ft_putendl_fd(path, 2);
	(void)getsing_returnvalue(1);
	return (0);
}

char	*get_oldpwd(void)
{
	t_env	*link;
	char	*tmp;

	if (!(link = search_env("OLDPWD", TRUE)) || !link->value)
		return (NULL);
	else
	{
		tmp = ft_strdup(link->value);
		tmp = resolve_path(tmp);
	}
	return (tmp);
}

char	*get_home(void)
{
	t_env	*link;
	char	*home;

	link = search_env("HOME", TRUE);
	if (link)
	{
		home = ft_strdup(link->value);
		return (home);
	}
	home = ft_strdup("HOME_NOT_FOUND");
	return (home);
}

char	*get_user(void)
{
	t_env	*link;
	char	*user;

	link = search_env("USER", TRUE);
	if (link)
	{
		user = ft_strdup(link->value);
		return (user);
	}
	user = ft_strdup("USER_NOT_FOUND");
	return (user);
}

char	**get_binpath(void)
{
	t_env	*link;
	char	**bins;
	char	*tmp;
	int		i;

	if (!(link = search_env("PATH", TRUE)))
	{
		ft_putendl_fd("var PATH not found", 2);
		return (NULL);
	}
	bins = ft_strsplit(link->value, ':');
	i = -1;
	while (bins[++i])
	{
		tmp = bins[i];
		bins[i] = ft_strjoin(bins[i], "/");
		free(tmp);
	}
	return (bins);
}
