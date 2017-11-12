/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_opt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/23 16:58:12 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/22 21:50:46 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		absolute_cd(char *target)
{
	char *tmp;

	update_env_oldpwd();
	if ((tmp = get_resolved_target(target, 1)))
	{
		if (chdir(tmp) == 0)
			update_env_pwd(tmp);
		else
			ft_putendl_fd("chdir: unknown error", 2);
	}
}

static char	*switch_path(char *target, char *target2)
{
	char	*tmp;
	char	*new;

	if (!(tmp = get_pwd(0)))
		return (NULL);
	if (!ft_strstr(tmp, target))
	{
		ft_putstr_fd("cd: string not in pwd: ", 2);
		ft_putendl_fd(target, 2);
		return (NULL);
	}
	new = ft_strreplace(tmp, target, target2);
	return (new);
}

char		*get_target(char *target, char *target2)
{
	char	*tmp;

	if (!target)
		target = get_home();
	else if (target2 != NULL || ft_strequ(target, "-"))
	{
		if (target2 != NULL)
			target = switch_path(target, target2);
		else
			target = get_oldpwd();
		if (target != NULL && (access(target, R_OK)) == 0)
		{
			tmp = replace_home_lite(ft_strdup(target));
			ft_putendl(tmp);
			free(tmp);
		}
	}
	else
		target = ft_strdup(target);
	return (target);
}

static int	read_arg(char *arg, int *opt)
{
	int		i;

	i = 1;
	while (arg[i])
	{
		if (arg[i] == 'P')
			*opt = 1;
		if (arg[i] != 'P' && arg[i] != 'L')
			return (-1);
		++i;
	}
	return (0);
}

int			read_cd_opt(char **target, char **target2, int opt, char **arg)
{
	int		i;

	i = 0;
	*target = NULL;
	*target2 = NULL;
	while (arg[++i])
	{
		if (arg[i][0] == '-' && arg[i][1] != 0 && *target == NULL)
		{
			if (read_arg(arg[i], &opt) == -1)
				*target = arg[i];
		}
		else if (*target == NULL)
			*target = arg[i];
		else if (*target2 == NULL)
			*target2 = arg[i];
		else
		{
			ft_putendl_fd("cd: too many arguments", 2);
			return (-1);
		}
	}
	return (opt);
}
