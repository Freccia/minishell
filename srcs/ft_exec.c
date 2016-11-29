/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:22:08 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/28 17:28:14 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_find_exec_readdir(DIR *dir, char *cmd)
{
	struct dirent	*dirent;

	while ((dirent = readdir(dir)) != NULL)
	{
		if (ft_strequ(dirent->d_name, cmd))
		{
			return (ft_strdup(dirent->d_name));
		}
	}
	return (NULL);
}

char			*ft_find_exec(char **paths, char *cmd)
{
	DIR				*dir;
	char			*exec;
	char			*path;
	char			*tmp;
	int				i;

	i = -1;
	exec = NULL;
	path = NULL;
	while (paths[++i])
	{
		if ((dir = opendir(paths[i])) != NULL)
		{
			exec = ft_find_exec_readdir(dir, cmd);
			if (closedir(dir))
				ft_error("closedir", "failed closing dir", paths[i]);
			if (exec != NULL)
			{
				tmp = ft_strjoin(paths[i], "/");
				path = ft_strjoin(tmp, exec);
				free(tmp);
				free(exec);
				return (path);
			}
		}
	}
	return (path);
}

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

int				ft_exec(char **cmd, char **env)
{
//	pid_t	parent;
	pid_t	pid;
	int		status;
	char	**paths;
	char	*exec;

	paths = ft_find_paths(env);
	if ((exec = ft_find_exec(paths, cmd[0])) == NULL)
	{
		ft_free_tab(paths);
		return (ft_error(cmd[0], "command not found", NULL));
	}
//	parent = getpid();
	if ((pid = fork()) < 0)
	{
		ft_error("fork", "failed to fork process", NULL);
	}
	else if (pid == 0)
	{
		execve(exec, &cmd[0], env);
	}
	waitpid(pid, &status, 0);
	ft_free_tab(paths);
	free(exec);
	return (status);
}
