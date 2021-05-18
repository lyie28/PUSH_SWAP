/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools_extra.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:30:10 by lyie              #+#    #+#             */
/*   Updated: 2021/05/13 13:42:28 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

int		ft_freelist(t_list *head)
{
	t_node *go;
	t_node *temp;

	go = head->head;
	while (go != NULL)
	{
		temp = go;
		go = go->next;
		free(temp);
	}
	free(head);
	return (-1);
}

int		ft_lstsize(t_list *list)
{
	t_node	*go;
	int		count;

	count = 0;
	if (!list)
		return (0);
	go = list->head;
	if (go == NULL)
		return (0);
	count++;
	while (go->next)
	{
		count++;
		go = go->next;
	}
	return (count);
}

void	ft_lstcopy_reverse(t_list *orig, t_list *copy)
{
	t_node *current;
	t_node *new;

	new = NULL;
	if (!orig)
		return ;
	if (!orig->head)
		return ;
	current = orig->head;
	if (!current)
		return ;
	while (current)
	{
		new = ft_lstnew(current->no);
		ft_lstadd_front(copy, new);
		current = current->next;
	}
}

void	ft_lstcopy(t_list *orig, t_list *copy)
{
	t_node *current;
	t_node *new;

	new = NULL;
	if (!orig)
		return ;
	if (!orig->head)
		return ;
	current = orig->head;
	while (current)
	{
		new = ft_lstnew(current->no);
		ft_lstadd_back(copy, new);
		current = current->next;
	}
}

int		ft_inlist(int val, t_list *vals)
{
	t_node *temp;

	temp = vals->head;
	while (temp)
	{
		if (val == temp->no)
			return (1);
		temp = temp->next;
	}
	return (0);
}
