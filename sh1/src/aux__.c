/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux__.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 21:11:03 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/21 16:51:11 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static short	prompt_(char *tmp1)
{
	char	*tmp2;
	short	length;

	tmp2 = get_user();
	ft_printf(
		"\033[1;30;40m%s\033[0m \033[0;33;40m%s\033[0m \033[1;30;40m>\033[0m ",
			tmp2, tmp1);
	length = ft_strlen(tmp1) + ft_strlen(tmp2) + 5;
	free(tmp2);
	return (length);
}

short			prompt(void)
{
	t_env	*link;
	char	*tmp1;
	short	length;

	if (!(link = search_env("PWD", TRUE)))
	{
		if (!(tmp1 = getcwd(NULL, MAXPATHLEN)))
		{
			ft_putendl_fd("getcwd: unknown error", 2);
			if ((chdir("/")) == -1)
				error_exit("chdir: unknown error");
			if (!(tmp1 = getcwd(NULL, MAXPATHLEN)))
				error_exit("getcwd: unknown error");
		}
	}
	else
		tmp1 = ft_strdup(link->value);
	tmp1 = replace_home_lite(tmp1);
	length = prompt_(tmp1);
	free(tmp1);
	return (length);
}

static void		update_env_values(void)
{
	t_env	*link;
	t_env	*tmp;
	char	*to_free;
	int		lvl;

	if ((link = search_env("SHLVL", FALSE)))
	{
		lvl = ft_atoi(link->value) + 1;
		to_free = ft_itoa(lvl);
		replace_env("SHLVL", to_free);
		free(to_free);
	}
	if ((link = search_env("SHELL", FALSE)))
	{
		if ((tmp = search_env("_", TRUE)))
			replace_env("SHELL", tmp->value);
	}
}

void			init_shell(void)
{
	(void)getsing_emptyenv(0);
	(void)getsing_returnvalue(0);
	update_env_values();
	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTERM, SIG_IGN);
	signal(SIGSTOP, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGTTIN, SIG_IGN);
	signal(SIGTTOU, SIG_IGN);
	signal(SIGCONT, SIG_IGN);
	signal(SIGWINCH, resize);
}

t_env			*evdup(char **env)
{
	t_env	*link;
	t_env	*start;
	t_env	**next;
	char	*join;
	int		i;

	start = NULL;
	next = NULL;
	i = -1;
	while (env[++i])
	{
		link = (t_env *)ft_memalloc(sizeof(t_env));
		start = (start) ? start : link;
		join = ft_strchr(env[i], '=');
		link->name = ft_strsub(env[i], 0, join - env[i]);
		link->value = ft_strsub(env[i], (join - env[i]) + 1, \
			ft_strlen(env[i]) - (join - env[i]));
		if (next)
			*next = link;
		next = &link->next;
	}
	if (next)
		*next = NULL;
	return (start);
}
