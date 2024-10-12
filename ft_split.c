/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khlavaty <khlavaty@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 14:48:47 by khlavaty          #+#    #+#             */
/*   Updated: 2023/02/06 15:25:56 by khlavaty         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fts_wordcount(char const *s, char c)
{
	size_t	i;
	int		wordcount;

	i = 0;
	wordcount = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != '\0')
			wordcount++;
		while (s[i] && (s[i] != c))
			i++;
	}
	return (wordcount);
}

static unsigned int	fts_strxcpy(char *dest, const char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	x;

	x = 0;
	while (src[x])
		x++;
	i = 0;
	if (size != 0)
	{
		while ((i < size - 1) && src[i] != '\0')
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	return (x);
}

static char	*fts_strndup(const char *s, size_t n)
{
	char	*str;

	str = (char *)malloc(sizeof(char) * (n + 1));
	if (str == NULL)
		return (NULL);
	fts_strxcpy(str, s, n + 1);
	return (str);
}

static char	**fts_cutsplit(char const *s, char c)
{
	char	**str;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	str = (char **)malloc(sizeof(char *) * (fts_wordcount(s, c) + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		k = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > k)
		{
			str[j] = fts_strndup(s + k, i - k);
			j++;
		}
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	if (!s || !*s)
	{
		str = (char **)malloc(sizeof(char *));
		if (str == NULL)
			return (NULL);
		str[0] = NULL;
		return (str);
	}
	str = fts_cutsplit(s, c);
	return (str);
}
