/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:13:07 by lyie              #+#    #+#             */
/*   Updated: 2021/05/13 08:57:44 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"

int	ft_string_check(char *str)
{
	if (ft_strncmp(str, "sa", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "sb", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "ss", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "pa", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "pb", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "ra", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "rb", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "rr", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "rra", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "rrb", ft_strlen(str)) == 0)
		return (1);
	if (ft_strncmp(str, "rrr", ft_strlen(str)) == 0)
		return (1);
	return (0);
}
