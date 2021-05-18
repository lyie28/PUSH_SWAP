/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 10:06:20 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 15:42:57 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_counters
{
	int	a;
	int	b;
	int	times;
	int	val;
	int	val2;
}				t_counters;

typedef struct s_node
{
	int				no;
	struct s_node	*next;
}				t_node;

typedef struct s_list
{
	t_node	*head;
}				t_list;

#endif
