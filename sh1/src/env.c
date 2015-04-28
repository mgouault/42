/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:45:36 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 22:18:42 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		replace_env(char *name, char *new_value)
{
	t_env *link;

	if (getsing_emptyenv(-1) == 0)
	{
		link = getsing_env(NULL);
		while (link && ft_strequ(link->name, name) == 0)
			link = link->next;
		if (link->value)
			free(link->value);
		link->value = ft_strdup(new_value);
	}
	link = getsing_hiddenenv(NULL);
	while (link && ft_strequ(link->name, link->name))
		link = link->next;
	if (link)
	{
		if (link->value)
			free(link->value);
		link->value = ft_strdup(new_value);
	}
}

void		add_env(char *name, char *value)
{
	t_env	*link;

	link = getsing_env(NULL);
	if (getsing_emptyenv(-1) == 1)
	{
		free_link(link);
		link = (t_env *)ft_memalloc(sizeof(t_env));
		link->name = ft_strdup(name);
		link->value = ft_strdup(value);
		(void)getsing_env(link);
		(void)getsing_emptyenv(0);
	}
	else
	{
		while (link && link->next)
			link = link->next;
		link->next = (t_env *)ft_memalloc(sizeof(t_env));
		link->next->name = ft_strdup(name);
		link->next->value = ft_strdup(value);
	}
}

static void	delete_env_(char *name, t_env *link)
{
	t_env *tmp;

	while (link)
	{
		if (link->next && ft_strequ(link->next->name, name))
		{
			tmp = link->next->next;
			free_link(link->next);
			link->next = tmp;
		}
		link = link->next;
	}
}

void		delete_env(char *name)
{
	t_env	*link;
	t_env	*tmp;

	if (getsing_emptyenv(-1) == 1)
		return ;
	link = getsing_env(NULL);
	if (link && ft_strequ(link->name, name))
	{
		if (!link->next)
		{
			(void)getsing_emptyenv(1);
			return ;
		}
		tmp = link->next;
		(void)getsing_env(tmp);
		free_link(link);
		link = tmp;
	}
	delete_env_(name, link);
}

t_env		*search_env(char *name, t_bool hidden)
{
	t_env	*link;

	link = getsing_env(NULL);
	while (link && ft_strequ(link->name, name) == 0)
		link = link->next;
	if (link || !hidden)
		return (link);
	link = getsing_hiddenenv(NULL);
	while (link && ft_strequ(link->name, name) == 0)
		link = link->next;
	return (link);
}
