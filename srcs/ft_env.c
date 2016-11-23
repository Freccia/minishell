/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 17:24:45 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/23 20:55:42 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

static int	ft_opt_i_populate(char ***env_cpy, int i)
{

}

static int	ft_opt_i(char ***env_cpy, int i)
{
	int		j;
	size_t	size;

	size = 0;
	j = i;
	ft_free_tab(*env_cpy);
	while (ft_strchr(*env_cpy[++j]))
		++size;
	*env_cpy = ft_tabnew(size);
	if (!size)
		return (0);
	ft_opt_i_populate(env_cpy, i);
	return (0);
}

/*
   static int	ft_opt_u(char ***env_cpy, int i)
   {

   }
   */

static int	ft_env_opt(t_env *e, char ***env_cpy)
{
	int		i;

	i = 0;
	while (e->cmd[++i] && e->cmd[i][0] == '-')
	{
		if(e->cmd[i][1] == 'i')
			ft_opt_i(env_cpy, i);
		//	else if (e->cmd[i][1] == 'u')
		//		ft_opt_u(env_cpy, i);
		else
			ft_env_error(ILL_OPT, e->cmd[i][1]);
	}
}

int			ft_env(t_env *e)
{
	char	**env_cpy;

	env_cpy = ft_tabdup(e->env);
	if (e->cmd_len > 1)
	{
		if (ft_env_opt(e, &env_cpy) > 0)
		{
			ft_exec_util();
		}
	}
	else
		ft_puttab(env_cpy);
	return (0);
}
