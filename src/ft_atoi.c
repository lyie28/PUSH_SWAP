/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:55:29 by lyie              #+#    #+#             */
/*   Updated: 2021/05/11 22:10:38 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

static int	ft_whitespace(char test)
{
	if ((test > 8 && test < 14) || test == 32)
		return (0);
	return (1);
}

static int	ft_checksize(int result, int i, char *str, int sign)
{
	unsigned long int	test;
	unsigned long int	pos_min;

	test = (long)result;
	pos_min = (long)INT_MAX + 1;
	if (sign == -1 && test * 10 + (str[i] - '0') > pos_min)
		return (1);
	if (sign == 1 && test * 10 + (str[i] - '0') > INT_MAX)
		return (1);
	return (0);
}

int			ft_atoi(const char *str, int *result)
{
	int				i;
	int				sign;
	unsigned int	build;

	build = 0;
	i = 0;
	sign = 1;
	while (ft_whitespace(str[i]) == 0)
		i++;
	if (str[i] == '-')
		sign = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	if (str[i] < 48 || str[i] > 57)
		return (0);
	build = str[i++] - '0';
	while (str[i] > 47 && str[i] < 58)
	{
		if (ft_checksize((build), i, (char *)str, sign))
			return (0);
		build = ((build) * 10) + (str[i] - '0');
		i++;
	}
	(*result) = (int)(build * sign);
	return (1);
}
