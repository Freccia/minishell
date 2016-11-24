/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:46:56 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 17:04:34 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabpop(char **tab, size_t pop)
{
	char	**new;
	size_t	i;

	new = NULL;
	i = -1;
	if (tab)
	{
		new = ft_tabnew(ft_tablen(tab) - 1);
		while (++i < pop && *tab[i])
		{
			new[i] = ft_strdup(tab[i]);
		}
		while (*tab[++i])
		{
			new[i - 1] = ft_strdup(tab[i]);
		}
		new[i - 1] = NULL;
	}
	return (new);
}
