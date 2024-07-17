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
		//printf("head: %d | mid: %d | tail: %d\n", head_val, stack->stack[stack->headidx + 1], tail_val);
		if (mid_val > head_val && tail_val < head_val)
			ps_rev_rotate_stack(stack, arrsz, c);
		else if (head_val > mid_val && head_val > tail_val)
			ps_rotate_stack(stack, arrsz, c);
		else
			ps_swap_stack(stack, arrsz, c);
	}
}


//Used for testing
/*
int	main(int argc, char *argv[])
{
	int		*arr;
	t_cray	*stack_a;
	t_cray	*stack_b;

	arr = ps_input_validation(argc, argv);
	stack_a = ps_init_stack(argc - 1, arr);
	stack_b = ps_init_stack(argc - 1, NULL);
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	sort_three(stack_a, argc - 1, 'a');
	print_cray(stack_a, argc - 1);
}
*/
