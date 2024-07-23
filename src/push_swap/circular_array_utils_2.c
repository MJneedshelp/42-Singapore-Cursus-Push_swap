/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:27:48 by mintan           ###   ########.fr       */
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
   tail by decrementing the tailidx. Returns the old tail index before the
   decrement. If the circular array is empty, return -1.
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
   than the given value (max) and returns the index of the element.
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
		cray->stack[(hdidx + i) % arrsz] > prev_max)
		{
			prev_max = cray->stack[(hdidx + i) % arrsz];
			retidx = (hdidx + i) % arrsz;
		}
		i++;
	}
	return (retidx);
}
