/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bigjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/10 17:29:57 by mgouault          #+#    #+#             */
/*   Updated: 2015/03/23 00:22:40 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void	ft_fill_arg(char *input, int i, va_list ap, char **bigjoin)
{
	char *tmp;
	char *tmp2;

	tmp = *bigjoin;
	if (input[i + 1] == 's')
	{
		*bigjoin = ft_strjoin(*bigjoin, va_arg(ap, char *));
		free(tmp);
	}
	else if (input[i + 1] == 'd')
	{
		tmp2 = ft_itoa(va_arg(ap, int));
		*bigjoin = ft_strjoin(*bigjoin, tmp2);
		free(tmp);
		free(tmp2);
	}
}

static int	ft_isvalidarg(char *input, int i)
{
	if (input[i] == '%')
	{
		if ((input[i + 1] == 's') || (input[i + 1] == 'd'))
			return (1);
	}
	return (0);
}

static int	ft_bigjoin_(char *input, int i, char **bigjoin)
{
	char *tmp;
	char *tmp2;

	tmp = *bigjoin;
	if ((input[i] == '%') && (input[i + 1] == '%'))
	{
		tmp2 = ft_strdup("0");
		tmp2[0] = '%';
		*bigjoin = ft_strjoin(*bigjoin, tmp2);
		i += 2;
	}
	else
	{
		tmp2 = ft_strdup("0");
		tmp2[0] = input[i];
		*bigjoin = ft_strjoin(*bigjoin, tmp2);
		++i;
	}
	free(tmp);
	free(tmp2);
	return (i);
}

char		*ft_bigjoin(char *format, ...)
{
	va_list ap;
	int		i;
	char	*input;
	char	*bigjoin;

	va_start(ap, format);
	input = (char *)format;
	bigjoin = ft_strdup("");
	i = 0;
	while (input[i])
	{
		if (ft_isvalidarg(input, i))
		{
			ft_fill_arg(input, i, ap, &bigjoin);
			i += 2;
		}
		else
			i = ft_bigjoin_(input, i, &bigjoin);
	}
	va_end(ap);
	return (bigjoin);
}
