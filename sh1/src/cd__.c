/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd__.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgouault <mgouault@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/05 22:05:31 by mgouault          #+#    #+#             */
/*   Updated: 2015/04/21 14:27:50 by mgouault         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_minishell1.h>

void		update_env_oldpwd(void)
{
	t_env	*link;
	char	*tmp;

	if (!(tmp = get_pwd(0)))
		return ;
	if (!(link = search_env("OLDPWD", FALSE)))
		add_env("OLDPWD", tmp);
	else
		replace_env("OLDPWD", tmp);
	free(tmp);
}

void		update_env_pwd(char *target)
{
	t_env	*link;

	if (!(link = search_env("PWD", FALSE)))
		add_env("PWD", target);
	else
		replace_env("PWD", target);
	free(target);
}
