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


/* Description: Finds the smallest element in a stack and returns the index of
   the element.
*/

int	sort_utils_find_least(t_cray *stk, int arrsz)
{
	int	curr_idx;
	int	lowest;
	int	i;

	i = 0;
	lowest = stk->stack[stk->headidx];
	curr_idx = stk->headidx;
	printf("Before while. Lowest: %d | idx: %d | i: %d | count: %d\n", lowest, idx, i, stk->count);
	while (i < stk->count)
	{
		if (stk->stack[(idx + i + 1) % arrsz] < lowest)
		{
			lowest = stk->stack[(idx + i + 1) % arrsz];
			//idx = (idx + 1) % arrsz;
			printf("Inside while if. Lowest: %d | idx: %d\n", lowest, idx);
		}
		i++;
	}
	return (idx);
}
