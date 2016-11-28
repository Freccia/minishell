/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:35:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/28 12:29:46 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcat(char **tab, char *str)
{
	char	**tmp;
	size_t	len;

	tmp = NULL;
	if (tab && *tab && str)
	{
		len = ft_tablen(tab);
		tmp = ft_tabnew(len + 2);
		tmp = ft_tabcpy(tmp, tab);
		tmp[len] = ft_strdup(str);
	}
	else if (str)
	{
		tmp = ft_tabnew(2);
		tmp[0] = ft_strdup(str);
	}
	return (tmp);
}
