/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_termcaps.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/18 16:51:55 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/03 17:17:06 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

int		ret_putchar(int c)
{
	return (write(1, &c, 1));
}

void	exit_term(void)
{
	t_term	term;

	tputs(tgetstr("rs", NULL), 0, ret_putchar);
	if (tcgetattr(getsing_ttyfd(-1), &term) == -1)
		ft_putendl_fd("tcgetattr error", 2);
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	if (tcsetattr(getsing_ttyfd(-1), TCSANOW, &term) == -1)
		ft_putendl_fd("tcsetattr error", 2);
}

void	init_term(void)
{
	char	*name;
	t_term	term;
	int		fd;

	if (!(name = getenv("TERM")))
		fast_exit("getenv error");
	if (tgetent(NULL, name) < 1)
		fast_exit("tgetent error");
	close(0);
	if ((fd = open("/dev/tty", O_RDWR)) == -1)
		fast_exit("open on tty error");
	(void)getsing_ttyfd(fd);
	if (tcgetattr(getsing_ttyfd(-1), &term) == -1)
		fast_exit("tcgetattr error");
	term.c_lflag &= ~(ICANON);
	term.c_lflag &= ~(ECHO);
	if (tcsetattr(getsing_ttyfd(-1), TCSANOW, &term) == -1)
		fast_exit("tcsetattr error");
	tputs(tgetstr("is", NULL), 0, ret_putchar);
	(void)getsing_col(tgetnum("co"));
}
