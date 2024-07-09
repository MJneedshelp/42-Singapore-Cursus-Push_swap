/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:45:47 by mintan            #+#    #+#             */
/*   Updated: 2024/07/09 16:37:22 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in 2 stacks and performs the rotate clockwise operation
   on both stacks. Prints out the operation rr.
   */

void	ps_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz)
{
	rotate_cw(stack1, arrsz);
	rotate_cw(stack2, arrsz);
	ft_printf("rr\n");
}

/* Description: Takes in 2 stacks and performs the rotate counter clockwise 
   operation on both stacks. Prints out the operation rrr.
   */

void	ps_rev_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz)
{
	rotate_ccw(stack1, arrsz);
	rotate_ccw(stack2, arrsz);
	ft_printf("rrr\n");
}
