/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 20:12:13 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 21:11:50 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

t_bool		ft_isdigit_str(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]))
			return (FALSE);
	return (TRUE);
}

static int	arg_count(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != ' ')
		{
			j++;
			c = (s[i] == '"') ? '"' : ' ';
			i++;
			while (s[i] && s[i] != c)
				i++;
		}
		i += (s[i]) ? 1 : 0;
	}
	return (j);
}

char		**arg_split(char *arg)
{
	char	**str;
	int		i;
	int		j;
	int		p;
	char	c;

	str = (char **)ft_memalloc(sizeof(char *) * (arg_count(arg) + 1));
	i = -1;
	p = -1;
	while (i < (int)ft_strlen(arg) - 1 && arg[++i])
	{
		arg[i] = (arg[i] == '\t') ? ' ' : arg[i];
		if (arg[i] != ' ')
		{
			j = i;
			c = (arg[i] && arg[i] == '"') ? '"' : ' ';
			while (arg[++j] && arg[j] != c)
				;
			str[++p] = ft_strsub(arg, (c == '"') ? i + 1 : i, \
				j - ((c == '"') ? i + 1 : i));
			i = j;
		}
	}
	str[++p] = NULL;
	return (str);
}

char		**make_bistr(t_env *link)
{
	t_env	*start;
	char	**bistr;
	int		i;

	if (!link)
		return (NULL);
	start = link;
	i = 0;
	while (link)
	{
		i++;
		link = link->next;
	}
	bistr = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (start)
	{
		bistr[i] = ft_bigjoin("%s=%s", start->name, start->value);
		i++;
		start = start->next;
	}
	bistr[i] = NULL;
	return (bistr);
}

char		*infin_join(char **arg)
{
	char	*join;
	int		v[3];

	v[0] = 0;
	v[1] = -1;
	while (arg[++v[1]])
	{
		v[2] = 0;
		while (arg[v[1]][v[2]])
			v[2]++;
		v[0] += v[2] + 1;
	}
	join = (char *)ft_memalloc(sizeof(char) * v[0]);
	v[0] = 0;
	v[1] = -1;
	while (arg[++v[1]])
	{
		v[2] = -1;
		while (arg[v[1]][++v[2]])
			join[v[0] + v[2]] = arg[v[1]][v[2]];
		v[0] += v[2];
		join[v[0]++] = ' ';
	}
	join[--v[0]] = 0;
	return (join);
}
