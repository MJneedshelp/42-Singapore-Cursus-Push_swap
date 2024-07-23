/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_three_less.c                               :+:      :+:    :+:   */
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
   of 2 moves. Function to be used only when there are 3 elements in the stack.
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

/* Description: Sorts a stack of 2 elements in ascending order. Function to be 
   used only when there are 2 elements in the stack.
*/

void	ps_sort_two(t_cray *stack, int arrsz, char c)
{
	if (check_sorted(stack, arrsz) != 1)
		ps_swap_stack(stack, arrsz, c);
}

/* Description: Takes in a stack and checks if the number of elements in the
   stack. Executes ps_sort_three or ps_sort_two depending on the number of 
   elements in the stack.
*/

void	ps_sort_three_less(t_cray *stack, int arrsz, char c)
{
	if (stack->count == 3)
		ps_sort_three(stack, arrsz, c);
	else
		ps_sort_two(stack, arrsz, c);
}