/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/06 00:10:20 by mintan            #+#    #+#             */
/*   Updated: 2024/07/07 19:29:18 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

int	main(void)
{
	t_cray	*cr1;
	int		arrsz;

	arrsz = 5;
	cr1 = init_cray(arrsz);
	add_itm_tl(cr1, 1, arrsz);
	print_cray(cr1, arrsz);
	printf("Test ft_strlen for word: %lu\n", ft_strlen("word"));
	ft_printf("Testing ft_printf\n");
}

/*
main workflow
1. Input validation (probably can be 1 file by itself):
	- no input
	- inputs are not integers
		- not numbers
		- out of range of integers
	- Duplicate numbers

*/
