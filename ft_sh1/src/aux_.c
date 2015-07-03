/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/24 18:55:28 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/27 20:39:33 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		ft_wait(pid_t pid, char *cmd)
{
	int		val;

	val = -1;
	if ((waitpid(pid, &val, WUNTRACED)) == -1)
		error_exit("wait: unknown error");
	if (WIFSTOPPED(val))
	{
		(void)getsing_pidpile(pid, cmd, FALSE, -1);
		val = WSTOPSIG(val);
	}
	else
		(void)getsing_returnvalue(val);
	return_value(val, cmd);
}

static void	successful_exit(char *str)
{
	int var;

	if (!str)
	{
		exit_term();
		exit(EXIT_SUCCESS);
	}
	var = ft_atoi(str) & 255;
	if (ft_isdigit_str(str))
	{
		exit_term();
		exit(var);
	}
	else
	{
		ft_putendl_fd("ft_minishell1: exit error: wrong value", 2);
		(void)getsing_returnvalue(1);
	}
}

void		try_exit(char *str, t_bool eof)
{
	static t_bool advert = FALSE;

	if (getsing_pidpile(-1, NULL, FALSE, -1) != NULL)
	{
		if (advert)
			successful_exit(str);
		if (eof)
			ft_putstr_fd("\nft_minishell1: you have suspended jobs.", 2);
		else
			ft_putendl_fd("ft_minishell1: you have suspended jobs.", 2);
		advert = TRUE;
	}
	else
		successful_exit(str);
}

static char	**return_value_(char **msg)
{
	msg[1] = "hangup";
	msg[3] = "quit";
	msg[4] = "illegal hardware instruction";
	msg[5] = "trace trap";
	msg[6] = "abort";
	msg[7] = "EMT instruction";
	msg[8] = "floating point exception";
	msg[9] = "killed";
	msg[10] = "bus error";
	msg[11] = "segmentation fault";
	msg[12] = "invalid system call";
	msg[14] = "timeout";
	msg[15] = "terminated";
	msg[17] = "suspended (signal)";
	msg[18] = "suspended (signal)";
	msg[21] = "suspended (tty input)";
	msg[22] = "suspended (tty output)";
	msg[24] = "cpu limit exceeded";
	msg[25] = "file size limit exceeded";
	msg[26] = "virtual time alarm";
	msg[27] = "profile signal";
	msg[30] = "user-defined signal 1";
	msg[31] = "user-defined signal 2";
	return (msg);
}

void		return_value(int ret, char *cmd)
{
	char	**msg;
	int		i;

	if (ret < 1 || ret == 13 || ret == 16 || ret == 19 || ret == 20 || \
		ret == 23 || ret == 28 || ret == 29 || ret == 30 || ret > 32)
		return ;
	if (ret == 2 || ret == 18)
		ft_putchar('\n');
	if (ret == 2)
		return ;
	msg = (char **)ft_memalloc(sizeof(char *) * 33);
	i = -1;
	while (++i < 33)
		msg[i] = NULL;
	msg = return_value_(msg);
	ft_putstr_fd("ft_minishell1: ", 2);
	ft_putstr_fd(msg[ret], 2);
	ft_putchar_fd(' ', 2);
	free(msg);
	ft_putendl_fd(cmd, 2);
	free(cmd);
}
