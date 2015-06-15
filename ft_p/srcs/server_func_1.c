/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 17:35:04 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 15:37:43 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

extern char	*g_pwd;

int			confirm_exec(int *r, char *error, int if_put)
{
	unsigned char *data;

	if (error)
	{
		if (ft_send((unsigned char *)ft_strdup(error), ft_strlen(error)) == -1)
			return (-1);
		free(error);
	}
	else
	{
		*r = 1;
		if (ft_send((unsigned char *)ft_strdup("AGREED"), 6) == -1)
			return (-1);
		if (!if_put)
		{
			if (ft_recv(&data, NULL) == -1)
				return (-1);
			if (!ft_strequ((char *)data, "GO"))
				return (ft_error("transmission error"));
		}
	}
	return (0);
}

static int	get_access(char *path, char **error)
{
	struct stat	st;
	int			fd;

	if ((fd = open(path, 0)) == -1)
	{
		*error = ft_strdup("can't access target");
		return (0);
	}
	if (fstat(fd, &st) == -1)
		return (ft_error("stat() error"));
	else if (S_ISDIR(st.st_mode) == 0)
		*error = ft_strdup("not a directory");
	else if (S_ISDIR(st.st_mode) == 1 && (00400 & st.st_mode))
	{
		if (close(fd) == -1)
			return (ft_error("close() error"));
		return (1);
	}
	if (close(fd) == -1)
		return (ft_error("close() error"));
	return (0);
}

static char	*check_cd(char *arg, char *error)
{
	char	*tmp1;
	char	*tmp2;
	t_bool	restricted;

	if (!arg)
		return (ft_strdup("no target given"));
	if (*arg == '/')
		return (ft_strdup("invalid target (no targets \"/<path>\" allowed)"));
	restricted = FALSE;
	tmp1 = ft_strjoin(g_pwd, "/");
	tmp2 = resolve_path(ft_strjoin(tmp1, arg), &restricted);
	free(tmp1);
	error = NULL;
	if (restricted)
		error = ft_strdup("can't cd under \"/\"");
	else if (get_access(arg, &error) == -1)
		return ("error");
	free(tmp2);
	return (error);
}

static int	check_exec(char *cmd, unsigned char *arg, int *r)
{
	char *error;

	error = NULL;
	if (ft_strequ(cmd, "cd"))
		error = check_cd((char *)arg, error);
	if (error && ft_strequ(error, "error"))
		return (-1);
	if (confirm_exec(r, error, ft_strequ(cmd, "put")) == -1)
		return (-1);
	return (0);
}

int			s_exec_cmd(unsigned char *cmd, unsigned char *arg, int r)
{
	if (check_exec((char *)cmd, arg, &r) == -1)
		return (-1);
	if (!r)
		return (0);
	if (ft_strequ((char *)cmd, "pwd") && ft_send((unsigned char *)\
		ft_strjoin(g_pwd, "\n"), ft_strlen(g_pwd) + 1) == -1)
		return (-1);
	else if (ft_strequ((char *)cmd, "ls"))
		s_ls((char *)arg);
	else if (ft_strequ((char *)cmd, "cd"))
	{
		if (chdir((char *)arg) == -1)
			return (ft_error("chdir() error"));
		cmd = (unsigned char *)ft_strjoin(g_pwd, "/");
		g_pwd = resolve_path((char *)ft_strjoin((char *)cmd, \
			(char *)arg), NULL);
		free(cmd);
		if (ft_send((unsigned char *)ft_strdup("EMPTY_SCUMBAG4242"), 17) == -1)
			return (-1);
	}
	return (0);
}
