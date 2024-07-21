/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:42:24 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 19:02:48 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Maybe remove this afterwards
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_circlearray
{
	int	*stack;
	int	headidx;
	int	tailidx;
	int	count;
}	t_cray;

/* Circular Array Utilities */
t_cray	*init_cray(int arrsz);
int		chk_cray_full(t_cray *cray, int arrsz);
int		chk_cray_empty(t_cray *cray);
void	add_itm_tl(t_cray *cray, int val, int arrsz);
void	add_itm_hd(t_cray *cray, int val, int arrsz);
int		rm_itm_hd(t_cray *cray, int arrsz);
int		rm_itm_tl(t_cray *cray, int arrsz);
void	print_cray(t_cray *cray, int arrsz);
int		find_min(t_cray *cray, int arrsz);
int		find_max(t_cray *cray, int arrsz);
int		find_next_max(t_cray *cray, int arrsz, int max);
int		find_dist(int arrsz, int from, int to);
int		head_or_tail(t_cray *cray, int arrsz, int index);
int		check_sorted(t_cray *cray, int arrsz);

/* push_swap Operations Utilities */
void	swap(t_cray *cray, int arrsz);
void	rotate_cw(t_cray *cray, int arrsz);
void	rotate_ccw(t_cray *cray, int arrsz);

/* push_swap Operations */
void	ps_swap_stack(t_cray *stack, int arrsz, char c);
void	ps_push_stack(t_cray *stack1, t_cray *stack2, int arrsz, char c);
void	ps_rotate_stack(t_cray *stack, int arrsz, char c);
void	ps_rev_rotate_stack(t_cray *stack, int arrsz, char c);
void	ps_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz);
void	ps_rev_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz);

/* push_swap main steps */
int		*ps_input_validation(int argc, char *argv[]);
t_cray	*ps_init_stack(int arrsz, int *arr);
void	ps_sort_three(t_cray *stack, int arrsz, char c);

/* Sort Utilities*/
void	rotate_to_head(t_cray *stk, int arrsz, int index);
void	ps_insertion_sort(t_cray *stack_a, t_cray *stack_b, int arrsz);

/* Turk sort steps */
int		find_target_b(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_2hd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_2tl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_ahd_btl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_atl_bhd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);

int		ts_check_a_b_hd_tl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_calc_cost(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_find_cheapest(t_cray *stack_a, t_cray *stack_b, int arrsz);
void	ts_bring_top_hh(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_tt(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_ht(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_th(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);






#endif
