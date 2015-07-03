/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/16 11:28:52 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/15 22:19:25 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void ft_print_arg(char *input, int i, va_list ap)
{
	if (input[i + 1] == 's')
		ft_putstr(va_arg(ap, char *));
	else if (input[i + 1] == 'd')
		ft_putnbr(va_arg(ap, int));
	else if (input[i + 1] == 'c')
		ft_putchar(va_arg(ap, int));
}

static int	ft_isvalidarg(char *input, int i)
{
	if (input[i] == '%')
	{
		if ((input[i + 1] == 's') || (input[i + 1] == 'd') ||
			(input[i + 1] == 'c'))
			return (1);
	}
	return (0);
}

static int	ft_printf_(char *input, int i, va_list ap)
{
	if (ft_isvalidarg(input, i))
	{
		ft_print_arg(input, i, ap);
		i += 2;
	}
	else
	{
		if (input[i] != '%')
			ft_putchar(input[i++]);
		else if ((input[i] == '%') && (input[i + 1] == '%'))
		{
			ft_putchar('%');
			i += 2;
		}
	}
	return (i);
}

int			ft_printf(char *format, ...)
{
	va_list ap;
	int		i;
	char	*input;

	va_start(ap, format);
	input = (char *)format;
	i = 0;
	while (input[i])
		i = ft_printf_(input, i, ap);
	va_end(ap);
	return (0);
}
