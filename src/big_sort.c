/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 11:12:01 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 15:45:34 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

static int	ft_find_and_move(t_list **a, t_list **b, t_list *chunk)
{
	t_list		*reverse;
	t_counters	count;

	count.val = 0;
	count.val2 = 0;
	while (ft_lstsize(chunk) > 0)
	{
		count.a = ft_topsearch(a, chunk, &count.val);
		reverse = malloc(sizeof(t_list));
		if (!reverse)
			return (-1);
		reverse->head = NULL;
		ft_lstcopy_reverse(*a, reverse);
		count.b = ft_topsearch(&reverse, chunk, &count.val2) + 1;
		if (count.a <= count.b)
		{
			ft_top_pop(a, b, count.a);
			count.val2 = count.val;
		}
		else
			ft_bot_pop(a, b, count.b);
		ft_del_node_at(&chunk, count.val2);
		ft_freelist(reverse);
	}
	return (0);
}

void	ft_sorter_go(t_list **a, t_list **b, t_list *sorted, int divider)
{
	int		till;
	t_list	*chunk;

	while ((ft_lstsize(sorted)) > 0)
	{
		till = ft_get_list_val(sorted, divider);
		if (ft_buildchunk(&sorted, till, &chunk) == -1)
			free_three_exit(*a, *b, sorted);
		ft_del_vals(sorted, chunk);
		if (ft_find_and_move(a, b, chunk) == -1)
		{
			ft_freelist(chunk);
			ft_freelist(sorted);
			ft_freelist(*a);
			ft_freelist(*b);
			exit(-1);
		}
		ft_freelist(chunk);
	}
	ft_freelist(sorted);
	ft_sort(a, b);
	while ((*b)->head)
		ft_write_op("pa\n", a, b);
}

void	ft_big_sort(int size, t_list **stack_a, t_list **stack_b)
{
	t_list	*sorted;
	int		chunk_size;

	sorted = ft_get_sorted_ref(*stack_a, *stack_b);
	if (size >= 250)
		chunk_size = (size / 13);
	if (size >= 100 && size < 250)
		chunk_size = (size / 7);
	if (size < 100 && size >= 10)
		chunk_size = size / 4;
	if (size < 10)
		chunk_size = size / 2;
	ft_sorter_go(stack_a, stack_b, sorted, (chunk_size));
}
