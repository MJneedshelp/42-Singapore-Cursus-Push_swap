/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort_pushb_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:20:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Finds the target index in Stack B given the element in Stack A.
   If the element in Stack A is smaller than the minimum in Stack B, the target
   element in Stack B is the max element.
   Else, the target element in Stack B is the closest largest element that is
   smaller than the element in Stack A.
*/
int	find_target_b(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;

	if (stack_a->stack[a_idx] < stack_b->stack[find_min(stack_b, arrsz)])
		b_target_idx = find_max(stack_b, arrsz);
	else
		b_target_idx = find_prev_max(stack_b, arrsz, stack_a->stack[a_idx]);
	return (b_target_idx);
}

/* Description: Calculates the cost of moving both element from Stack A and
   target element from Stack B to the head of their stacks via upward movement.
*/
int	ts_cost_2hd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, stack_a->headidx, a_idx);
	b_dist = find_dist(arrsz, stack_b->headidx, b_target_idx);
	cost = a_dist + b_dist - ft_least(a_dist, b_dist, INT_MAX);
	return (cost);
}

/* Description: Calculates the cost of moving both element from Stack A and
   target element from Stack B to the head of their stacks via downward movement.
*/
int	ts_cost_2tl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, a_idx, stack_a->tailidx) + 1;
	b_dist = find_dist(arrsz, b_target_idx, stack_b->tailidx) + 1;
	cost = a_dist + b_dist - ft_least(a_dist, b_dist, INT_MAX);
	return (cost);
}

/* Description: Calculates the cost of moving both element from Stack A and
   target element from Stack B to the head of their stacks. Element A uses
   upward movement while element B uses downward movement.
*/
int	ts_cost_ahd_btl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, stack_a->headidx, a_idx);
	b_dist = find_dist(arrsz, b_target_idx, stack_b->tailidx) + 1;
	cost = a_dist + b_dist;
	return (cost);
}

/* Description: Calculates the cost of moving both element from Stack A and
   target element from Stack B to the head of their stacks. Element A uses
   downward movement while element B uses upward movement.
*/
int	ts_cost_atl_bhd(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;
	int	a_dist;
	int	b_dist;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	a_dist = find_dist(arrsz, a_idx, stack_a->tailidx) + 1;
	b_dist = find_dist(arrsz, stack_b->headidx, b_target_idx);
	cost = a_dist + b_dist;
	return (cost);
}
