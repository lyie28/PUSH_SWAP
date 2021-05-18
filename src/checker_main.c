/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 11:12:30 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 15:58:10 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include "../includes/get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

static int	ft_instruct(t_list *stack_a)
{
	char	*str;
	t_list	*stack_b;

	stack_b = malloc(sizeof(t_list));
	if (!stack_b)
		return (-2);
	stack_b->head = NULL;
	while (get_next_line(0, &str))
	{
		if (ft_string_check(str) == 0)
		{
			free(str);
			return (-1);
		}
		ft_execute(str, &stack_a, &stack_b);
		free(str);
	}
	free(str);
	ft_freelist(stack_b);
	return (ft_checksort(stack_a));
}

static int	ft_checker(int argc, char **argv, t_list **head)
{
	int		i;
	int		result;
	t_node	*node;

	(*head) = malloc(sizeof(t_list));
	if (!(*head))
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

int	main(int argc, char **argv)
{
	t_list	*head;
	int		error;

	head = NULL;
	if (argc == 1)
		return (0);
	if (ft_checker(argc, argv, &head) == 0)
	{
		write(1, "Error\n", 6);
		ft_freelist(head);
		return (0);
	}
	error = ft_instruct(head);
	if (error < 1)
	{
		if (error == -1)
			write(1, "Error\n", 6);
		if (error == 0)
			write(1, "KO\n", 3);
		ft_freelist(head);
		return (0);
	}
	write(1, "OK\n", 3);
	ft_freelist(head);
	return (0);
}
