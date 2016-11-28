/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:15:17 by lfabbro           #+#    #+#             */
/*   Updated: 2016/11/28 13:21:31 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if ((i > 0 && s[i] != c && s[i - 1] == c)
				|| (i == 0 && s[i] != c))
			count++;
		i++;
	}
	return (count);
}

static int		ft_strlen_ch(char const *s, char c, int i)
{
	int	len;

	len = 1;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static char		*ft_strcpy_ch(char const *s, char c, int i)
{
	int		k;
	char	*str;

	k = 0;
	str = (char *)malloc(sizeof(*str) * (ft_strlen_ch(s, c, i) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i] != c && s[i] != '\0')
	{
		str[k] = s[i];
		k++;
		i++;
	}
	str[k] = '\0';
	return (str);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		k;
	char	**tab;

	if (s != NULL)
	{
		if (!(tab = (char **)malloc(sizeof(tab) * (ft_count_words(s, c) + 1))))
			return (NULL);
		i = 0;
		k = 0;
		while (i < ft_count_words(s, c) && s[k] != '\0')
		{
			while (s[k] == c)
				k++;
			tab[i] = ft_strcpy_ch(s, c, k);
			if (tab[i] == NULL)
				return (NULL);
			while (s[k] != c && s[k] != '\0')
				k++;
			i++;
		}
		tab[i] = NULL;
		return (tab);
	}
	return (NULL);
}
