/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_1.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/04 20:11:06 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

/* Description: Initialises a structure containing the stack. Allocates memory
   with malloc for the structure containing thefollowing members:
   - stack: an array of integers with size: arrsz. Memory allocated with malloc
   - count: the number of items in the array. Initialised as 0
   - headidx: the index of the head of the circular array. Initialised as 0
   - tailidx: the index of the tail of the circular array. Initialised as -1
   (behind the head)
   Returns a pointer to the structure.
*/
t_cray	*init_cray(int arrsz)
{
	t_cray	*cray;

	cray = (t_cray *)malloc(sizeof(t_cray));
	if (cray == NULL)
		return (NULL);
	cray->stack = (int *)malloc(arrsz * sizeof(int));
	if (cray->stack == NULL)
		return (free(cray), NULL);
	cray->count = 0;
	cray->headidx = 0;
	cray->tailidx = -1;
	return (cray);
}

/* Description: Checks if all indices of the cicular array is filled by
   comparing the count with the arrsz.
*/

int	chk_cray_full(t_cray *cray, int arrsz)
{
	return (cray->count == arrsz);
}

/* Description: Checks if the circular array is empty. Empty if count == 0.
*/
int	chk_cray_empty(t_cray *cray)
{
	return (cray->count == 0);
}

/* Description: adds an item into the circular array from the tail. Item is
   not added if the circular array is full already.
*/

void	add_itm_tl(t_cray *cray, int val, int arrsz)
{
	if (chk_cray_full < 0)
		return ;
	cray->count++;
	cray->tailidx = (cray->tailidx + 1) % arrsz;
	cray->stack[cray->tailidx] = val;
}

/* Description: adds an item into the circular array from the head. Item is
   not added if the circular array is full already.
*/

void	add_itm_hd(t_cray *cray, int val, int arrsz)
{
	if (chk_cray_full < 0)
		return ;
	cray->count++;
	cray->headidx = (cray->headidx - 1 + arrsz) % arrsz;
	cray->stack[cray->headidx] = val;
}
