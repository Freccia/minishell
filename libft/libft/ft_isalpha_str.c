/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 18:34:23 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/25 18:35:20 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isalpha_str(char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (0);
		++str;
	}
	return (1);
}
