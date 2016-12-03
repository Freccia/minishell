/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:55:15 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/29 19:08:33 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

/*
 * $1, $2, $3, ... are the positional parameters.
 * "$@" is an array-like construct of all positional parameters, {$1, $2, $3 ...}.
 * "$*" is the IFS expansion of all positional parameters, $1 $2 $3 ....
 * $# is the number of positional parameters.
 * $- current options set for the shell.
 * $$ pid of the current shell (not subshell).
 * $_ most recent parameter (or the abs path of the command to start the current shell immediately after startup).
 * $IFS is the (input) field separator.
 * $? is the most recent foreground pipeline exit status.
 * $! is the PID of the most recent background command.
 * $0 is the name of the shell or shell script.
 */

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

static char		**ft_parse_cmd(t_env *e)
{
	char	**cmds;
	char	*trline;

	trline = ft_strxtrim(e->line, '\t');
	cmds = ft_strsplit(trline, ';');
	//	ft_subspecials(&e->cmd);
	free(trline);
	return (cmds);
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
	else if (ft_strequ(e->cmd[0], "cd") && ++ret)
		ft_chdir(e);
	/*
	   else if (ft_strequ(e->cmd[0], "echo") && ++ret)
	   ft_echo(e);
	   */
	return (ret);
}

int			ft_parse_line(t_env *e)
{
	int		i;
	int		ret;
	char	**cmds;

	i = -1;
	ret = 0;
	if ((cmds = ft_parse_cmd(e)) != NULL)
	{
		while (cmds[++i])
		{
			e->cmd = ft_strsplit(cmds[i], ' ');
			e->cmd_len = ft_tablen(e->cmd);
			if (e->cmd_len)
			{
				if ((ret = ft_exec_builtin(e)))
					;
				else
					ret = ft_exec(e->cmd, e->env);
			}
			e->cmd_exit_stat = ret;
			ft_free_tab(e->cmd);
		}
	}
	return (ret);
}
