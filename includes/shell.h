/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:10:33 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 18:15:02 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include			<unistd.h>
# include			"libft.h"

# define E_ILLOPT	44
# define E_NOENT	45

typedef struct		s_env
{
	char			*line;
	char			*prompt;
	char			**env;
	char			**cmd;
	size_t			cmd_len;
	int				ft_errno;
	int				exit;
}					t_env;

int					ft_parse_line(t_env *e);

//void				ft_exec_cmd(t_env *e);
int					ft_error(char *util, char *msg, char *what);

/*
**		BUILTINS
*/
void				ft_exit(t_env *e);
int					ft_env(t_env *e);
int					ft_setenv_blt(t_env *e);
int					ft_setenv(char ***env, char *name, char *value);
int					ft_unsetenv_blt(t_env *e);
int					ft_unsetenv(char ***env, char *name);
//int					ft_chdir(t_env *e);
//int					ft_echo(t_env *e);

#endif
