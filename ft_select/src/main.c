/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:15:16 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/14 13:27:38 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

static void	init_term(void)
{
	t_term term;

	if (tgetent(NULL, get_envterm()) < 1)
		error_exit("tgetent error");
	if (tcgetattr(0, &term) == -1)
		error_exit("tcgetattr error");
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		error_exit("tcsetattr error");
	tputs(tgetstr("ti", NULL), 0, ret_putchar);
	tputs(tgetstr("is", NULL), 0, ret_putchar);
	tputs(tgetstr("vi", NULL), 0, ret_putchar);
}

void		launch_select(void)
{
	init_term();
	print_lst();
	wait_for_read();
}

static void	init_signals(void)
{
	signal(SIGCONT, catch_sigcont);
	signal(SIGTSTP, catch_sigtstp);
	signal(SIGWINCH, catch_sigwinch);
	signal(SIGINT, catch_sigint);
	signal(SIGHUP, catch_exit);
	signal(SIGQUIT, catch_exit);
	signal(SIGABRT, catch_exit);
	signal(SIGKILL, catch_exit);
	signal(SIGTERM, catch_exit);
}

int			main(int ac, char **av)
{
	if (ac < 2)
	{
		ft_putendl_fd("ft_select: not enough arguments", 2);
		exit(EXIT_FAILURE);
	}
	build_lst(av);
	init_signals();
	launch_select();
	return (0);
}
