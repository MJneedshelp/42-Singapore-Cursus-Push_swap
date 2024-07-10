/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_insertion_sort.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:48:53 by mintan            #+#    #+#             */
/*   Updated: 2024/07/10 21:48:53 by mintan           ###   ########.fr       */
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

int	sort_utils_find_least(t_cray *stack)
{
	int	idx;
	int	lowest;
	int	i;

	i = 0;
	lowest = stack->stack[stack->headidx];
	idx = stack->headidx;
	while (i < stack->count)
	{

	}
}
