/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:15 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:13:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static size_t	ft_parse_cmd(t_env *e)
{
	char	*trline;

	trline = ft_strxtrim(e->line, '\t');
	e->cmd = ft_strsplit(trline, ' ');
	
	ft_puttab(e->cmd);		//remove_me

	free(trline);
	e->cmd_len = ft_tablen(e->cmd);
	return (e->cmd_len);
}

static int		ft_exec_builtin(t_env *e)
{
	char	ret;

	ret = 0;
	if (!ft_strcmp(e->cmd[0], "exit") && ++ret)
		ft_exit(e);
	else if (!ft_strcmp(e->cmd[0], "env") && ++ret)
		ft_env(e);
	else if (!ft_strcmp(e->cmd[0], "setenv") && ++ret)
		ft_setenv(e);
	else if (!ft_strcmp(e->cmd[0], "unsetenv") && ++ret)
		ft_unsetenv_blt(e);
	else if (!ft_strcmp(e->cmd[0], "cd") && ++ret)
		ft_chdir(e);
	else if (!ft_strcmp(e->cmd[0], "echo") && ++ret)
		ft_echo(e);
	return (ret);
}

int			ft_parse_line(t_env *e)
{
	int		ret;

	ret = 0;
	if (ft_parse_cmd(e))
	{
		if ((ret = ft_exec_builtin(e)))
			;
		else
			ret = ft_exec(e);
	}
	ft_free_tab(e->cmd);
	return (ret);
}
