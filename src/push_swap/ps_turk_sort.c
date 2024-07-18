/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort.c                                     :+:      :+:    :+:   */
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

/* Steps:
   1. Probably need to think about the logic if there's less than 5 elements
   in the stack A
   2. Push 2 elements to stack B to form the min and the max in stack B
   3. While stack A has more than 3 elements
		- calculate cost for each element to be moved to stack B
			- check if the elememt is the new min in stack B
				- target element in stack b: current max in stack B
			- Not new min
				- target element in stack b: the next smallest element after
				the current element in stack A (works even if the element in A
				is the biggest)
			- Cost: (no. steps to move elm in A to top) + (no. steps to move elm in B to top)
				- if both elm A and target B are closer to head
					- count number of (rr)s + ra / rb needed
					- Dist head (A) + Dist Head (B) - least(Dist head (A) + Dist Head (B))
				- if both elm A and target B are closer to tail
					- count the number of rrr(s) + rra / rrb needed
					- Dist tail (A) + Dist tail (B) - least(Dist tail (A) + Dist tail (B))
				- if both elm A and target B are closer to different ends compare between 3 movements
					- Dist head (A) + Dist Head (B) - least(Dist head (A) + Dist Head (B))
					- Dist tail (A) + Dist tail (B) - least(Dist tail (A) + Dist tail (B))
					- A dist closer(head / tail) + b dist closer(head / tail)
		- execute the first cheapest move to push to B
	4. Sort three in stack A
	5. While stack B not empty
		- find next bigger elm in stack A
			- move next bigger elm in stack A to the top
		- if elm B is the new biggest in stack A
			- move the smallest in stack A to the top
		- push from B to A
*/

/* Description: Runs through each element in Stack A and calculates the cost of pushing them
   to Stack B. Execute the steps only for the cheapest element in Stack A.
   xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx
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





/* Description: Calculates the cost of moving an element from Stack A to
   Stack B given the index of element in Stack A
   1. Finds the target element in Stack B
   2. Calculates the cost of moving the element in Stack A on top of the element in Stack B
*/
int	ts_calc_cost(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;
	int	cost;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	if (head_or_tail(stack_a, arrsz, a_idx) == 1 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 1)
		cost = ts_cost_2hd(stack_a, stack_b, arrsz, a_idx);
	else if (head_or_tail(stack_a, arrsz, a_idx) == 0 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 0)
		cost = ts_cost_2tl(stack_a, stack_b, arrsz, a_idx);
	else if (head_or_tail(stack_a, arrsz, a_idx) == 1 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 0)
	{
		cost = ft_least(ts_cost_ahd_btl(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2hd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2tl(stack_a, stack_b, arrsz, a_idx));
	}
	else if (head_or_tail(stack_a, arrsz, a_idx) == 0 && \
	head_or_tail(stack_b, arrsz, b_target_idx) == 1)
	{
		cost = ft_least(ts_cost_atl_bhd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2hd(stack_a, stack_b, arrsz, a_idx), \
		ts_cost_2tl(stack_a, stack_b, arrsz, a_idx));
	}
	return (cost);
}

/* Description: XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
*/
void	ps_turk_sort(t_cray *stack_a, t_cray *stack_b, int arrsz)
{
	if (arrsz <= 5)
	// perform sorting for 5 or less
	else
	{
		ps_push_stack(stack_a, stack_b, arrsz, 'b');
		ps_push_stack(stack_a, stack_b, arrsz, 'b');
		while (stack_a->count > 3)
		{
			//push cheapest to B
			//calculate cost + push b
		}
		ps_sort_three(stack_a, arrsz, 'a');
		while (stack_b->count > 0)
		{
			//push to A
		}
		if (check_sorted(stack_a, arrsz) == 0)
			rotate_to_head(stack_a, arrsz, find_min(stack_a, arrsz));
	}
}






