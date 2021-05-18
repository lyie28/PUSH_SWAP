/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/06 10:50:56 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 16:42:00 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

void	ft_sort_three(t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;
	int	c;

	a = (*stack_a)->head->no;
	b = (*stack_a)->head->next->no;
	c = (*stack_a)->head->next->next->no;
	if (a < b && b > c && a < c)
	{
		ft_write_op("sa\n", stack_a, stack_b);
		ft_write_op("ra\n", stack_a, stack_b);
	}
	if (a < b && b > c && a > c)
		ft_write_op("rra\n", stack_a, stack_b);
	if (a > b && b < c && c > a)
		ft_write_op("sa\n", stack_a, stack_b);
	if (a > b && b < c && c < a)
		ft_write_op("ra\n", stack_a, stack_b);
	if (a > b && b > c)
	{
		ft_write_op("sa\n", stack_a, stack_b);
		ft_write_op("rra\n", stack_a, stack_b);
	}
}

static void	ft_after_moves(int count, t_list **a, t_list **b, int size)
{
	if (count == 1)
		ft_write_op("sa\n", a, b);
	if (count == 2 && count != size - 1)
	{
		ft_write_op("sa\n", a, b);
		ft_write_op("rra\n", a, b);
	}
	if (count == size - 1)
	{
		ft_write_op("ra\n", a, b);
		ft_write_op("ra\n", a, b);
	}
	if (count == size)
		ft_write_op("ra\n", a, b);
}

void	ft_putback(t_list **st_a, t_list **st_b)
{
	t_node	*current_a;
	t_node	*current_b;
	int		count;
	int		size;

	size = ft_lstsize(*st_a);
	count = 0;
	current_a = (*st_a)->head;
	current_b = (*st_b)->head;
	current_b = (*st_b)->head;
	while (current_a->no < current_b->no)
	{
		count++;
		if (current_a->next == NULL)
			break ;
		current_a = current_a->next;
	}
	if (count == 2 && count != size - 1)
		ft_write_op("ra\n", st_a, st_b);
	if (count == size - 1)
		ft_write_op("rra\n", st_a, st_b);
	ft_write_op("pa\n", st_a, st_b);
	ft_after_moves(count, st_a, st_b, size);
	return ;
}

void	ft_sort_five(int size, t_list **stack_a, t_list **stack_b)
{
	int	shift;
	int	i;

	i = -1;
	shift = (size - 1) - 3;
	while (++i < shift)
		ft_write_op("pb\n", stack_a, stack_b);
	ft_sort_three(stack_a, stack_b);
	ft_putback(stack_a, stack_b);
	if (shift == 2)
		ft_putback(stack_a, stack_b);
}

void	ft_sort_two(int size, t_list **stack_a, t_list **stack_b)
{
	int	a;
	int	b;

	a = 0;
	b = 0;
	if (size <= 2)
		return ;
	a = (*stack_a)->head->no;
	b = (*stack_a)->head->next->no;
	if (b < a)
		ft_write_op("ra\n", stack_a, stack_b);
}
