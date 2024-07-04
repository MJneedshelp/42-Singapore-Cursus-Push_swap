/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:42:24 by mintan            #+#    #+#             */
/*   Updated: 2024/07/04 20:32:27 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

//Maybe remove this afterwards
# include <stdio.h>
# include <stdlib.h>

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
void	add_itm(t_cray *cray, int val, int arrsz);
int		rm_itm(t_cray *cray, int arrsz);
void	print_cray(t_cray *cray, int arrsz);


#endif
