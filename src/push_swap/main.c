/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:10:20 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 19:17:51 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"


/*
//Main logic
int	main(int argc, char	*argv[])
{
	//1. Input validation (probably can be 1 file by itself):
	//	- input: argc, argv[]
	//	- return:
	//		- array of integers if all items are validated
	//		- NULL pointer if argc == 1 (no input)
	//		-
	//	- Actions: checks the following
	//		- no input
	//			- atoi for each argument
	//			- inputs are not integers
	//		- not numbers
	//		- out of range of integers
	//		- Duplicate numbers

	//2. Convert array of integers into all running order positive integers
	//	- Look for smallest element
	//	- get range

	//3. Init stack x 2 for A and B stack (probably can be 1 file by itself)
	//	- input: array from 1, argc (count of items in array)
	//	- return: cray A
	//	- Actions:
	//		- init_cray
	//		- if array is not NULL
	//			- while not arrsz, add items into stack

	//4. Algorithm function
	//	- input: stacks A and B
	//	- return: void
	//	- Actions:
	//		- perform algo to sort stack A
	//		- tbd
}
*/


/*
int	main(int argc, char *argv[])
{
	int		*arr;
	t_cray	*stack_a;
	t_cray	*stack_b;

	arr = ps_input_validation(argc, argv);
	if (arr == NULL)
		return(ft_printf("Error\n"), -1);
	stack_a = ps_init_stack(argc - 1, arr);
	stack_b = ps_init_stack(argc - 1, NULL);
	//print_cray(stack_a, argc - 1);
	//print_cray(stack_b, argc - 1);
	//need to think of freeing if malloc fails
	if (check_sorted(stack_a, argc - 1) != 1)
		ps_insertion_sort(stack_a, stack_b, argc - 1);
	print_cray(stack_a, argc - 1);
	return (0);

}
*/

//Used for testing
int	main(int argc, char *argv[])
{
	int		*arr;
	t_cray	*stack_a;
	t_cray	*stack_b;
	int		i;

	i = 0;
	arr = ps_input_validation(argc, argv);
	stack_a = ps_init_stack(argc - 1, arr);
	stack_b = ps_init_stack(argc - 1, NULL);
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_push_stack(stack_a, stack_b, argc - 1, 'b');
	ps_rotate_stack(stack_b, argc - 1, 'b');
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	//printf("Min stack B | Index: %d | Val: %d\n", find_min(stack_b, argc - 1), stack_b->stack[find_min(stack_b, argc - 1)]);
	//printf("Max stack B | Index: %d | Val: %d\n", find_max(stack_b, argc - 1), stack_b->stack[find_max(stack_b, argc - 1)]);
	while (i < stack_a->count)
	{
		printf("A Elm: %d | Target B val: %d | 2 hd cost: %d | 2 tl cost: %d | ahd, btl: %d | atl, bhd: %d | final cost: %d\n", \
		stack_a->stack[(stack_a->headidx + i) % (argc - 1)], \
		stack_b->stack[find_target_b(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1))], \
		ts_cost_2hd(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1)), \
		ts_cost_2tl(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1)), \
		ts_cost_ahd_btl(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1)), \
		ts_cost_atl_bhd(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1)), \
		ts_calc_cost(stack_a, stack_b, argc - 1, (stack_a->headidx + i) % (argc - 1)));
		i++;
	}
	printf("Cheapest to push from A. Idx: %d | Val: %d\n", ts_find_cheapest(stack_a, stack_b, argc - 1), stack_a->stack[ts_find_cheapest(stack_a, stack_b, argc - 1)]);
	//ts_bring_top_hh(stack_a, stack_b, argc - 1, stack_a->tailidx);
	ts_bring_top_tt(stack_a, stack_b, argc - 1, stack_a->headidx + 1);
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	ts_bring_top_ht(stack_a, stack_b, argc - 1, stack_a->headidx + 1);
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);
	ts_bring_top_th(stack_a, stack_b, argc - 1, stack_a->headidx + 1);
	printf("Stack A\n");
	print_cray(stack_a, argc - 1);
	printf("Stack B\n");
	print_cray(stack_b, argc - 1);

	
	// printf("A val: %d | Target B index %d | Target B val: %d\n", stack_a->stack[3], find_target_b(stack_a, stack_b, argc - 1, 3), stack_b->stack[find_target_b(stack_a, stack_b, argc - 1, 3)]);
	// printf("A val: %d | Target B index %d | Target B val: %d\n", stack_a->stack[4], find_target_b(stack_a, stack_b, argc - 1, 4), stack_b->stack[find_target_b(stack_a, stack_b, argc - 1, 4)]);
	// printf("A val: %d | Target B index %d | Target B val: %d\n", stack_a->stack[7], find_target_b(stack_a, stack_b, argc - 1, 7), stack_b->stack[find_target_b(stack_a, stack_b, argc - 1, 7)]);
	// printf("A val: %d | Target B index %d | Target B val: %d\n", stack_a->stack[11], find_target_b(stack_a, stack_b, argc - 1, 11), stack_b->stack[find_target_b(stack_a, stack_b, argc - 1, 11)]);



}




// Main used for testing things

// int	main(void)
// {
// 	t_cray	*cr1;
// 	int		arrsz;

// 	arrsz = 5;
// 	cr1 = init_cray(arrsz);
// 	add_itm_tl(cr1, 1, arrsz);
// 	print_cray(cr1, arrsz);
// 	printf("Test ft_strlen for word: %lu\n", ft_strlen("word"));
// 	ft_printf("Testing ft_printf\n");
// }

