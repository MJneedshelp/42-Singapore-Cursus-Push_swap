/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:10:20 by mintan            #+#    #+#             */
/*   Updated: 2024/07/07 19:29:18 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"



//Proper main
int	main(int argc, char	*argv[])
{
	//1. Input validation (probably can be 1 file by itself):
	//	- input: argc, argv[]
	//	- return:
	//		- array of integers if all items are validated
	//		- NULL pointer if argc == 1 (no input)
	//		-
	//	- Acions: checks the following
	//		- no input
	//			- atoi for each argument
	//			- inputs are not integers
	//		- not numbers
	//		- out of range of integers
	//		- Duplicate numbers

	//2. Init stack x 2 for A and B stack (probably can be 1 file by itself)
	//	- input: array from 1, argc (count of items in array)
	//	- return: cray A
	//	- Actions:
	//		- init_cray
	//		- if array is not NULL
	//			- while not arrsz, add items into stack

	//3. Algorithm function
	//	- input: stacks A and B
	//	- return: void
	//	- Actions:
	//		- perform algo to sort stack A
	//		- tbd
}







// Main used for testing things
/*
int	main(void)
{
	t_cray	*cr1;
	int		arrsz;

	arrsz = 5;
	cr1 = init_cray(arrsz);
	add_itm_tl(cr1, 1, arrsz);
	print_cray(cr1, arrsz);
	printf("Test ft_strlen for word: %lu\n", ft_strlen("word"));
	ft_printf("Testing ft_printf\n");
}
*/
