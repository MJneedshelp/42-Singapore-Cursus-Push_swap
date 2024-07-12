/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:42:24 by mintan            #+#    #+#             */
/*   Updated: 2024/07/09 18:51:35 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Maybe remove this afterwards
# include <stdio.h>
# include <stdlib.h>
# include "libft.h"
# include "ft_printf.h"

typedef struct s_circlearray
{
	int	*stack;
	int	headidx;
	int	tailidx;
	int	count;
}	t_cray;

/* Circular Array Utilities */
t_cray	*init_cray(int arrsz);
int		chk_cray_full(t_cray *cray, int arrsz);
int		chk_cray_empty(t_cray *cray);
void	add_itm_tl(t_cray *cray, int val, int arrsz);
void	add_itm_hd(t_cray *cray, int val, int arrsz);
int		rm_itm_hd(t_cray *cray, int arrsz);
int		rm_itm_tl(t_cray *cray, int arrsz);
void	print_cray(t_cray *cray, int arrsz);
int		find_least(t_cray *cray, int arrsz);
int		find_dist(int arrsz, int from, int to);

/* push_swap Operations Utilities */
void	swap(t_cray *cray, int arrsz);
void	rotate_cw(t_cray *cray, int arrsz);
void	rotate_ccw(t_cray *cray, int arrsz);

/* push_swap Operations */
void	ps_swap_stack(t_cray *stack, int arrsz, char c);
void	ps_push_stack(t_cray *stack1, t_cray *stack2, int arrsz, char c);
void	ps_rotate_stack(t_cray *stack, int arrsz, char c);
void	ps_rev_rotate_stack(t_cray *stack, int arrsz, char c);
void	ps_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz);
void	ps_rev_rotate_both(t_cray *stack1, t_cray *stack2, int arrsz);

/* push_swap main steps */
int		*ps_input_validation(int argc, char *argv[]);
t_cray	*ps_init_stack(int arrsz, int *arr);

/* Sort Utilities*/
void	rotate_to_head(t_cray *stk, int arrsz, int index);


#endif
