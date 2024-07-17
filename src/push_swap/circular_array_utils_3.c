/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:37:58 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 18:42:55 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in a circular array of integers and checks if the elements
   in the array are sorted in ascending order starting from the head. The
   elements in the array should already be simplified [0, N). The circular array
   not be fully filled; the function checks up to the number of elements only
   Return:
   - 0: circular array is not sorted yet
   - 1: cicurlar array is sorted already
   */

int	check_sorted(t_cray *cray, int arrsz)
{
	int	i;
	int	curr_val;
	int	next_val;

	i = 0;
	while (i < cray->count - 1)
	{
		curr_val = cray->stack[(cray->headidx + i) % arrsz];
		next_val = cray->stack[(cray->headidx + i + 1) % arrsz];
		if (curr_val > next_val)
			return (0);
		i++;
	}
	return (1);
}


//Testing
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
	ps_rev_rotate_stack(stack_a, argc - 1, 'a');
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	printf("Check sorted A: %d\n", check_sorted(stack_a, argc - 1));
	printf("Check sorted B: %d\n", check_sorted(stack_b, argc - 1));
	ps_sort_three(stack_a, argc - 1, 'a');
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
}
*/


