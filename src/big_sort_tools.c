/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:29:22 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 11:33:51 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdio.h>

t_list	*ft_get_sorted_ref(t_list *stack_a, t_list *stack_b)
{
	t_list	*copy;
	t_list	*sorted;
	t_node	*temp;
	t_node	*new;
	int		lowest;

	new = NULL;
	temp = stack_a->head;
	if (!temp)
		return (NULL);
	if (!(copy = malloc(sizeof(t_list))))
		free_stacks_exit(stack_a, stack_b);
	copy->head = NULL;
	ft_lstcopy(stack_a, copy);
	if (!(sorted = malloc(sizeof(t_list))))
		free_three_exit(stack_a, stack_b, copy);
	sorted->head = NULL;
	while (ft_lstsize(copy) != 0)
	{
		lowest = ft_findlowest(&copy);
		new = ft_lstnew(lowest);
		ft_lstadd_back(sorted, new);
	}
	free(copy);
	return (sorted);
}

int		ft_get_list_val(t_list *list, int here)
{
	int		i;
	t_node	*temp;

	if (!list)
		return (0);
	if (!list->head)
		return (0);
	temp = (list->head);
	i = 0;
	while (i < here && temp->next != NULL)
	{
		temp = temp->next;
		i++;
	}
	return (temp->no);
}

int		ft_buildchunk(t_list **sorted, int till, t_list **chunk)
{
	t_node *temp;
	t_node *new;

	if (!((*chunk) = malloc(sizeof(t_list))))
		return (-1);
	(*chunk)->head = NULL;
	temp = (*sorted)->head;
	while (temp)
	{
		if (temp->no <= till)
		{
			new = ft_lstnew(temp->no);
			ft_lstadd_front(*chunk, new);
		}
		temp = temp->next;
	}
	return (0);
}

int		ft_topsearch(t_list **a, t_list *chunk, int *val)
{
	t_node	*temp;
	int		count;

	count = 0;
	temp = (*a)->head;
	while (temp)
	{
		if (ft_inlist(temp->no, chunk))
		{
			*val = temp->no;
			return (count);
		}
		count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_del_node_at(t_list **chunk, int val)
{
	t_node *temp;

	temp = (*chunk)->head;
	if (temp->no == val)
	{
		(*chunk)->head = (*chunk)->head->next;
		free(temp);
		return ;
	}
	while (temp)
	{
		if (temp->next->no == val)
		{
			ft_del_node(temp);
			return ;
		}
		temp = temp->next;
	}
}
