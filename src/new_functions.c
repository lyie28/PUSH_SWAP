/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 10:48:15 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 11:43:45 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

int		ft_get_index(t_list **b, int size)
{
	int	i;
	int	max;
	int	max_index;
	t_node	*current;
	(void)size;
	i = 1;
	if ((*b)->head)
		max = (*b)->head->no;
	else
		return (0);
	current = (*b)->head;
	max_index = 0;
	while (current)
	{
		if (current->no > max)
		{
			max = current->no;
			max_index = i;
		}
		current = current->next;
		i++;
	}
	return (max_index);
}

void	ft_sort(t_list **a, t_list **b)
{
	int	i;
	int	max_index;
	int	count;
	int 	size;

	size = ft_lstsize(*b);
	while (size != 0)
	{
		size = ft_lstsize(*b);
		max_index = ft_get_index(b, size);
		if (max_index < size / 2)
			count = max_index - 1;
		else
			count = size - max_index + 1;
		i = 0;
		while (i < count)
		{
			if (max_index >= size / 2)
				ft_write_op("rrb\n", a, b);
			else
				ft_write_op("rb\n", a, b);
			i++;
		}
		ft_write_op("pa\n", a, b);
	}
}
