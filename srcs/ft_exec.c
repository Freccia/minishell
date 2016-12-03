/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 19:22:08 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/30 17:38:31 by lfabbro          ###   ########.fr       */
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

static char		*ft_find_exec(char **paths, char *cmd)
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
	return (NULL);
}

static char		**ft_find_paths(char **env)
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

static int		ft_fork_exec(char *exec, char **cmd, char **env)
{
	pid_t	pid;
	int		status;

	status = 0;
	if ((pid = fork()) < 0)
	{
		ft_error("fork", "failed to fork process", NULL);
	}
	else if (pid == 0)
	{
		execve(exec, &cmd[0], env);
	}
	waitpid(pid, &status, WUNTRACED);
	ft_handle_ret_signal(status);
	return (status);
}

int				ft_exec(char **cmd, char **env)
{
	int		status;
	char	**paths;
	char	*exec;

	status = 0;
	exec = NULL;
	paths = ft_find_paths(env);
	if (cmd[0][0] == '.' || cmd[0][0] == '/')
		exec = ft_strdup(cmd[0]);
	else
		exec = ft_find_exec(paths, cmd[0]);
	if (exec == NULL)
	{
		ft_free_tab(paths);
		return (ft_error(cmd[0], "command not found", NULL));
	}
	if (access(exec, X_OK) == 0 || ft_issticky(exec))
	{
		status = ft_fork_exec(exec, cmd, env);
	}
	else
		ft_error(exec, "permission denied", NULL);
	ft_free_tab(paths);
	free(exec);
	return (status);
}
