/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_inputvalidation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:09:36 by mintan            #+#    #+#             */
/*   Updated: 2024/07/09 18:51:29 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: validates the incoming arguments received in main.
   - input: argc, argv[]
   - return:
   		- 1: if all the arguments are validated
		- 0: if there is no input
		- -1: if any of the arguments do not pass the validation
   - Validations - sequentially:
   		- no input
		- inputs are not integers or out of range
		- inputs are duplicated
		*/

int	ps_input_validation(int argc, char *argv[])
{
	int	ret;

	if (argc == 1)
		return (0);

}
