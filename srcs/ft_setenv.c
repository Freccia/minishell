/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:16:46 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:28:10 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static char		*ft_setentry(char *name, char *value)
{
	char	*tmp;
	char	*entry;

	tmp = ft_strjoin(name, "=");
	entry = ft_strjoin(tmp, value);
	free(tmp);
	return (entry);
}

int				ft_setenv(char ***env, char *name, char *value)
{
	int		i;
	char	*entry;
	char	**tmp;

	i = 0;
	entry = ft_setentry(name, value);
	while (*env[i])
	{
		if (ft_strnequ(*env[i], name, ft_strlen(name)))
		{
			free(*env[i]);
			*env[i] = entry;
			return (0);
		}
	}
	tmp = ft_tabcat(*env, entry);
	ft_free_tab(*env);
	*env = tmp;
	return (0);
}
