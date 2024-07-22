/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
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

// /* Description: Rotates an element in the stack to the head. Uses rotate if
//    the element is closer to the head and reverse rotate if the element is
//    closer to the tail.
// */

// void	rotate_to_head(t_cray *stk, int arrsz, int index)
// {
// 	int	dist_to_head;
// 	int	dist_to_tail;
// 	int	final_val;

// 	dist_to_head = find_dist(arrsz, stk->headidx, index);
// 	dist_to_tail = find_dist(arrsz, index, stk->tailidx);
// 	final_val = stk->stack[index];
// 	while (stk->stack[stk->headidx] != final_val)
// 	{
// 		if (dist_to_head <= dist_to_tail + 1)
// 			ps_rotate_stack(stk, arrsz, 'a');
// 		else
// 			ps_rev_rotate_stack(stk, arrsz, 'a');
// 	}
// }

/* Description: sorts stack A by pushing the all numbers to stack B starting
   from the smallest number to the biggest. Push the whole of stack B back to
   stack A afterwards. Steps:
   1. Find the index of the smallest element in stack A
   2. Rotate the smallest element to the head of stack A
		- Use rotate if the element is closer to the head
		- Use reverse rotate if the element is closer to the tail
   3. Push element to stack B
   4. Repeat steps 1 to 3 until all elements are in stack B
   5. Push all elements back to stack A

*/
void	ps_insertion_sort(t_cray *stack_a, t_cray *stack_b, int arrsz)
{
	int	smallest_index;

	while (stack_b->count < arrsz)
	{
		smallest_index = find_min(stack_a, arrsz);
		rotate_to_head(stack_a, arrsz, smallest_index);
		ps_push_stack(stack_a, stack_b, arrsz, 'b');
	}
	while (stack_a->count < arrsz)
		ps_push_stack(stack_b, stack_a, arrsz, 'a');
}




//Used for testing
// int	main(int argc, char *argv[])
// {
// 	int		*arr;
// 	int		i;
// 	t_cray	*stack_a;
// 	t_cray	*stack_b;
// 	int		smallest_index;

// 	stepcount = 0;
// 	arr = ps_input_validation(argc, argv);
// 	stack_a = ps_init_stack(argc - 1, arr);
// 	stack_b = ps_init_stack(argc - 1, NULL);
// 	printf("Stack A\n");
// 	print_cray(stack_a, argc - 1);
// 	printf("Stack B\n");
// 	print_cray(stack_b, argc - 1);
// 	// printf("Push all to stack B from stack A starting with the smallest\n");
// 	while (stack_b->count < argc - 1)
// 	{
// 		smallest_index = find_least(stack_a, argc - 1);
// 		rotate_to_head(stack_a, argc - 1, smallest_index);
// 		ps_push_stack(stack_a, stack_b, argc - 1, 'b');
// 	}
// 	// printf("All items pushed to stack B.\nStack A\n");
// 	// print_cray(stack_a, argc - 1);
// 	// printf("Stack B\n");
// 	// print_cray(stack_b, argc - 1);
// 	// printf("Push all items back to stack A\n");
// 	while (stack_a->count < argc - 1)
// 	{
// 		ps_push_stack(stack_b, stack_a, argc - 1, 'a');
// 	}
// 	printf("Stack A\n");
// 	print_cray(stack_a, argc - 1);
// 	printf("Stack B\n");
// 	print_cray(stack_b, argc - 1);
// }
