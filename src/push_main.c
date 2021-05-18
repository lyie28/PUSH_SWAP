/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 22:16:53 by lyie              #+#    #+#             */
/*   Updated: 2021/05/16 20:37:18 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

static int	ft_push_checker(int argc, char **argv, t_list **head)
{
	int		i;
	int		result;
	t_node	*node;

	if (!((*head) = malloc(sizeof(t_list))))
		exit(-1);
	(*head)->head = NULL;
	result = 0;
	i = 1;
	while (i < argc)
	{
		result = 0;
		if (ft_isnumber(argv[i]) == 0)
			return (0);
		if (ft_atoi(argv[i], &result) == 0)
			return (0);
		node = ft_lstnew(result);
		ft_lstadd_back((*head), node);
		i++;
	}
	if (ft_replicas((*head)) == 0)
		return (0);
	return (1);
}

int			ft_sorter(int size, t_list **stack_a, t_list **stack_b)
{
	if (size <= 3)
		ft_sort_two(size, stack_a, stack_b);
	else if (size == 4)
		ft_sort_three(stack_a, stack_b);
	else if (size <= 6)
		ft_sort_five(size, stack_a, stack_b);
	else
		ft_big_sort(size - 1, stack_a, stack_b);
	return (1);
}

int			ft_error(t_list **stack_a)
{
	write(1, "Error\n", 6);
	ft_freelist(*stack_a);
	return (0);
}

int			main(int argc, char **argv)
{
	t_list *stack_a;
	t_list *stack_b;

	if (argc == 1)
		return (0);
	stack_a = NULL;
	if (ft_push_checker(argc, argv, &stack_a) == 0)
		return (ft_error(&stack_a));
	if (ft_checksort(stack_a) == 1)
	{
		ft_freelist(stack_a);
		return (0);
	}
	if (!(stack_b = malloc(sizeof(t_list))))
	{
		ft_freelist(stack_a);
		return (-1);
	}
	stack_b->head = NULL;
	ft_sorter(argc, &stack_a, &stack_b);
	ft_freelist(stack_a);
	ft_freelist(stack_b);
	return (0);
}
