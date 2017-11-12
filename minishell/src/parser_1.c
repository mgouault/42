/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/19 19:35:58 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/05 23:54:15 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

static void		do_eof(t_var *v)
{
	try_exit(NULL, TRUE);
	v->key = K_ENTER;
}

static char		*bread(int fd)
{
	char	*b;
	short	r;

	b = (char *)ft_memalloc(sizeof(char) * 6 + 1);
	ft_bzero(b, 7);
	if ((r = read(fd, b, 6)) == -1)
		error_exit("ft_minishell1: read on /dev/stdin error");
	b[r] = 0;
	return (b);
}

static char		**parser__(char **line, char ***tmp, t_var *v, t_line **history)
{
	if (v->key == K_EOF && !(**line))
		do_eof(v);
	else if (v->key == K_DELETE && v->cursor > v->begin)
		delete_char(line, v, v->cursor - v->begin);
	else if (v->key == K_UP && history)
		line = to_up(line, tmp, v, history);
	else if (v->key == K_DOWN && history)
		line = to_down(line, tmp, v, history);
	else if (v->key == K_TAB && ft_strchr(*line, ' '))
		completion(line, v);
	return (line);
}

static char		**parser_(char **line, t_var *v, t_line *history)
{
	char *b;
	char **tmp;

	tmp = NULL;
	while (v->key != K_ENTER)
	{
		b = bread(0);
		v->key = gekie(b);
		if (v->key == K_TILDE)
			b = do_tilde(b);
		if (v->key == K_LEFT && v->cursor > v->begin)
			to_left(v);
		else if (v->key == K_RIGHT && v->cursor < v->end)
			to_right(v);
		else if (v->key == K_CLEAR)
			do_clear(v, line);
		else if (v->key == K_NONE || v->key == K_TILDE)
			print_char(line, b, v, v->cursor - v->begin);
		else
			line = parser__(line, &tmp, v, &history);
		(void)getsing_cursor(v->cursor);
		(void)getsing_line(*line);
		free(b);
	}
	return (line);
}

char			*parser(t_line *history)
{
	char	**line;
	char	*pute;
	t_var	*v;

	init_term();
	history = history_dup(history);
	v = (t_var *)ft_memalloc(sizeof(t_var));
	tputs(tgetstr("sc", NULL), 0, ret_putchar);
	v->begin = prompt();
	pute = ft_strdup("");
	line = &pute;
	v->cursor = v->begin;
	v->end = v->begin;
	v->key = K_NONE;
	line = parser_(line, v, history);
	endline(v->end - v->cursor);
	exit_term();
	return (ft_strdup(*line));
}
