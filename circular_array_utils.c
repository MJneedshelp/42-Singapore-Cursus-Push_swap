/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circular_array_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 21:56:37 by mintan            #+#    #+#             */
/*   Updated: 2024/07/03 21:56:37 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Description:
*/
void	init_cray(t_cray *cray, int arrsz)
{
	//cray->stack = (int *)malloc(arrsz * sizeof(int));
	printf("inside init\n");
	//if (cray->stack == NULL)
	//	return (NULL);
	cray->count = 10;
	printf("assign\n");
	cray->headidx = 0;
	cray->tailidx = 0;
}

int		chk_cray_full(t_cray *cray, int arrsz)
{
	return (cray->count == arrsz);
}

int		chk_cray_empty(t_cray *cray)
{
	return (cray->count == 0);
}

void	add_itm(t_cray *cray, int val, int arrsz)
{
	if (!chk_cray_full)
		return;
	printf("Inside add item before. Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d | val: %d\n", arrsz, cray->count, cray->headidx, cray->tailidx, val);
	cray->count++;
	printf("No. items: %d\n", cray->count);
	cray->stack[cray->tailidx] = val;
	printf("%d\n", cray->stack[cray->tailidx]);
	cray->tailidx = (cray->tailidx + 1) % arrsz;
	printf("Inside add item after. Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n", arrsz, cray->count, cray->headidx, cray->tailidx);
}

int	rm_itm(t_cray *cray, int arrsz)
{
	int	rmitm_val;

	if (chk_cray_empty)
		return (NULL);
	rmitm_val = cray->stack[cray->headidx];
	cray->headidx = (cray->headidx + 1) % arrsz;
	cray->count--;
	return (rmitm_val);
}

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
	}
}

int	main(void)
{
	t_cray *cray1;
	int		arrsz;

	arrsz = 5;
	printf("here\n");
	init_cray(cray1, arrsz);
	printf("After init. Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n", arrsz, cray1->count, cray1->headidx, cray1->tailidx);
	printf("Count: %d\n", cray1->count);
	//(cray1->stack)[0] = 1;
	//printf("&d\n", cray1->stack[0]);
	/*
	add_itm(cray1, 1, arrsz);
	add_itm(cray1, 2, arrsz);
	add_itm(cray1, 3, arrsz);
	add_itm(cray1, 4, arrsz);
	print_cray(cray1, arrsz);*/
}
