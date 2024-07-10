/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_stack_initialisation.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 08:25:11 by mintan            #+#    #+#             */
/*   Updated: 2024/07/10 08:25:11 by mintan           ###   ########.fr       */
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

// Testing for stack initialisation
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
	print_cray(stack_a, argc - 1);
	print_cray(stack_b, argc - 1);
}
*/

