/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 17:33:14 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/30 19:38:28 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include <unistd.h>

static int	ft_chdir_error(char *path)
{
	if (access(path, F_OK) == -1)
		return (ft_error(path, "No such file or directory", NULL));
	else if (access(path, X_OK) == -1)
		return (ft_error(path, "permission denied: ", NULL));
	return (ft_error("cd", "unknown error: ", path));
}

static int	ft_chdir_env(t_env *e, char *dir)
{
	char	*pwd;
	char	*oldpwd;

	pwd = NULL;
	oldpwd = NULL;
	oldpwd = getcwd(oldpwd, 0);
	if (chdir(dir) == -1)
		return (ft_chdir_error(dir));
	pwd = getcwd(pwd, 0);
	ft_unsetenv(&e->env, "OLDPWD");
	ft_setenv(&e->env, "OLDPWD", oldpwd);
	ft_unsetenv(&e->env, "PWD");
	ft_setenv(&e->env, "PWD", pwd);
	free(oldpwd);
	free(pwd);
	return (0);
}

int			ft_chdir(t_env *e)
{
	if (e->cmd_len > 2)
		return (ft_error("cd", "too many arguments", NULL));
	if (e->cmd_len == 1)
	{
		if (!ft_issetenv(e->env, "HOME") && e->home == NULL)
			return (ft_error("cd", "no home set", NULL));
		return (ft_chdir_env(e, e->home));
	}
	if (ft_strequ(e->cmd[1], "-"))
	{
		free(e->cmd[1]);
		if ((e->cmd[1] = ft_find_value(e->env, "OLDPWD")) == NULL)
			return (ft_error("cd", "no oldpwd in env", NULL));
	}
	return (ft_chdir_env(e, e->cmd[1]));
}
