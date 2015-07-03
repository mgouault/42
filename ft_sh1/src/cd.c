/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 14:18:15 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/21 14:27:35 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char		*resolve_path(char *path)
{
	char	*tmp;

	if (path[ft_strlen(path) - 1] != '/')
	{
		tmp = ft_strjoin(path, "/");
		free(path);
		path = tmp;
	}
	path = cleanpath(path);
	path = dot_dot(path, 0, NULL, NULL);
	if (path[ft_strlen(path) - 1] == '/' && ft_strlen(path) > 1)
	{
		tmp = ft_strsub(path, 0, ft_strlen(path) - 1);
		free(path);
		path = tmp;
	}
	return (path);
}

char		*get_pwd(int ifabs)
{
	t_env	*link;
	char	*tmp;

	if (ifabs == 1 || !(link = search_env("PWD", TRUE)) || \
		!link->value || access(link->value, R_OK) == -1)
	{
		if (!(tmp = getcwd(NULL, MAXPATHLEN)))
		{
			ft_putendl_fd("getcwd: unknown error or permission denied", 2);
			return (NULL);
		}
	}
	else
		tmp = resolve_path(ft_strdup(link->value));
	return (tmp);
}

char		*get_resolved_target(char *target, int ifabs)
{
	char	*tmp;
	char	*tmp2;

	if (target[0] == '/')
		tmp = ft_strdup(target);
	else
	{
		if (!(tmp = get_pwd(ifabs)))
			return (NULL);
		tmp2 = tmp;
		if (tmp[ft_strlen(tmp) - 1] != '/' && target[0] != '/')
			tmp = ft_bigjoin("%s/%s", tmp, target);
		else
			tmp = ft_strjoin(tmp, target);
		free(tmp2);
	}
	tmp = resolve_path(tmp);
	return (tmp);
}

static void	change_dir_(char *tmp)
{
	if (chdir(tmp) == 0)
	{
		update_env_pwd(tmp);
		(void)getsing_returnvalue(0);
	}
	else
		ft_putendl_fd("chdir: unknown error", 2);
}

void		change_dir(char **arg)
{
	char	*target;
	char	*target2;
	char	*tmp;
	int		opt;

	opt = 0;
	if ((opt = read_cd_opt(&target, &target2, opt, arg)) != -1)
	{
		target = get_target(target, target2);
		if (target)
		{
			if (opt == 1 && (ft_strequ(target, "HOME_NOT_FOUND") == 0)
				&& get_access(target))
				absolute_cd(target);
			else if ((ft_strequ(target, "HOME_NOT_FOUND") == 0)
				&& get_access(target))
			{
				update_env_oldpwd();
				if ((tmp = get_resolved_target(target, 0)))
					change_dir_(tmp);
			}
			free(target);
		}
	}
}
