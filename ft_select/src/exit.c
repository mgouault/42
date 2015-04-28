/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/09 14:20:19 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/12 17:07:02 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_select.h>

void	exit_tools(void)
{
	t_term term;

	tputs(tgetstr("ve", NULL), 0, ret_putchar);
	tputs(tgetstr("rs", NULL), 0, ret_putchar);
	tputs(tgetstr("te", NULL), 0, ret_putchar);
	if (tcgetattr(0, &term) == -1)
		error_exit("tcgetattr error");
	term.c_lflag |= (ICANON);
	term.c_lflag |= (ECHO);
	if (tcsetattr(0, TCSADRAIN, &term) == -1)
		ft_putendl_fd("ft_select: tcsetattr error", 2);
}

void	proper_exit(t_lst *link)
{
	free_lst(link);
	exit_tools();
	exit(EXIT_SUCCESS);
}

void	error_exit(char *str)
{
	exit_tools();
	ft_putstr_fd("ft_select: ", 2);
	ft_putendl_fd(str, 2);
	exit(EXIT_FAILURE);
}
