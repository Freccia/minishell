/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 16:39:39 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/24 16:58:26 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_tabcpy(char **dst, char **src)
{
	int		i;

	i = -1;
	while (src[++i])
	{
		dst[i] = ft_strdup(src[i]);
	}
	dst[i] = NULL;
	return (dst);
}
