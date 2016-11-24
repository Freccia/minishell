/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsetenv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 17:05:01 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:19:13 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_unsetenv(char ***env, char *name)
{
	size_t	pos;
	char	**tmp;

	pos = 0;
	while (*env[pos])
	{
		if (ft_strnequ(*env[pos], name, ft_strlen(name)))
		{
			tmp = ft_tabpop(*env, pos);
			ft_free_tab(*env);
			*env = tmp;
			return (0);
		}
	}
	return (-1);
}

int			ft_unsetenv_blt(t_env *e)
{
	int		i;

	i = 0;
	if (e->cmd_len > 1)
	{
		while (++i < e->cmd_len)
			ft_unsetenv(&e->env, e->cmd[i]);
	}
	else
		ft_putendl("unsetenv: too few arguments");
	return (0);
}
