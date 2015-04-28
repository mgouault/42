/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/11 18:43:45 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/01 15:02:30 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void	free_pid(t_pid *pid)
{
	if (pid)
	{
		free(pid->cmd);
		free(pid);
	}
}

void	free_link(t_env *link)
{
	if (link)
	{
		free(link->name);
		free(link->value);
		free(link);
	}
}

void	free_ev(void)
{
	t_env	*link;

	link = getsing_env(NULL);
	while (link)
	{
		free(link->name);
		free(link->value);
		link = link->next;
	}
}

void	free_bistr(char **str)
{
	int		i;

	i = -1;
	if (str)
	{
		while (str[++i])
		{
			if (str[i] != NULL)
				free(str[i]);
		}
		free(str);
	}
}
