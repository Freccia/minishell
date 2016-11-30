/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 13:10:33 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/30 22:23:45 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <unistd.h>
# include <dirent.h>
# include <sys/wait.h>
# include <signal.h>
# include "libft.h"

# define PATH		"/usr/bin:/bin:/usr/sbin:/sbin"

typedef struct		s_env
{
	int				x;
	int				exit;
	char			**env;
	char			*prompt;
	char			*home;
	char			*line;
	char			**cmd;
	size_t			cmd_len;
	int				cmd_exit_stat;
}					t_env;

int					ft_parse_line(t_env *e);
int					ft_exec(char **cmd, char **env);
int					ft_error(char *util, char *msg, char *what);

/*
**		Init
*/
void				ft_init(t_env *e, int ac, char **av, char **env);

/*
**		Signals
*/
int					ft_handle_ret_signal(int status);
void				ft_set_sig_handler(void);
void				ft_sig_handler(int sig);

/*
**		Tools
*/
int					ft_issetenv(char **env, char *name);
void				ft_env_free(t_env *e);
char				*ft_find_name(char **env, char *name);
char				*ft_find_value(char **env, char *name);

/*
**		Builtins
*/
void				ft_exit(t_env *e);
int					ft_env(t_env *e);
int					ft_setenv_blt(t_env *e);
int					ft_setenv(char ***env, char *name, char *value);
int					ft_unsetenv_blt(t_env *e);
int					ft_unsetenv(char ***env, char *name);
int					ft_chdir(t_env *e);
//int					ft_echo(t_env *e);

#endif
