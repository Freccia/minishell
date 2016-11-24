/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:35:54 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:28:23 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcat(char **tab, char *str)
{
	char	**tmp;
	size_t	len;

	tmp = NULL;
	if (tab && str)
	{
		len = ft_tablen(tab) + 1;
		tmp = ft_tabnew(len);
		ft_tabcpy(tmp, tab);
		tmp[len] = ft_strdup(str);
	}
	return (tmp);
}
