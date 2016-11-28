/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:15 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/28 14:25:43 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
static int		ft_subspecials(char ***cmd)
{
	int		i;

	i = -1;
	while (*cmd[++i])
	{
		if (ft_strstr(*cmd[i], "$$"))
		{
			ft_subspec();
		}
	}
	return (0);
}
*/

static size_t	ft_parse_cmd(t_env *e)
{
	char	*trline;

	trline = ft_strxtrim(e->line, '\t');
	e->cmds = ft_strsplit(trline, ';');
//	ft_subspecials(&e->cmd);
	free(trline);
	return ((e->cmds == NULL) ? 0 : 1);
}

static int		ft_exec_builtin(t_env *e)
{
	char	ret;

	ret = 0;
	if (ft_strequ(e->cmd[0], "exit") && ++ret)
		ft_exit(e);
	else if (ft_strequ(e->cmd[0], "env") && ++ret)
		ft_env(e);
	else if (ft_strequ(e->cmd[0], "setenv") && ++ret)
		ft_setenv_blt(e);
	else if (ft_strequ(e->cmd[0], "unsetenv") && ++ret)
		ft_unsetenv_blt(e);
	/*
	else if (ft_strequ(e->cmd[0], "cd") && ++ret)
		ft_chdir(e);
	else if (ft_strequ(e->cmd[0], "echo") && ++ret)
		ft_echo(e);
		*/
	return (ret);
}

int			ft_parse_line(t_env *e)
{
	int		i;
	int		ret;

	i = -1;
	ret = 0;
	if (ft_parse_cmd(e))
	{
		while (e->cmds[++i])
		{
			e->cmd = ft_strsplit(e->cmds[i], ' ');
			e->cmd_len = ft_tablen(e->cmd);
			if ((ret = ft_exec_builtin(e)))
				;
			else
				e->cmd_exit_stat = ft_exec(e->cmd, e->env);
			ft_free_tab(e->cmd);
		}
	}
	ft_free_tab(e->cmds);
	e->cmds = NULL;
	return (ret);
}
