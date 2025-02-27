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
int		find_min(t_cray *cray, int arrsz);
int		find_max(t_cray *cray, int arrsz);
int		find_prev_max(t_cray *cray, int arrsz, int max);
int		find_next_max(t_cray *cray, int arrsz, int max);
int		find_dist(int arrsz, int from, int to);
int		head_or_tail(t_cray *cray, int arrsz, int index);
int		check_sorted(t_cray *cray, int arrsz);
void	print_cray(t_cray *cray, int arrsz);

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

/* Sort Utilities*/
void	rotate_to_head(t_cray *stk, int arrsz, int index, char c);
void	ps_sort_three(t_cray *stack, int arrsz, char c);
void	ps_sort_two(t_cray *stack, int arrsz, char c);
void	ps_sort_three_less(t_cray *stack, int arrsz, char c);

/* push_swap input validation steps */
int		find_stray_sz(char **stray);
int		find_arr_sz_split(char *str);
int		*ps_validate_input(int arrsz, char **stray, int strt_idx);
int		*ps_gen_intray(int argc, char *argv[]);
int		check_numeric(char *str);
int		check_duplicate(int *arr, int arrsz);
int		find_next_least(int *arr, int arrsz, long least);
int		*simplify_arr(int *arr, int arrsz);
t_cray	*ps_init_stack(int arrsz, int *arr);

/* Turk sort steps */
void	ps_turk_sort(t_cray *stack_a, t_cray *stack_b, int arrsz);
int		find_target_b(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		find_target_a(t_cray *stack_a, t_cray *stack_b, int arrsz, int b_idx);
int		ts_cost_2hd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_2tl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_ahd_btl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_cost_atl_bhd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_chck_ab_hdtl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_calc_cost(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_find_cheapest(t_cray *stack_a, t_cray *stack_b, int arrsz);
void	ts_bring_top(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
int		ts_strat_htth(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_hh(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_tt(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_ht(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);
void	ts_bring_top_th(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx);

#endif
