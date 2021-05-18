/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:48:39 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 15:56:25 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_reverse(t_list **stack_x)
{
	t_node	*current;
	t_node	*last;

	if (!(*stack_x)->head)
		return ;
	current = (*stack_x)->head;
	if (!current->next)
		return ;
	while (current->next->next != NULL)
		current = current->next;
	last = current->next;
	current->next = NULL;
	ft_lstadd_front(*stack_x, last);
}

void	ft_rotate(t_list **stack_x)
{
	t_node	*temp;

	if (!(*stack_x)->head)
		return ;
	temp = (*stack_x)->head;
	(*stack_x)->head = temp->next;
	temp->next = NULL;
	ft_lstadd_back((*stack_x), temp);
}

int	ft_swap(t_list **stack_x)
{
	t_node	*temp;

	if ((*stack_x)->head != NULL && (*stack_x)->head->next != NULL)
	{
		temp = (*stack_x)->head;
		(*stack_x)->head = temp->next;
		temp->next = (*stack_x)->head->next;
		(*stack_x)->head->next = temp;
	}
	return (1);
}

int	ft_push(t_list **stack_from, t_list **stack_to)
{
	t_node	*temp;

	if ((*stack_from)->head == NULL)
		return (0);
	temp = (*stack_from)->head;
	(*stack_from)->head = temp->next;
	ft_lstadd_front(*stack_to, temp);
	return (1);
}
