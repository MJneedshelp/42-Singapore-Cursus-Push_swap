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
	cray->tailidx = 0;
	return (cray);
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
	cray->count++;
	// printf("No. items: %d\n", cray->count);
	cray->stack[cray->tailidx] = val;
	// printf("%d\n", cray->stack[cray->tailidx]);
	cray->tailidx = (cray->tailidx + 1) % arrsz;
}

int	rm_itm(t_cray *cray, int arrsz)
{
	int	rmitm_val;

	if (chk_cray_empty == 1)
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
		count++;
	}
}

int	main(void)
{
	t_cray *cray1;
	int		arrsz;
	int		p_itm;

	arrsz = 5;
	cray1 = init_cray(arrsz);
	printf("After init. Stack addr: %p | Arrsz: %d | No. items: %d | Head index: %d | Tail index: %d\n",cray1->stack, arrsz, cray1->count, cray1->headidx, cray1->tailidx);

	add_itm(cray1, 1, arrsz);
	add_itm(cray1, 2, arrsz);
	add_itm(cray1, 3, arrsz);
	add_itm(cray1, 4, arrsz);
	p_itm = rm_itm(cray1, arrsz);
	printf("Removed item: %d\n", p_itm);
	// printf("%d\n", cray1->stack[0]);
	print_cray(cray1, arrsz);
}
