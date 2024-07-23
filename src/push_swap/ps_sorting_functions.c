/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sorting_functions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 19:31:20 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Sorts a stack of 3 elements in ascending order with a maximum
   of 2 moves.
*/

void	ps_sort_three(t_cray *stack, int arrsz, char c)
{
	int	head_val;
	int mid_val;
	int	tail_val;

	while (check_sorted(stack, arrsz) != 1)
	{
		head_val = stack->stack[stack->headidx];
		mid_val = stack->stack[(stack->headidx + 1 + arrsz) % arrsz];
		tail_val = stack->stack[stack->tailidx];
		if (mid_val > head_val && tail_val < head_val)
			ps_rev_rotate_stack(stack, arrsz, c);
		else if (head_val > mid_val && head_val > tail_val)
			ps_rotate_stack(stack, arrsz, c);
		else
			ps_swap_stack(stack, arrsz, c);
	}
}
