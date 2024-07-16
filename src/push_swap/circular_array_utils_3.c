/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils_3.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 14:37:58 by mintan            #+#    #+#             */
/*   Updated: 2024/07/16 18:42:55 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in a circular array of integers and checks if the elements
   in the array are sorted in ascending order starting from the head. The 
   elements in the array should already be simplified [0, N).
   Return:
   - 0: circular array is not sorted yet
   - 1: cicurlar array is sorted already
   */

int	check_sorted(t_cray *cray, int arrsz)
{
	int	i;

	i = 0;
	while (i < arrsz)
	{
		if (cray->stack[(cray->headidx + i) % arrsz] != i)
			return (0);
		i++;
	}
	return (1);
}
