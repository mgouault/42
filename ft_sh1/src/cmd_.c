/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 22:09:25 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:15:29 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		bin_notfound(char *cmd)
{
	ft_putstr_fd("ft_minishell1: command not found: ", 2);
	ft_putendl_fd(cmd, 2);
	(void)getsing_returnvalue(127);
}

static void	init_signal(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
	signal(SIGTERM, SIG_DFL);
	signal(SIGSTOP, SIG_DFL);
	signal(SIGTSTP, SIG_DFL);
	signal(SIGTTIN, SIG_DFL);
	signal(SIGTTOU, SIG_DFL);
	signal(SIGWINCH, SIG_DFL);
}

void		ft_execve(char *tmp1, char **arg, t_env *link)
{
	pid_t	pid;
	char	**envp;
	char	*cmd;

	envp = make_bistr(link);
	if ((pid = fork()) == -1)
		error_exit("fork: unknown error");
	if (pid == 0)
	{
		init_signal();
		if (execve(tmp1, arg, envp) == -1)
		{
			ft_putstr_fd("ft_minishell1: can't execute: ", 2);
			ft_putendl_fd(tmp1, 2);
			exit(1);
		}
	}
	if (pid > 0)
	{
		cmd = infin_join(arg);
		ft_wait(pid, cmd);
		free(tmp1);
		if (envp)
			free(envp);
	}
}
