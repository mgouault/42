/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 15:47:38 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:02:28 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static t_pid	*ft_fg_(char *name)
{
	t_pid	*pid;

	if (ft_isdigit_str(name))
	{
		if (!(pid = getsing_pidpile(-1, NULL, TRUE, ft_atoi(name))))
		{
			ft_putstr_fd("fg: job not found: ", 2);
			ft_putendl_fd(name, 2);
			return (NULL);
		}
	}
	else
	{
		ft_putendl_fd("ft_minishell1: fg error: wrong arg", 2);
		return (NULL);
	}
	return (pid);
}

void			ft_fg(char *name)
{
	t_pid	*pid;
	char	*tmp_cmd;
	pid_t	tmp_pid;

	if (!name)
	{
		if (!(pid = getsing_pidpile(-1, NULL, TRUE, -1)))
			ft_putendl_fd("fg: no current job.", 2);
	}
	else
		pid = ft_fg_(name);
	if (!pid)
		return ;
	ft_putstr_fd("[1] + continued ", 2);
	ft_putendl_fd(pid->cmd, 2);
	tmp_cmd = ft_strdup(pid->cmd);
	tmp_pid = pid->pid;
	free_pid(pid);
	kill(tmp_pid, SIGCONT);
	ft_wait(tmp_pid, tmp_cmd);
}

static void		ft_setenv_(char *name)
{
	if (!name)
		ft_putendl_fd("setenv: Too few arguments.", 2);
	else
		ft_putendl_fd("setenv: Syntax error.", 2);
	(void)getsing_returnvalue(1);
}

void			ft_setenv(char *name, char *value)
{
	t_env	*link;

	if (!name || ft_strchr(name, '='))
	{
		ft_setenv_(name);
		return ;
	}
	value = (!value) ? "" : value;
	if (!(link = search_env(name, FALSE)))
		add_env(name, value);
	else
	{
		if (link->name)
			free(link->name);
		if (link->value)
			free(link->value);
		link->name = ft_strdup(name);
		if (!value)
			link->value = NULL;
		else
			link->value = ft_strdup(value);
	}
}
