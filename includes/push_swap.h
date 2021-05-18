/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lyie <lyie@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/11 20:13:15 by lyie              #+#    #+#             */
/*   Updated: 2021/05/18 11:55:50 by lyie             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "structs.h"

void	ft_lstadd_back(t_list *head, t_node *new);
int		ft_position_counter(t_list **list, int no);
void	ft_sort(t_list **a, t_list **b);
int		ft_position_counter_rev(t_list **list, int no);
int		ft_faux_prep(int no, t_list **b, int *ra, int *error);
void	ft_putback(t_list **st_a, t_list **st_b);
void	ft_del_vals(t_list *list, t_list *vals);
int		ft_inlist(int val, t_list *vals);
void	ft_del_node(t_node *node);
void	ft_lstcopy_reverse(t_list *orig, t_list *copy);
void	ft_big_sort(int size, t_list **stack_a, t_list **stack_b);
int		ft_replicas(t_list *head);
int		ft_isnumber(char *arg);
void	ft_lstadd_front(t_list *stack, t_node *new);
int		ft_findlowest(t_list **list);
int		ft_lstsize(t_list *list);
int		ft_swap(t_list **stack_x);
void	ft_rotate(t_list **stack_x);
void	ft_reverse(t_list **stack_x);
void	ft_sort_two_b(int size, t_list **stack_a, t_list **stack_b);
void	ft_sort_two(int size, t_list **stack_a, t_list **stack_b);
int		ft_execute(char *op, t_list **stack_a, t_list **stack_b);
int		ft_write_op(char *op, t_list **stack_a, t_list **stack_b);
void	ft_sort_three(t_list **stack_a, t_list **stack_b);
int		ft_checksort(t_list *stack);
void	ft_sort_five(int size, t_list **stack_a, t_list **stack_b);
void	ft_lstcopy(t_list *orig, t_list *copy);
int		ft_push(t_list **stack_from, t_list **stack_to);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_string_check(char *str);
int		ft_freelist(t_list *head);
t_node	*ft_lstnew(int no);
void	ft_lstprinter(t_list *lst);
int		ft_atoi(const char *str, int *result);
int		ft_topsearch(t_list **a, t_list *chunk, int *val);
void	ft_del_node_at(t_list **chunk, int val);
int		ft_get_list_val(t_list *list, int here);
t_list	*ft_get_sorted_ref(t_list *stack_a, t_list *stack_b);
int		ft_buildchunk(t_list **sorted, int till, t_list **chunk);
int		ft_b_prepared(int no, t_list **a, t_list **b, t_list *chunk);
void	ft_bot_pop(t_list **a, t_list **b, int count);
void	free_stacks_exit(t_list *a, t_list *b);
void	free_three_exit(t_list *a, t_list *b, t_list *other);
void	ft_top_pop(t_list **a, t_list **b, int count);
void	ft_recall(t_list **a, t_list **b);
#endif
