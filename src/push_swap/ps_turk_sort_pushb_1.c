/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort_pushb_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 11:44:25 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Moves an element from Stack A and its target element in Stack B
   to the top of their respective stacks by rotating both stacks. This function
   is executed when both the element from Stack A and its target element in
   Stack B are closer to their respective heads.
*/

void	ts_bring_top_hh(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, stack_a->headidx, a_idx);
	b_dist = find_dist(arrsz, stack_b->headidx, b_target_idx);
	while (a_dist != 0 && b_dist != 0)
	{
		ps_rotate_both(stack_a, stack_b, arrsz);
		a_dist--;
		b_dist--;
	}
	while (a_dist != 0)
	{
		ps_rotate_stack(stack_a, arrsz, 'a');
		a_dist--;
	}
	while (b_dist != 0)
	{
		ps_rotate_stack(stack_b, arrsz, 'b');
		b_dist--;
	}
}


/* Description: Moves an element from Stack A and its target element in Stack B
   to the top of their respective stacks by rotating both stacks. This function
   is executed when both the element from Stack A and its target element in
   Stack B are closer to their respective tails.
*/

void	ts_bring_top_tt(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, a_idx, stack_a->tailidx) + 1;
	b_dist = find_dist(arrsz, b_target_idx, stack_b->tailidx) + 1;
	while (a_dist != 0 && b_dist != 0)
	{
		ps_rev_rotate_both(stack_a, stack_b, arrsz);
		a_dist--;
		b_dist--;
	}
	while (a_dist != 0)
	{
		ps_rev_rotate_stack(stack_a, arrsz, 'a');
		a_dist--;
	}
	while (b_dist != 0)
	{
		ps_rev_rotate_stack(stack_b, arrsz, 'b');
		b_dist--;
	}
}

/* Description: Moves an element from Stack A and its target element in Stack B
   to the top of their respective stacks by rotating both stacks. This function
   is executed when the element from Stack A is closer to its head while its
   target element in Stack B is closer to its tail.
*/

void	ts_bring_top_ht(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, stack_a->headidx, a_idx);
	b_dist = find_dist(arrsz, b_target_idx, stack_b->tailidx) + 1;
	while (a_dist != 0)
	{
		ps_rotate_stack(stack_a, arrsz, 'a');
		a_dist--;
	}
	while (b_dist != 0)
	{
		ps_rev_rotate_stack(stack_b, arrsz, 'b');
		b_dist--;
	}
}

/* Description: Moves an element from Stack A and its target element in Stack B
   to the top of their respective stacks by rotating both stacks. This function
   is executed when the element from Stack A is closer to its tail while its
   target element in Stack B is closer to its head.
*/

void	ts_bring_top_th(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, a_idx, stack_a->tailidx) + 1;
	b_dist = find_dist(arrsz, stack_b->headidx, b_target_idx);
	while (a_dist != 0)
	{
		ps_rev_rotate_stack(stack_a, arrsz, 'a');
		a_dist--;
	}
	while (b_dist != 0)
	{
		ps_rotate_stack(stack_b, arrsz, 'b');
		b_dist--;
	}
}


/* Description: Moves an element from Stack A and its target element in Stack B
   to the top of their respective stacks:
   1. Finds the target element in Stack B
   2. Execute the push_swap operations based on the elements' closenest to their
   stacks' head or tail
*/

void	ts_bring_top(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	scenario;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	scenario = ts_check_a_b_hd_tl(stack_a, stack_b, arrsz, a_idx);
	if (scenario == 1)
		ts_bring_top_hh(stack_a, stack_b, arrsz, a_idx);
	else if (scenario == 2)
		ts_bring_top_tt(stack_a, stack_b, arrsz, a_idx);
	else
	{
		if (ts_strategy_ht_th(stack_a, stack_b, arrsz, a_idx) == 1)
			ts_bring_top_ht(stack_a, stack_b, arrsz, a_idx);
		else if (ts_strategy_ht_th(stack_a, stack_b, arrsz, a_idx) == 2)
			ts_bring_top_th(stack_a, stack_b, arrsz, a_idx);
		else if (ts_strategy_ht_th(stack_a, stack_b, arrsz, a_idx) == 3)
			ts_bring_top_hh(stack_a, stack_b, arrsz, a_idx);
		else
			ts_bring_top_tt(stack_a, stack_b, arrsz, a_idx);
	}
}
