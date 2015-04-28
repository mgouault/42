/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/10 22:08:48 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/14 13:32:56 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	catch_exit(int sig)
{
	exit_tools();
	ft_putendl_fd("ft_select: program exited", 2);
	exit(sig);
}

void	catch_sigint(int sig)
{
	exit_tools();
	ft_putendl_fd("^C", 2);
	exit(sig);
}

void	catch_sigwinch(int sig)
{
	(void)sig;
	print_lst();
}

void	catch_sigtstp(int sig)
{
	t_term	term;
	char	tmp[2];

	(void)sig;
	exit_tools();
	signal(SIGTSTP, SIG_DFL);
	if (tcgetattr(0, &term) == -1)
		error_exit("tcgetattr error");
	tmp[0] = term.c_cc[VSUSP];
	tmp[1] = 0;
	ioctl(1, TIOCSTI, tmp);
}

void	catch_sigcont(int sig)
{
	(void)sig;
	signal(SIGCONT, catch_sigcont);
	signal(SIGTSTP, catch_sigtstp);
	launch_select();
}
