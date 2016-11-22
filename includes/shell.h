/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:10:33 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/22 18:31:27 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include			<unistd.h>
# include			"libft.h"

typedef struct		s_env
{
	char			*prompt;
	char			**env;
	char			**cmd;
	int				ft_errno;
}					t_env;

int					ft_parse_line(t_env *e, char *line);

void				ft_exec_cmd(t_env *e);

/*
**		BUILTINS
*/
void				ft_exit(t_env *e);
void				ft_env(t_env *e);
void				ft_setenv(t_env *e);
void				ft_unsetenv(t_env *e);
void				ft_chdir(t_env *e);
void				ft_echo(t_env *e);

#endif
