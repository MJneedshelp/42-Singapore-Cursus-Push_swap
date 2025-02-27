/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:37:58 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:24:23 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Finds the closest element in a circular array that is bigger
   than the given value (max) and returns the index of the element.
*/

int	find_next_max(t_cray *cray, int arrsz, int max)
{
	int	hdidx;
	int	next_max;
	int	retidx;
	int	i;

	i = 0;
	next_max = INT_MAX;
	hdidx = cray->headidx;
	while (i < cray->count)
	{
		if (cray->stack[(hdidx + i) % arrsz] > max && \
		cray->stack[(hdidx + i) % arrsz] < next_max)
		{
			next_max = cray->stack[(hdidx + i) % arrsz];
			retidx = (hdidx + i) % arrsz;
		}
		i++;
	}
	return (retidx);
}

/* Description: Finds the distance between 2 elements in a circular array.
   Usually used to find the distance between an element and the head or tail
   of the circular array.
*/

int	find_dist(int arrsz, int from, int to)
{
	int	dist;

	dist = (to - from + arrsz) % arrsz;
	return (dist);
}

/* Description: Finds out if an element is closer to the head or tail of
   a circular array by finding the distance of the element to the head or
   tail.
   Return:
   - 1: Distance to head <= distance to tail + 1
   - 0: Distance to head > distance to tail + 1
*/
int	head_or_tail(t_cray *cray, int arrsz, int index)
{
	int	dist_to_head;
	int	dist_to_tail;

	dist_to_head = find_dist(arrsz, cray->headidx, index);
	dist_to_tail = find_dist(arrsz, index, cray->tailidx);
	if (dist_to_head <= dist_to_tail)
		return (1);
	return (0);
}

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

/* Description: Prints the circular array starting from the head index to the
   tail index. Only prints out the number of items in the circular array and
   not all the items in the array by using the count.
*/

void	print_cray(t_cray *cray, int arrsz)
{
	int	start;
	int	count;

	start = cray->headidx;
	count = 0;
	ft_printf("Arrsz: %d | No. items: %d | Head index: %d | Tail index:\
	%d\n", arrsz, cray->count, cray->headidx, cray->tailidx);
	while (count < cray->count)
	{
		ft_printf("%d\n", cray->stack[start]);
		start = (start + 1) % arrsz;
		count++;
	}
}
