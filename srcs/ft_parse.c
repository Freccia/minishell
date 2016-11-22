/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:15 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/22 18:31:21 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_parse_cmd(t_env *e, char *line)
{
	char	*trline;

	trline = ft_strxtrim(line, '\t');
	e->cmd = ft_strsplit(trline, ' ');
	ft_puttab(e->cmd);		//remove_me
	free(trline);
}

static int	ft_isbuiltin(t_env *e)
{
	char	ret;

	ret = 0;
	if (!ft_strcmp(e->cmd[1], "exit") && ++ret)
		ft_exit(e);
	else if (!ft_strcmp(e->cmd[1], "env") && ++ret)
		ft_env(e);
	else if (!ft_strcmp(e->cmd[1], "setenv") && ++ret)
		ft_setenv(e);
	else if (!ft_strcmp(e->cmd[1], "unsetenv") && ++ret)
		ft_unsetenv(e);
	else if (!ft_strcmp(e->cmd[1], "cd") && ++ret)
		ft_chdir(e);
	else if (!ft_strcmp(e->cmd[1], "echo") && ++ret)
		ft_echo(e);
	return (ret);
}

int			ft_parse_line(t_env *e, char *line)
{
	ft_parse_cmd(e, line);
	if (ft_exec_builtin(e))
		;
	else
		ft_exec_cmd(e);
	ft_free_tab(e->cmd);
	return (0);
}
