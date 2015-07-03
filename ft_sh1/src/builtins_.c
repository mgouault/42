/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 21:50:57 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 21:56:39 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		ft_echo_var(char *name)
{
	t_env *link;

	if (name[0] == '?' && name[1] == 0)
	{
		ft_putnbr(getsing_returnvalue(-1));
		ft_putchar('\n');
	}
	else
	{
		if (!(link = search_env(name, FALSE)))
		{
			ft_putstr_fd(name, 2);
			ft_putendl_fd(": Undefined variable.", 2);
		}
		else
			ft_putendl(link->value);
	}
}

void		ft_unsetenv(char *name)
{
	if (name == NULL)
	{
		ft_putendl_fd("unsetenv: Too few arguments.", 2);
		(void)getsing_returnvalue(1);
	}
	else
		delete_env(name);
}

void		ft_env(char *cmd, char **arg)
{
	t_env	*env;

	if (getsing_emptyenv(-1) == 1)
		env = NULL;
	else
		env = getsing_env(NULL);
	if (cmd == NULL)
	{
		while (env)
		{
			ft_printf("%s=%s\n", env->name, env->value);
			env = env->next;
		}
	}
	else
	{
		if (ft_strequ(cmd, "-i"))
			choose_exec(arg, NULL);
		else
			choose_exec(arg, env);
	}
}
