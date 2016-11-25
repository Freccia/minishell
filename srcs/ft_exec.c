/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:22:08 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 20:58:39 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char			**ft_find_paths(char **env)
{
	char	*value;
	char	**paths;

	paths = NULL;
	value = NULL;
	if ((value = ft_find_value(env, "PATH")) == NULL)
		paths = ft_strsplit(PATH, ':');
	else
	{
		paths = ft_strsplit(value, ':');
		free(value);
	}
	return (paths);
}

//pid_t parent = getpid();
//pid_t pid = fork();
//
//if (pid == -1)
//{
//		error, failed to fork()
//} 
//else if (pid > 0)
//{
//		int status;
//		waitpid(pid, &status, 0);
//}
//else 
//{
//		// we are the child
//		execve(...);
//		_exit(EXIT_FAILURE);   // exec never returns
//}

int				ft_exec(char **cmd, char **env)
{
	pid_t	parent;
	pid_t	pid;
	int		status;
	char	**paths;
	char	*exec;

	paths = ft_find_paths(env);
	if ((exec = ft_find_exec(paths, cmd[0])) == NULL)
		return (ft_error(cmd[0], "command not found", NULL));
	parent = getpid();
	pid = fork();
	if (pid < 0)
		ft_error("fork", "failed to fork process", NULL);
	else if (pid == 0)
	{
		ft_printf("execve executing %s\n", exec);
		ft_printf("arguments:\n");
		ft_printf("%s\n", cmd[1]);
		ft_puttab(&cmd[1]);
		execve(exec, &cmd[1], env);
	}
	else
	{
		ft_printf("waiting...\n");
		waitpid(pid, &status, 0);
	}
	return (0);
}
