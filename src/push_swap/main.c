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

	//probably need to do smth here

	stack_a = ps_init_stack(argc - 1, arr);
	stack_b = ps_init_stack(argc - 1, NULL);

	// printf("Stack A\n");
	// print_cray(stack_a, argc - 1);
	// printf("Stack B\n");
	// print_cray(stack_b, argc - 1);

	if (check_sorted(stack_a, argc - 1) == 0)
	{
		if (argc - 1 <= 3)
			ps_sort_three_less(stack_a, argc - 1, 'a');
		else
			ps_turk_sort(stack_a, stack_b, argc - 1);
	}
	
	// printf("Stack A\n");
	// print_cray(stack_a, argc - 1);
	// printf("Stack B\n");
	// print_cray(stack_b, argc - 1);
	
	//need to free all the memory here

}





