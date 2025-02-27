/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test Circular Array.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/09 14:02:30 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"
#include "../include/libft.h"
#include "../include/ft_printf.h"

int	main(void)
{
	t_cray	*cray1;
	int		arrsz;
	int		p_itm;

	arrsz = 5;
	cray1 = init_cray(arrsz);
	printf("After init. Stack addr: %p | Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n", cray1->stack, arrsz, cray1->count, cray1->headidx, cray1->tailidx);

	add_itm_tl(cray1, 1, arrsz);
	add_itm_tl(cray1, 2, arrsz);
	add_itm_tl(cray1, 3, arrsz);
	add_itm_tl(cray1, 4, arrsz);
	add_itm_tl(cray1, 5, arrsz);
	print_cray(cray1, arrsz);
	printf("After adding. Stack addr: %p | Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n",cray1->stack, arrsz, cray1->count, cray1->headidx, cray1->tailidx);


	p_itm = rm_itm_hd(cray1, arrsz);
	printf("Removed item: %d\n", cray1->stack[p_itm]);
	p_itm = rm_itm_hd(cray1, arrsz);
	printf("Removed item: %d\n", cray1->stack[p_itm]);

	add_itm_tl(cray1, 6, arrsz);
	//add_itm_tl(cray1, 7, arrsz);
	printf("After adding. Stack addr: %p | Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n",cray1->stack, arrsz, cray1->count, cray1->headidx, cray1->tailidx);
	print_cray(cray1, arrsz);
	printf("Perform swap. Stack after swap\n");
	swap(cray1, arrsz);
	print_cray(cray1, arrsz);
	printf("Perform swap again. Stack after swap\n");
	swap(cray1, arrsz);
	print_cray(cray1, arrsz);
	printf("Rotate cw. Stack after rotation\n");
	rotate_cw(cray1, arrsz);
	print_cray(cray1, arrsz);
	add_itm_hd(cray1, 7, arrsz);
	print_cray(cray1, arrsz);
	rm_itm_tl(cray1, arrsz);
	print_cray(cray1, arrsz);
	printf("Rotate ccw. Stack after rotation\n");
	rotate_ccw(cray1, arrsz);
	print_cray(cray1, arrsz);
	printf("Swap with the ps_swap_stack function");
	ps_swap_stack(cray1, arrsz, 'a');
	print_cray(cray1, arrsz);
}
