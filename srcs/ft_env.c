/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:24:45 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:30:31 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_opt_i(t_env *e, char ***env_cpy, int i)
{
	char	**tmp;

	tmp = NULL;
	ft_free_tab(*env_cpy);
	*env_cpy = ft_tabnew(5);
	while (++i < e->cmd_len && ft_strchr(e->cmd[i], '='))
	{
		tmp = ft_tabcat(*env_cpy, e->cmd[i]);
		ft_free_tab(*env_cpy);
		*env_cpy = tmp;
	}
}

static int	ft_env_opt(t_env *e, char ***env_cpy)
{
	int		i;

	i = 0;
	while (++i < e->cmd_len)
	{
		if (e->cmd[i][0] == '-')
		{
			if (e->cmd[i][1] == 'u')
				ft_unsetenv(env_cpy, e->cmd[i + 1]);
			else if (e->cmd[i][1] == 'i')
				return (ft_opt_i(e, env_cpy, i));
		}
	}
	return (i);
}

int			ft_env(t_env *e)
{
	char	**env_cpy;

	env_cpy = ft_tabdup(e->env);
	if (e->cmd_len > 1)
	{
		if (ft_env_opt(e, &env_cpy) > 0)
		{
			ft_exec(e, env_cpy);
		}
	}
	else
		ft_puttab(env_cpy);
	return (0);
}
