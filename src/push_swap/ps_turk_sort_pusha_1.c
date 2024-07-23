/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_turk_sort_pusha_1.c                             :+:      :+:    :+:   */
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

/* Description: Finds the target index in Stack A given the element in Stack B.
   If the element in Stack B is larger than the maximum in Stack A, the target
   element in Stack A is the min element.
   Else, the target element in Stack A is the closest larger element
*/
int	find_target_a(t_cray *stack_a, t_cray *stack_b, int arrsz, int b_idx)
{
	int	a_target_idx;

	if (stack_b->stack[b_idx] > stack_a->stack[find_max(stack_a, arrsz)])
		a_target_idx = find_min(stack_a, arrsz);
	else
		a_target_idx = find_next_max(stack_a, arrsz, stack_b->stack[b_idx]);
	return (a_target_idx);
}
