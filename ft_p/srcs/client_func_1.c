/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_func_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 21:04:44 by mgouault          #+#    #+#             */
/*   Updated: 2015/06/05 15:34:06 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_p.h>

int			exec_notfound(char *cmd, char *input, char *opt)
{
	(void)input;
	(void)opt;
	if (cmd && !ft_isspace_str(cmd))
		ft_printf("ERROR: %s: command not found\n", cmd);
	return (0);
}

int			exec_quit(char *cmd, char *input, char *opt)
{
	(void)cmd;
	(void)input;
	(void)opt;
	if (ft_send((unsigned char *)ft_strdup("quit"), 4) == -1)
		return (-1);
	ft_putendl("SUCCESS: quit");
	return (0);
}

int			request_exec(char *cmd, unsigned char *input)
{
	unsigned char	*tmp1;
	unsigned char	*tmp2;
	unsigned char	*data;

	tmp1 = (unsigned char *)ft_strjoin(cmd, " ");
	tmp2 = (unsigned char *)ft_strjoin((char *)tmp1, (char *)input);
	free(tmp1);
	if (ft_send(tmp2, ft_strlen_uc(tmp2)) == -1)
		return (-1);
	if (ft_recv(&data, NULL) == -1)
		return (-1);
	if (ft_strequ((char *)data, "AGREED"))
	{
		free(data);
		if (ft_strequ(cmd, "pwd") || ft_strequ(cmd, "ls"))
			ft_printf("SUCCESS: %s\n", cmd);
		else
			ft_printf("SUCCESS: %s %s\n", cmd, input);
		return (1);
	}
	else
		ft_printf("ERROR: %s %s: %s\n", cmd, input, data);
	free(data);
	return (0);
}

int			c_exec_cmd(char *cmd, char *input, char *opt)
{
	unsigned char	*data;
	short			r;

	if (ft_strequ(cmd, "ls") && input && input[0] == '-')
	{
		cmd = ft_strjoin(cmd, " ");
		data = (unsigned char *)cmd;
		cmd = ft_strjoin(cmd, input);
		free(data);
		input = opt;
	}
	if (!input)
		input = ft_strdup("");
	r = request_exec(cmd, (unsigned char *)input);
	if (r < 1)
		return ((r == 0) ? 0 : -1);
	if (ft_send((unsigned char *)ft_strdup("GO"), 2) == -1)
		return (-1);
	if (ft_recv(&data, NULL) == -1)
		return (-1);
	if (!ft_strequ(cmd, "cd") && !ft_strequ((char *)data, "EMPTY_SCUMBAG4242"))
		ft_putstr((char *)data);
	return (0);
}
