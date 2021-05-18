/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_in_common.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:03:49 by lyie              #+#    #+#             */
/*   Updated: 2021/05/13 09:05:21 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"
#include <unistd.h>
#include <stdio.h>

int	ft_checksort(t_list *stack)
{
	t_node *ptr2;
	t_node *ptr1;

	ptr1 = stack->head;
	while (ptr1->next)
	{
		ptr2 = ptr1->next;
		if (ptr1->no > ptr2->no)
			return (0);
		ptr1 = ptr1->next;
	}
	return (1);
}

int	ft_write_op(char *op, t_list **stack_a, t_list **stack_b)
{
	if (op[0] == 's' && (op[1] == 'a' || op[1] == 's'))
		ft_swap(stack_a);
	if (op[0] == 's' && (op[1] == 'b' || op[1] == 's'))
		ft_swap(stack_b);
	if (op[0] == 'p' && (op[1] == 'a'))
		ft_push(stack_b, stack_a);
	if (op[0] == 'p' && (op[1] == 'b'))
		ft_push(stack_a, stack_b);
	if (op[0] == 'r' && op[1] == 'r' && op[2] == '\n')
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	if (op[0] == 'r' && op[1] == 'a')
		ft_rotate(stack_a);
	if (op[0] == 'r' && op[1] == 'b')
		ft_rotate(stack_b);
	if (op[0] == 'r' && op[1] == 'r' && (op[2] == 'a' || op[2] == 'r'))
		ft_reverse(stack_a);
	if (op[0] == 'r' && op[1] == 'r' && (op[2] == 'b' || op[2] == 'r'))
		ft_reverse(stack_b);
	write(1, &(op[0]), ft_strlen(op));
	return (1);
}

int	ft_execute(char *op, t_list **stack_a, t_list **stack_b)
{
	if (op[0] == 's' && (op[1] == 'a' || op[1] == 's'))
		ft_swap(stack_a);
	if (op[0] == 's' && (op[1] == 'b' || op[1] == 's'))
		ft_swap(stack_b);
	if (op[0] == 'p' && (op[1] == 'a'))
		ft_push(stack_b, stack_a);
	if (op[0] == 'p' && (op[1] == 'b'))
		ft_push(stack_a, stack_b);
	if (op[0] == 'r' && op[1] == 'r' && (ft_strlen(op) == 2))
	{
		ft_rotate(stack_a);
		ft_rotate(stack_b);
	}
	if (op[0] == 'r' && op[1] == 'a')
		ft_rotate(stack_a);
	if (op[0] == 'r' && op[1] == 'b')
		ft_rotate(stack_b);
	if (op[0] == 'r' && op[1] == 'r' && (op[2] == 'a' || op[2] == 'r'))
		ft_reverse(stack_a);
	if (op[0] == 'r' && op[1] == 'r' && (op[2] == 'b' || op[2] == 'r'))
		ft_reverse(stack_b);
	return (1);
}

int	ft_replicas(t_list *head)
{
	t_node	*count;
	t_node	*copy;
	int		i;

	i = 0;
	if (!head)
		return (-1);
	if (!head->head)
		return (-1);
	count = head->head;
	while (count->next != NULL)
	{
		copy = count->next;
		while (copy)
		{
			if (count->no == copy->no)
				return (0);
			copy = copy->next;
		}
		count = count->next;
		i++;
	}
	return (1);
}

int	ft_isnumber(char *arg)
{
	int i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] < 48 || arg[i] > 57)
		{
			if (arg[i] == '-' && i == 0)
				break ;
			else
				return (0);
		}
		i++;
	}
	return (1);
}
