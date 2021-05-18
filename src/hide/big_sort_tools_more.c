/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools_more.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 09:27:05 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 11:54:10 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>
#include <unistd.h>

static void	ft_part_one(t_counters count, t_list **a, t_list **b)
{
	int i;

	i = -1;
	if (count.a < count.b)
	{
		while (++i < count.a)
			ft_write_op("rb\n", a, b);
		ft_write_op("pb\n", a, b);
	}
	else
	{
		while (++i < count.b)
			ft_write_op("rrb\n", a, b);
		ft_write_op("pb\n", a, b);
	}
}

static int	ft_doit(t_counters count, t_list **a, t_list **b, t_list *chunk)
{
	int ra;

	ft_part_one(count, a, b);
	ra = 0;
	if (ft_getnext(&(count.times), &ra, a, chunk))
		return (-1);
	printf("count a vs count b: %i vs %i\n", count.a, count.b);
	if (count.a < count.b)
	{
		while (--count.a >= 0)
		{
			if (ra == 0 && --count.times >= 0)
				ft_write_op("rrr\n", a, b);
			else
				ft_write_op("rrb\n", a, b);
		}
		return (0);
	}
	while (--count.b >= -1)
	{
		if (ra == 1 && --count.times >= -1)
			ft_write_op("rr\n", a, b);
		else
			ft_write_op("rb\n", a, b);
	}
	return (0);
}

int			ft_b_prepared(int no, t_list **a, t_list **b, t_list *chunk)
{
	t_counters	count;
	t_list		*reverse;
	int			error;

	error = 0;
	count.a = 0;
	count.b = 0;
	count.times = 0;
	if ((*b)->head == NULL)
		return (ft_write_op("pb\n", a, b));
	if (no > (*b)->head->no)
		return (ft_write_op("pb\n", a, b));
	count.a = ft_position_counter(b, no);
	if (!(reverse = malloc(sizeof(t_list))))
		return (-1);
	reverse->head = NULL;
	ft_lstcopy_reverse(*b, reverse);
	count.b = ft_position_counter_rev(&reverse, no);
	error = ft_doit(count, a, b, chunk);
	ft_freelist(reverse);
	return (error);
}
