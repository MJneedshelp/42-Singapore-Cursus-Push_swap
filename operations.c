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

#include "push_swap.h"

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
