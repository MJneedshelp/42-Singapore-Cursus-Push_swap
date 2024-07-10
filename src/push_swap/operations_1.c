/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 13:45:47 by mintan            #+#    #+#             */
/*   Updated: 2024/07/09 15:19:53 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Swaps the first 2 elements at the top of a stack. Does nothing
   if the stack does not have any elements or only has 1 element. Prints out the
   operation s(a) or s(b) based on the input char c (stack name).
   */

void	ps_swap_stack(t_cray *stack, int arrsz, char c)
{
	swap(stack, arrsz);
	ft_printf("s%c\n", c);
}

/* Description: takes in 2 stacks and perform the swap operation on both stacks.
   Prints out the operation ss.
   */

void	ps_swap_both(t_cray *stack1, t_cray *stack2, int arrsz)
{
	swap(stack1, arrsz);
	swap(stack2, arrsz);
	ft_printf("ss\n");
}

/* Description: Removes the top of stack 1 and puts it at the top of stack 2.
   Does nothing if stack 1 is empty. Prints out the operation p(a) or p(b)
   based on the input char c.
   */

void	ps_push_stack(t_cray *stack1, t_cray *stack2, int arrsz, char c)
{
	int	stack_index;
	int	rm_val;

	stack_index = 0;
	rm_val = 0;
	stack_index = rm_itm_hd(stack1, arrsz);
	if (stack_index >= 0)
	{
		rm_val = stack1->stack[stack_index];
		add_itm_hd(stack2, rm_val, arrsz);
	}
	ft_printf("p%c\n", c);
}

/* Decription: Rotates the stack clockwise (head becomes the tail). Prints
   out the operation r(a) or r(b) based on the input char c.
  */

void	ps_rotate_stack(t_cray *stack, int arrsz, char c)
{
	rotate_cw(stack, arrsz);
	ft_printf("r%c\n", c);
}

/* Description: rotates the stack counter-clockwise (tail becomes head).
   Prints out the operation rr(a) or rr(b) based on the input char c.
   */

void	ps_rev_rotate_stack(t_cray *stack, int arrsz, char c)
{
	rotate_ccw(stack, arrsz);
	ft_printf("rr%c\n", c);
}
