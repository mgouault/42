/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/07 14:45:47 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:45:09 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

char			*do_tilde(char *b)
{
	b[0] = 126;
	b[1] = 0;
	return (b);
}

char			**empty_cmd(char *input)
{
	char	**arg;
	int		i;

	if (!input || !(*input))
		return (NULL);
	i = 0;
	while (input[i])
	{
		if (input[i] != ' ' && input[i] != '\t')
		{
			arg = arg_split(input);
			free(input);
			return (arg);
		}
		++i;
	}
	return (NULL);
}

static char		**get_input(char *line)
{
	char	**input;
	int		i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ';' && line[i + 1] == ';')
		{
			ft_putendl_fd("ft_minishell1: parse error near `;;'", 2);
			return (NULL);
		}
		i++;
	}
	input = ft_strsplit(line, ';');
	free(line);
	return (input);
}

static void		ft_minishell1(char *line)
{
	char	**input;
	char	**arg;
	int		i;

	if (!(*line) || !(input = get_input(line)))
		return ;
	i = 0;
	while (input[i])
	{
		if ((arg = empty_cmd(input[i])))
			exec_cmd(arg);
		else
			free(input[i]);
		i++;
	}
	free(input);
	return ;
}

int				main(int argc, char **argv, char **envp)
{
	t_line	*history;
	char	*line;

	(void)argv;
	(void)argc;
	if (!envp || !(*envp))
		error_exit("Invalid ENVP");
	(void)getsing_env(evdup(envp));
	(void)getsing_hiddenenv(evdup(envp));
	init_shell();
	history = NULL;
	while (42)
	{
		line = parser(history);
		history = update_history(history, line);
		ft_minishell1(line);
	}
	return (0);
}
