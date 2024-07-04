/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/04 20:25:40 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Description: Swaps the head item with the next adjacent item. No action
   performed if the circular array is empty or if it has less than 2 items.
*/

void	swap(t_cray *cray, int arrsz)
{
	int	temp;

	if (chk_cray_empty(cray) == 1 || cray->count < 2)
		return ;
	temp = cray->stack[cray->headidx];
	cray->stack[cray->headidx] = cray->stack[(cray->headidx + 1) % arrsz];
	cray->stack[cray->headidx + 1] = temp;
}

/* Description: Rotates the circular array clockwise:
   - remove the head
   - add the head value to tail of the queue
   - No action performed if the circular array has less than 2 items.
*/

void	rotate_cw(t_cray *cray, int arrsz)
{
	int	temp;

	if (cray->count < 2)
		return ;
	temp = cray->stack[rm_itm(cray, arrsz)];
	add_itm(cray, temp, arrsz);
}
