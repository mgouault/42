/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singletons_.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 22:32:25 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:33:24 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

t_env	*getsing_env(t_env *env)
{
	static t_env	*actual_env = NULL;

	if (env)
		actual_env = env;
	return (actual_env);
}

t_env	*getsing_hiddenenv(t_env *env)
{
	static t_env	*hidden_env = NULL;

	if (env)
		hidden_env = env;
	return (hidden_env);
}

int		getsing_emptyenv(int status)
{
	static int		actual_status = -1;

	if (status > -1)
		actual_status = status;
	return (actual_status);
}

int		getsing_returnvalue(int value)
{
	static int		actual_value = -1;

	if (value > -1)
		actual_value = value;
	return (actual_value);
}

int		getsing_ttyfd(int ttyfd)
{
	static int		actual_ttyfd = -1;

	if (ttyfd > -1)
		actual_ttyfd = ttyfd;
	return (actual_ttyfd);
}
