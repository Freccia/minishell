/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_quote.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbro <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 19:51:18 by lfabbro           #+#    #+#             */
/*   Updated: 2016/12/15 20:48:54 by lfabbro          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Description: behaves like ft_strsplit() but it holds in quote.
**		!!! It doesn't accept quote ('\"' || '\'') as a separator!
*/

static int		ft_count_words_q(char const *s, char c)
{
	int		i;
	int		count;
	char	quote;

	i = 0;
	count = 0;
	quote = '\0';
	while (s[i] != '\0')
	{
		if (quote == '\0')
			if ((i > 0 && s[i] != c && s[i - 1] == c) || (i == 0 && s[i] != c))
				++count;
		if (quote == '\0' && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote != '\0' && s[i] == quote)
			quote = '\0';
		++i;
	}
	return (count);
}

static int		ft_strlen_ch_q(char const *s, char c, int i)
{
	int		len;
	char	quote;

	len = 1;
	quote = '\0';
	while (s[i] != '\0')
	{
		if (quote == '\0' && s[i] == c)
			break ;
		if (quote == '\0' && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote != '\0' && s[i] == quote)
			quote = '\0';
		++i;
		++len;
	}
	return (len);
}

static char		*ft_strcpy_ch_q(char const *s, char c, int i)
{
	int		k;
	char	*str;
	char	quote;

	k = 0;
	quote = '\0';
	if ((str = ft_strnew(ft_strlen_ch_q(s, c, i) + 1)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		if (quote == '\0' && s[i] == c)
			break ;
		if (quote == '\0' && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote != '\0' && s[i] == quote)
			quote = '\0';
		else
			str[k++] = s[i];
		++i;
	}
	str[k] = '\0';
	return (str);
}

int				ft_skip_word_q(char const *s, char c, int i)
{
	int		len;
	char	quote;

	len = 0;
	quote = '\0';
	while (s[i] != '\0')
	{
		if (quote == '\0' && s[i] == c)
			break ;
		if (quote == '\0' && (s[i] == '\'' || s[i] == '\"'))
			quote = s[i];
		else if (quote != '\0' && s[i] == quote)
			quote = '\0';
		++i;
		++len;
	}
	return (len);
}

char			**ft_strsplit_quote(char const *s, char c)
{
	int		i;
	int		k;
	int		nwords;
	char	**tab;

	nwords = ft_count_words_q(s, c);
	if (s != NULL && c != '\'' && c != '\"' && nwords)
	{
		if (!(tab = ft_tabnew(nwords)))
			return (NULL);
		i = 0;
		k = 0;
		while (k < nwords && s[i] != '\0')
		{
			while (s[i] == c)
				++i;
			if ((tab[k] = ft_strcpy_ch_q(s, c, i)) == NULL)
				return (NULL);
			i += ft_skip_word_q(s, c, i);
			++k;
		}
		tab[k] = NULL;
		return (tab);
	}
	return (NULL);
}
