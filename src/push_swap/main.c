/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:10:20 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:25:38 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in a an array of integers and the size of the array.
   Loads all of the integers into a circular array.
   - The last number in the input array will be added to the bottom of the stack
   - return:
		- NULL if malloc fails
		- stack: a circular buffer array populated with integers from the input
		array
*/

t_cray	*ps_init_stack(int arrsz, int *arr)
{
	t_cray	*stack;
	int		i;

	i = 0;
	stack = init_cray(arrsz);
	if (stack == NULL)
		return (NULL);
	if (arr != NULL)
	{
		while (i < arrsz)
		{
			add_itm_tl(stack, arr[i], arrsz);
			i++;
		}
	}
	return (stack);
}

/* Description: Takes in Stack A and Stack B and the number array.
   For each input, free the memory allocated if it is not NULL. 
*/
void	free_mem(t_cray *stack_a, t_cray *stack_b, int *arr)
{
	if (arr != NULL)
		free (arr);
	if (stack_a != NULL)
	{
		free (stack_a->stack);
		free (stack_a);
	}
	if (stack_b != NULL)
	{
		free (stack_b->stack);
		free (stack_b);
	}
}

/* Description: Function to be used when an error is encountered.
   Prints out Error\n and exits with 1.
*/
void	end_error(void)
{
	ft_printf("Error\n");
	exit (1);
}

/* Description: the main logic of push_swap. Actions:
   1. Validates the input with ps_input_validation
   2. Initialise Stacks A and Stacks B
   3. If Stack A has <= 3 elements, perform sort_three_less
   4. If Stack A has > 3 elements, perform turk sort
   5. Free all allocated memory
*/
int	main(int argc, char *argv[])
{
	int		*arr;
	t_cray	*stack_a;
	t_cray	*stack_b;

	arr = ps_input_validation(argc, argv);
	printf("after validation in main: %d, %d, %d\n", arr[0], arr[1], arr[2]);
	if (arr == NULL)
		end_error();
	stack_a = ps_init_stack((sizeof(*arr) / sizeof(int)), arr);
	stack_b = ps_init_stack((sizeof(*arr) / sizeof(int)), NULL);
	if (stack_a == NULL || stack_b == NULL)
	{
		free_mem(stack_a, stack_b, arr);
		end_error();
	}
	if (check_sorted(stack_a, (sizeof(*arr) / sizeof(int))) == 0)
	{
		if ((sizeof(*arr) / sizeof(int))<= 3)
			ps_sort_three_less(stack_a, (sizeof(*arr) / sizeof(int)), 'a');
		else
			ps_turk_sort(stack_a, stack_b, (sizeof(*arr) / sizeof(int)));
	}
	free_mem(stack_a, stack_b, arr);
	exit (0);
}
