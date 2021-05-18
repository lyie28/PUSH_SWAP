/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 09:44:56 by lyie              #+#    #+#             */
/*   Updated: 2021/05/17 10:47:08 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <stdlib.h>
#include <stdio.h>

void		ft_lstprinter(t_list *lst)
{
	t_node *current;

	if (!lst)
		return ;
	if (!lst->head)
		return ;
	current = lst->head;
	while (current)
	{
		printf("current node is %i\n", current->no);
		current = current->next;
	}
}

void		ft_del_node(t_node *node)
{
	t_node *temp;

	temp = node->next;
	node->next = node->next->next;
	free(temp);
}

static void	ft_restart(t_node **temp, t_list **list)
{
	ft_del_node(*temp);
	*temp = (*list)->head;
}

void		ft_del_vals(t_list *list, t_list *vals)
{
	t_node *temp;

	if (!list)
		return ;
	temp = list->head;
	if (!temp)
		return ;
	while (ft_inlist(temp->no, vals))
	{
		list->head = temp->next;
		if (temp->next == NULL)
		{
			free(temp);
			return ;
		}
		free(temp);
		temp = list->head;
	}
	while (temp->next)
	{
		if (ft_inlist(temp->next->no, vals))
			ft_restart(&temp, &list);
		temp = temp->next;
	}
}

static int	ft_findlowest_plus(t_node *current, int lowest)
{
	while (current->next)
	{
		if (current->next->no == lowest)
		{
			ft_del_node(current);
			return (lowest);
		}
		current = current->next;
	}
	return (lowest);
}

int			ft_findlowest(t_list **list)
{
	t_node	*current;
	int		lowest;

	if (!(*list))
		return (-1);
	if (!(*list)->head)
		return (-1);
	current = (*list)->head;
	lowest = current->no;
	while (current)
	{
		if (current->no < lowest)
			lowest = current->no;
		current = current->next;
	}
	current = (*list)->head;
	if (current->no == lowest)
	{
		(*list)->head = current->next;
		free(current);
		return (lowest);
	}
	return (ft_findlowest_plus(current, lowest));
}
