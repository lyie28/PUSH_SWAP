/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools_extra.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:12:01 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 15:54:43 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <unistd.h>

int	ft_position_counter_rev(t_list **list, int no)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = (*list)->head;
	while (temp != NULL)
	{
		if (no < temp->no)
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

int	ft_position_counter(t_list **list, int no)
{
	int		count;
	t_node	*temp;

	count = 0;
	temp = (*list)->head;
	while (temp != NULL)
	{
		if (no > temp->no)
			break ;
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_bot_pop(t_list **a, t_list **b, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		ft_write_op("rra\n", a, b);
	ft_write_op("pb\n", a, b);
}

void	ft_top_pop(t_list **a, t_list **b, int count)
{
	int	i;

	i = -1;
	while (++i < count)
		ft_write_op("ra\n", a, b);
	ft_write_op("pb\n", a, b);
}
