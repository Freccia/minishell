/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 20:03:34 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/26 15:02:47 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

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
				value = ft_strdup(ft_strchr(tab[i], '=') + 1);
				free(entry);
				return (value);
			}
		}
	}
	free(entry);
	return (value);
}
