/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frees.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 12:39:05 by lyie              #+#    #+#             */
/*   Updated: 2021/05/13 12:39:18 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	free_stacks_exit(t_list *a, t_list *b)
{
	ft_freelist(a);
	ft_freelist(b);
	exit(-1);
}

void	free_three_exit(t_list *a, t_list *b, t_list *other)
{
	ft_freelist(a);
	ft_freelist(b);
	ft_freelist(other);
	exit(-1);
}
