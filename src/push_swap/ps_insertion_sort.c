/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/11 19:56:20 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

//	steps
//	1. find lowest in stack A. Get the index of the smallest element
//	2. Move the lowest member to the top stack A. Use rotate if it is closer
//	to head. Use reverse rotate if it is closer to tail
//	3. push b
//	3. repeat steps 1 to 3 until all elements




/* Description: Rotates an element in the stack to the head. Uses rotate if
   the element is closer to the head and reverse rotate if the element is
   closer to the tail.

Finds the smallest element in a stack and returns the index of
   the element.
*/

/*
int	main(int argc, char *argv[])
{
	int		*arr;
	int		i;
	t_cray	*stack_a;
	t_cray	*stack_b;

	arr = ps_input_validation(argc, argv);
	i = 0;
	printf("Arr: %p\n", arr);
	if (arr != NULL)
	{
		while (i < argc - 1)
		{
			printf("Item in arr: %d\n", arr[i]);
			i++;
		}
	}
	stack_a = ps_init_stack(argc - 1, arr);
	stack_b = ps_init_stack(argc - 1, NULL);
	print_cray(stack_a, argc - 1);
	print_cray(stack_b, argc - 1);
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	print_cray(stack_a, argc - 1);
	print_cray(stack_b, argc - 1);
	printf("Smallest element in stack_a: %d | index: %d\n", stack_a->stack[sort_utils_find_least(stack_a, argc -1)], sort_utils_find_least(stack_a, argc -1));
	printf("Smallest element in stack_b: %d | index: %d\n", stack_b->stack[sort_utils_find_least(stack_b, argc -1)], sort_utils_find_least(stack_b, argc -1));
}
*/
