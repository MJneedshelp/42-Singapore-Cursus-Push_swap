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
   head by incrementing the headidx. Returns the old head index before the
   increment. If the circular array is empty, return -1.
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
