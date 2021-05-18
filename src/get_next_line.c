/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/01 15:58:13 by lyie              #+#    #+#             */
/*   Updated: 2021/05/12 10:32:44 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>

size_t		ft_strlen(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

static int	ft_nline(char **line, char **chest, int i, int size)
{
	if (!((*line) = malloc(sizeof(char) * i + 1)))
		return (-1);
	ft_strlcpy((*line), (*chest), i + 1);
	if (!(*chest = ft_substr((*chest), i + 1, (size - i))))
	{
		free(*chest);
		return (-1);
	}
	return (1);
}

static int	ft_endfile(char **line, char **chest)
{
	int i;
	int size;

	size = ft_strlen(*chest);
	i = (ft_strchr(*chest, '\n'));
	if (i != -1)
		return (ft_nline(line, chest, i, size));
	else if (ft_strlen(*chest) != 0)
	{
		if (!((*line) = ft_strdup(*chest)))
		{
			free(*chest);
			return (-1);
		}
	}
	else if (!(*line = ft_strdup("")))
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
		if (!(*line = ft_strdup("")))
			return (-1);
		return (0);
	}
	return (ft_endfile(line, chest));
}

int			get_next_line(int fd, char **line)
{
	static char	*chest;
	int			i;
	int			store;
	int			size;
	char		buffer[BUFFER_SIZE + 1];

	store = 0;
	if (BUFFER_SIZE < 1 || fd < 0 || read(fd, 0, 0) < 0 || !line)
		return (-1);
	while ((store = (read(fd, buffer, BUFFER_SIZE))) > 0)
	{
		if (!(chest = ft_strjoin(chest, buffer, store)))
		{
			if (chest != NULL)
				free(chest);
			return (-1);
		}
		size = ft_strlen(chest);
		i = (ft_strchr(chest, '\n'));
		if (i != -1)
			return (ft_nline(line, &chest, i, size));
	}
	return (ft_nullify(line, &chest));
}
