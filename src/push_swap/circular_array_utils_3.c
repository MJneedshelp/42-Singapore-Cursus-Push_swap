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

/* Description: Finds the biggest element in a circular array that is smaller
   than the given value and returns the index of the element.
*/

int	find_next_max(t_cray *cray, int arrsz, int max)
{
	int	hdidx;
	int	next_max;
	int	retidx;
	int	i;

	i = 0;
	next_max = -1;
	hdidx = cray->headidx;
	while (i < cray->count)
	{
		if (cray->stack[(hdidx + i) % arrsz] < max && \
		cray->stack[(hdidx + i) % arrsz] > next_max)
		{
			next_max = cray->stack[(hdidx + i) % arrsz];
			retidx = (hdidx + i) % arrsz;
		}
		i++;
	}
	return (retidx);
}


/* Description: Prints the circular array starting from the head index to the
   tail index. Only prints out the number of items in the circular array and
   not all the items in the array by using the count.
*/

// SWITCH OUT THE PRINTF LATER WITH YOUR OWN PRINTF

void	print_cray(t_cray *cray, int arrsz)
{
	int	start;
	int	count;

	start = cray->headidx;
	count = 0;
	printf("Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n", arrsz, cray->count, cray->headidx, cray->tailidx);
	while (count < cray->count)
	{
		printf("%d\n", cray->stack[start]);
		start = (start + 1) % arrsz;
		count++;
	}
}



//Testing

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
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_rotate_stack(stack_a, argc - 1, 'a');
	ps_rotate_stack(stack_a, argc - 1, 'a');
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Find next max smaller than 3 in stack A. Index: %d | value: %d\n", find_next_max(stack_a, argc - 1, 3), stack_a->stack[find_next_max(stack_a, argc - 1, 3)]);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	printf("Find next max smaller than 7 in stack B. Index: %d | value: %d\n", find_next_max(stack_b, argc - 1, 7), stack_b->stack[find_next_max(stack_b, argc - 1, 7)]);
}



