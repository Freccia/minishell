/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 16:45:41 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/23 16:51:17 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabnew(size_t size)
{
	char	**new;
	size_t	i;

	i = 0;
	if (size == 0 || (new = malloc(sizeof(new) * size)) == NULL)
		return (NULL);
	while (i < size)
	{
		new[i] = NULL;
		++i;
	}
	new[i] = NULL;
	return (new);
}
