/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 19:43:36 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/21 16:48:04 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void	exec_file_(char *cmd)
{
	ft_putstr_fd("ft_minishell1: no such file or directory: ", 2);
	ft_putendl_fd(cmd, 2);
	(void)getsing_returnvalue(127);
}

static void	exec_file(char *cmd, char **arg, t_env *env)
{
	struct stat	st;
	int			i;

	if ((i = stat(cmd, &st)) == -1)
		exec_file_(cmd);
	else if (access(cmd, X_OK) == -1 || (S_ISREG(st.st_mode) == 0))
	{
		if (access(cmd, F_OK) == 0)
		{
			ft_putstr_fd("ft_minishell1: permission denied: ", 2);
			ft_putendl_fd(cmd, 2);
			(void)getsing_returnvalue(126);
		}
		else
			exec_file_(cmd);
	}
	else
		ft_execve(ft_strdup(cmd), arg, env);
}

static void	choose_exec_(char *target, char **arg, t_env *link)
{
	char *tmp;

	if (ft_strchr(target, '/'))
		exec_file(target, arg, link);
	else
	{
		if (!(tmp = search_binpath(target)))
			bin_notfound(target);
		else
			ft_execve(tmp, arg, link);
	}
}

void		choose_exec(char **arg, t_env *link)
{
	char	*target;
	int		incr;

	if (!arg || !arg[0])
		return ;
	incr = 0;
	if (arg[1] && ft_strequ(arg[0], "env"))
	{
		target = arg[1];
		incr++;
		if (ft_strequ(arg[1], "-i"))
		{
			target = arg[2];
			incr++;
		}
	}
	else
		target = arg[0];
	arg = &(arg[incr]);
	choose_exec_(target, arg, link);
}

void		exec_cmd(char **arg)
{
	replace_home(arg, get_home());
	if (ft_strequ(arg[0], "exit"))
		try_exit(arg[1], FALSE);
	else if (ft_strequ(arg[0], "cd"))
		change_dir(arg);
	else if (ft_strequ(arg[0], "env"))
		ft_env(arg[1], arg);
	else if (ft_strequ(arg[0], "setenv"))
		ft_setenv(arg[1], arg[2]);
	else if (ft_strequ(arg[0], "unsetenv"))
		ft_unsetenv(arg[1]);
	else if (ft_strequ(arg[0], "echo") && arg[1] && arg[1][0] == '$')
		ft_echo_var(&arg[1][1]);
	else if (ft_strequ(arg[0], "fg"))
		ft_fg(arg[1]);
	else
		choose_exec(arg, getsing_env(NULL));
	free_bistr(arg);
}
