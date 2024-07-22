/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/04 20:25:40 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"

/* Description: "removes" an item from the circular array starting from the
   head by incrementing the headidx. Returns the old head index before the
   increment. If the circular array is empty, return -1.
*/

int	rm_itm_hd(t_cray *cray, int arrsz)
{
	int	rmitm_idx;

	if (chk_cray_empty(cray) == 1)
		return (-1);
	rmitm_idx = cray->headidx;
	cray->headidx = (cray->headidx + 1) % arrsz;
	cray->count--;
	return (rmitm_idx);
}



/* Description: "removes" an item from the circular array starting from the
   head by incrementing the headidx. Returns the old head index before the
   increment. If the circular array is empty, return -1.
*/

int	rm_itm_tl(t_cray *cray, int arrsz)
{
	int	rmitm_idx;

	if (chk_cray_empty(cray) == 1)
		return (-1);
	rmitm_idx = cray->tailidx;
	cray->tailidx = (cray->tailidx - 1 + arrsz) % arrsz;
	cray->count--;
	return (rmitm_idx);
}

/* Description: Finds the smallest element in a circular array and returns
   the index of the element.
*/

int	find_min(t_cray *cray, int arrsz)
{
	int	hdidx;
	int	min;
	int	retidx;
	int	i;

	i = 0;
	min = cray->stack[cray->headidx];
	hdidx = cray->headidx;
	retidx = cray->headidx;
	while (i < cray->count - 1)
	{
		if (cray->stack[(hdidx + i + 1) % arrsz] < min)
		{
			min = cray->stack[(hdidx + i + 1) % arrsz];
			retidx = (hdidx + i + 1) % arrsz;
		}
		i++;
	}
	return (retidx);
}

/* Description: Finds the biggest element in a circular array and returns
   the index of the element.
*/

int	find_max(t_cray *cray, int arrsz)
{
	int	hdidx;
	int	max;
	int	retidx;
	int	i;

	i = 0;
	max = cray->stack[cray->headidx];
	hdidx = cray->headidx;
	retidx = cray->headidx;
	while (i < cray->count - 1)
	{
		if (cray->stack[(hdidx + i + 1) % arrsz] > max)
		{
			max = cray->stack[(hdidx + i + 1) % arrsz];
			retidx = (hdidx + i + 1) % arrsz;
		}
		i++;
	}
	return (retidx);
}

/* Description: Finds the biggest element in a circular array that is smaller
   than the given value and returns the index of the element.
*/

int	find_prev_max(t_cray *cray, int arrsz, int max)
{
	int	hdidx;
	int	prev_max;
	int	retidx;
	int	i;

	i = 0;
	prev_max = -1;
	hdidx = cray->headidx;
	while (i < cray->count)
	{
		if (cray->stack[(hdidx + i) % arrsz] < max && \
		cray->stack[(hdidx + i) % arrsz] > next_max)
		{
			prev_max = cray->stack[(hdidx + i) % arrsz];
			retidx = (hdidx + i) % arrsz;
		}
		i++;
	}
	return (retidx);
}








// int	main(int argc, char *argv[])
// {
// 	int		*arr;
// 	int		i;
// 	t_cray	*stack_a;
// 	t_cray	*stack_b;
// 	int		smallest_index;

// 	arr = ps_input_validation(argc, argv);
// 	i = 0;
// 	printf("Arr: %p\n", arr);
// 	if (arr != NULL)
// 	{
// 		while (i < argc - 1)
// 		{
// 			printf("Item in arr: %d\n", arr[i]);
// 			i++;
// 		}
// 	}
// 	stack_a = ps_init_stack(argc - 1, arr);
// 	stack_b = ps_init_stack(argc - 1, NULL);
// 	print_cray(stack_a, argc - 1);
// 	print_cray(stack_b, argc - 1);
// 	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
// 	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
// 	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
// 	print_cray(stack_a, argc - 1);
// 	print_cray(stack_b, argc - 1);
// 	printf("Smallest element in stack_a: %d | index: %d\n", stack_a->stack[find_least(stack_a, argc -1)], find_least(stack_a, argc -1));
// 	printf("Smallest element in stack_b: %d | index: %d\n", stack_b->stack[find_least(stack_b, argc -1)], find_least(stack_b, argc -1));
// 	smallest_index = find_least(stack_a, argc -1);
// 	printf("Stack_a. Dist of smallest element to head: %d\n", find_dist(argc - 1, stack_a->headidx, smallest_index));
// 	printf("Stack_a. Dist of smallest element to tail: %d\n", find_dist(argc - 1, smallest_index, stack_a->tailidx));
// 	// smallest_index = find_least(stack_b, argc -1);
// 	// printf("Stack_b. Dist of smallest element to head: %d\n", find_dist(argc - 1, stack_b->headidx, smallest_index));
// 	// printf("Stack_b. Dist of smallest element to tail: %d\n", find_dist(argc - 1, smallest_index, stack_b->tailidx));
// 	rotate_to_head(stack_a, argc - 1, smallest_index);
// 	print_cray(stack_a, argc - 1);
// }
