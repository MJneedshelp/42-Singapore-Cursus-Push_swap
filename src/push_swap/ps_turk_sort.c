/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:26:56 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in the index of the element from Stack A and finds the
   index of the target element in Stack B. Returns the 4 integers based on the
   scenarios:
   - 1: A and target B are both closer to head
   - 2: A and target B are both closer to tail
   - 3: A closer to head, B closer to tail
   - 4: A closer to tail, B closer to head
*/

int	ts_check_a_b_hd_tl(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	if (head_or_tail(stack_a, arrsz, a_idx) == 1 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 1)
		return (1);
	else if (head_or_tail(stack_a, arrsz, a_idx) == 0 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 0)
		return (2);
	else if (head_or_tail(stack_a, arrsz, a_idx) == 1 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 0)
		return (3);
	else
		return (4);
}

/* Description: Calculates the cost of moving an element from Stack A to
   Stack B given the index of element in Stack A
   1. Finds the target element in Stack B
   2. Calculates the cost of moving the element in Stack A and target element
   in B to the top of their stacks based on their closenest to head or tail
*/

int	ts_calc_cost(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;
	int	scenario;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	scenario = ts_check_a_b_hd_tl(stack_a, stack_b, arrsz, a_idx);
	if (scenario == 1)
		cost = ts_cost_2hd(stack_a, stack_b, arrsz, a_idx);
	else if (scenario == 2)
		cost = ts_cost_2tl(stack_a, stack_b, arrsz, a_idx);
	else if (scenario == 3)
	{
		cost = ft_least(ts_cost_ahd_btl(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2hd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2tl(stack_a, stack_b, arrsz, a_idx));
	}
	else
	{
		cost = ft_least(ts_cost_atl_bhd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2hd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2tl(stack_a, stack_b, arrsz, a_idx));
	}
	return (cost);
}

/* Description: Runs through each element in Stack A and calculates the cost of 
   pushing them to Stack B. Returns the index of the first element in Stack A 
   with the cheapest cost.
*/

int	ts_find_cheapest(t_cray *stack_a, t_cray *stack_b, int arrsz)
{
	int	i;
	int	cheapest_idx;
	int	min;
	int	st;

	i = 0;
	st = stack_a->headidx;
	cheapest_idx = st;
	min = ts_calc_cost(stack_a, stack_b, arrsz, st);
	while (i < stack_a->count - 1)
	{
		if (ts_calc_cost(stack_a, stack_b, arrsz, (st + i + 1) % arrsz) < min)
		{
			cheapest_idx = (st + i + 1) % arrsz;
			min = ts_calc_cost(stack_a, stack_b, arrsz, (st + i + 1) % arrsz);
		}
		i++;
	}
	return (cheapest_idx);
}

/* Description: Performs the turk sort algorithm (cr: A. Yigit Ogun). This
   function is only used when there are more than 3 items in the stack.
   Actions:
   1. Push either 1 (if Stack A has 4 elements) or 2 elements (if Stack A 
   has more than 4) from Stack A to Stack B.
   2. Start pushing elements from Stack A to Stack B until there are only 3
   elements left in Stack A:
		- for each push, find the target element in Stack B
		- calculate the cost of bringing the element and it's target to the
		top
		- bring the cheapest element in Stack A and its target element in 
		Stack B to the top
		- push to Stack B
   3. Sort the remaining 3 elements in Stack A
   4. Start pushing the elements in Stack B back to Stack A
		- for each push, find the target element in Stack A
		- bring target element in Stack A to top
		- push to Stack A
   5. Rotate the smallest in A to the head
*/

void	ps_turk_sort(t_cray *stack_a, t_cray *stack_b, int arrsz)
{
	int	tgt_idx;

	ps_push_stack(stack_a, stack_b, arrsz, 'b');
	if (arrsz >= 5)
		ps_push_stack(stack_a, stack_b, arrsz, 'b');
	while (stack_a->count > 3)
	{
		tgt_idx = ts_find_cheapest(stack_a, stack_b, arrsz);
		ts_bring_top(stack_a, stack_b, arrsz, tgt_idx);
		ps_push_stack(stack_a, stack_b, arrsz, 'b');
	}
	ps_sort_three(stack_a, arrsz, 'a');
	while (stack_b->count > 0)
	{
		tgt_idx = find_target_a(stack_a, stack_b, arrsz, stack_b->headidx);
		rotate_to_head(stack_a, arrsz, tgt_idx, 'a');
		ps_push_stack(stack_b, stack_a, arrsz, 'a');
	}
	if (check_sorted(stack_a, arrsz) == 0)
		rotate_to_head(stack_a, arrsz, find_min(stack_a, arrsz), 'a');
}
