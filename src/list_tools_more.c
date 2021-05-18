/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_more.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:44:56 by lyie              #+#    #+#             */
/*   Updated: 2021/05/11 22:00:00 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void	ft_lstadd_front(t_list *start, t_node *new)
{
	new->next = start->head;
	start->head = new;
}

void	ft_lstadd_back(t_list *start, t_node *node)
{
	t_node *current;

	if (start->head == NULL)
	{
		start->head = node;
		return ;
	}
	current = start->head;
	while (current->next != NULL)
		current = current->next;
	current->next = node;
	return ;
}

t_node	*ft_lstnew(int no)
{
	t_node *new;

	if (!(new = malloc(sizeof(t_node))))
		return (NULL);
	new->no = no;
	new->next = NULL;
	return (new);
}
