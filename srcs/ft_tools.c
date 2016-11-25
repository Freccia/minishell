/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:34 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 20:58:40 by lfabbro          ###   ########.fr       */
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
				return (path);
			}
		}
	}
	return (path);
}

char		*ft_find_value(char **tab, char *name)
{
	char	*entry;
	char	*value;
	int		i;

	i = -1;
	entry = ft_strjoin(name, "=");
	value = NULL;
	if (tab)
	{
		while (tab[++i])
		{
			if (ft_strnequ(tab[i], entry, ft_strlen(entry)))
			{
				value = ft_strdup(ft_strchr(tab[i], '='));
				free(entry);
				return (value);
			}
		}
	}
	free(entry);
	return (value);
}
