/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:00 by lyie              #+#    #+#             */
/*   Updated: 2020/12/06 18:21:20 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <string.h>

char	*ft_strdup(char *src)
{
	int		size;
	char	*dest;
	int		i;

	i = 0;
	size = ft_strlen(src);
	if (!(dest = malloc(sizeof(char) * (ft_strlen(src) + 1))))
		return (NULL);
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (i);
		i++;
	}
	if (s[i] == c)
		return (i);
	return (-1);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if ((!(dest)) || (!(src)))
		return (0);
	while (src[i])
	{
		i++;
	}
	if (size == 0)
		return (i);
	while (src[j] && j < (size - 1))
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2, int store)
{
	char	*cat;
	int		size;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == NULL)
	{
		if (!(cat = malloc(sizeof(char) * store + 1)))
			return (NULL);
		ft_strlcpy(cat, s2, store + 1);
		return (cat);
	}
	size = (ft_strlen((char *)s1)) + store;
	if (!(cat = malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (s1[++i] != '\0')
		cat[i] = s1[i];
	while (++j < store)
		cat[i + j] = s2[j];
	cat[i + j] = '\0';
	free((void *)s1);
	return (cat);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*finalstr;
	size_t	i;

	if (!(s))
		return (NULL);
	if (start >= ft_strlen((char *)s))
		len = 0;
	else if (ft_strlen((char *)&s[start]) < len)
		len = ft_strlen((char *)&s[start]);
	if (!(finalstr = malloc(sizeof(char) * len + 1)))
		return (NULL);
	i = 0;
	while (i < len && (s[start + i] != '\0'))
	{
		finalstr[i] = s[start + i];
		i++;
	}
	free((void *)s);
	finalstr[i] = '\0';
	return (finalstr);
}
