/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:13 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 16:26:57 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nline(char **line, char **chest, int i, int size)
{
	(*line) = malloc(sizeof(char) * i + 1);
	if (!(*line))
		return (-1);
	ft_strlcpy((*line), (*chest), i + 1);
	(*chest) = ft_substr((*chest), i + 1, (size - i));
	if (!(*chest))
	{
		free(*chest);
		return (-1);
	}
	return (1);
}

static int	ft_endfile(char **line, char **chest)
{
	int	i;
	int	size;
	int	check;

	check = 0;
	size = ft_strlen(*chest);
	i = (ft_strchr(*chest, '\n'));
	if (i != -1)
		return (ft_nline(line, chest, i, size));
	check = ft_strlen(*chest);
	if (check != 0)
		(*line) = ft_strdup(*chest);
	else
		(*line = ft_strdup(""));
	if (!(*line))
	{
		free(*chest);
		return (-1);
	}
	free(*chest);
	*chest = NULL;
	return (0);
}

static int	ft_nullify(char **line, char **chest)
{
	if (!(*chest))
	{
		(*line = ft_strdup(""));
		if (!(*line))
			return (-1);
		return (0);
	}
	return (ft_endfile(line, chest));
}

int	get_next_line(int fd, char **line)
{
	static char	*chest;
	int			i;
	int			store;
	int			size;
	char		buffer[BUFFER_SIZE + 1];

	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	store = (read(fd, buffer, BUFFER_SIZE));
	while (store > 0)
	{
		chest = ft_strjoin(chest, buffer, store);
		if (!(chest))
		{
			if (chest != NULL)
				free(chest);
			return (-1);
		}
		size = ft_strlen(chest);
		i = (ft_strchr(chest, '\n'));
		if (i != -1)
			return (ft_nline(line, &chest, i, size));
		store = (read(fd, buffer, BUFFER_SIZE));
	}
	return (ft_nullify(line, &chest));
}
