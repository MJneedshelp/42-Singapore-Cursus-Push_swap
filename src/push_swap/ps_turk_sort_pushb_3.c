/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort_pushb_3.c                             :+:      :+:    :+:   */
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

/* Description: Decides on the strategy for bringing an element from Stack A
   and its target element in Stack B to the top of their respective stacks when
   element in Stack A and the element in Stack B are closer to different sides

   Decision is made by selecting the cheapest of 4
   strategies.
   Return:
   - 1: Stack A rotates, Stack B reverse rotates
   - 2: Stack A reverse rotates, Stack B rotates
   - 3: Both stacks rotate
   - 4: Both stacks reverse rotate
*/

int	ts_strat_htth(t_cray *stack_a, t_cray *stack_b, int arrsz, int a_idx)
{
	int	b_target_idx;

	b_target_idx = find_target_b(stack_a, stack_b, arrsz, a_idx);
	if ((ts_cost_ahd_btl(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_2hd(stack_a, stack_b, arrsz, a_idx)) && \
	(ts_cost_ahd_btl(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_2tl(stack_a, stack_b, arrsz, a_idx)))
		return (1);
	if ((ts_cost_atl_bhd(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_2hd(stack_a, stack_b, arrsz, a_idx)) && \
	(ts_cost_atl_bhd(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_2tl(stack_a, stack_b, arrsz, a_idx)))
		return (2);
	if ((ts_cost_2hd(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_ahd_btl(stack_a, stack_b, arrsz, a_idx)) && \
	(ts_cost_2hd(stack_a, stack_b, arrsz, a_idx) <= \
	ts_cost_2tl(stack_a, stack_b, arrsz, a_idx)))
		return (3);
	return (4);
}
