/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_input_validation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 18:09:36 by mintan            #+#    #+#             */
/*   Updated: 2024/07/23 14:31:17 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "../../include/push_swap.h"
#include "../../include/libft.h"
#include "../../include/ft_printf.h"

/* Description: Takes in a string and checks if all characters are digits.
   - Allows for ' ', '\t', '\r', at the start of the string.
   - Allows for either 1 '+' or '-' after the spaces, before the digits
   - return:
		- 1: the string is numeric
		- 0: the string is not numeric
   */

int	check_numeric(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= '\t' && str[i] <= '\r') || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/* Description: Takes in an array of integers and checks if there are duplicate
   values within the array.
   - return:
		- 1: no duplicates
		- 0: contains duplicates
   */

int	check_duplicate(int *arr, int arrsz)
{
	int	i;
	int	j;

	i = 0;
	while (i < arrsz)
	{
		j = i + 1;
		while (j < arrsz)
		{
			if (arr[i] == arr[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

/* Description: Takes in a array of integers, which can contain negative
   numbers, and an integer value: least. Returns the index of the next smallest
   element after least.
*/
int	find_next_least(int *arr, int arrsz, long least)
{
	int	retidx;
	int	i;
	int	next_least;

	i = 0;
	retidx = 0;
	next_least = INT_MAX;
	while (i < arrsz)
	{
		if (arr[i] < next_least && arr[i] > least)
		{
			retidx = i;
			next_least = arr[i];
		}
		i++;
	}
	return (retidx);
}

/* Description: Takes in an array of integers, which can contain negative
   numbers and converts all the integers to positive integers starting
   with 0. The relative positions the integers in the original array is
   preserved.
*/

int	*simplify_arr(int *arr, int arrsz)
{
	int		*ret;
	long	least;
	int		least_idx;
	int		i;

	i = 0;
	least = (long)INT_MIN - 1;
	ret = (int *)malloc(arrsz * sizeof(int));
	if (ret == NULL)
		return (NULL);
	while (i < arrsz)
	{
		least_idx = find_next_least(arr, arrsz, least);
		least = arr[least_idx];
		ret[least_idx] = i;
		i++;
	}
	free(arr);
	return (ret);
}

/* Description: validates the incoming arguments received in main. Simplifies
   the resulting array by converting everything to positive integers and
   maintaining the relative positions of the elements: [0, N).
   - input: argc, argv[]
   - return:
   		- array of integers: if all the arguments are validated
		- NULL: if any of the arguments do not pass the validation
   - Validations - sequentially:
   		- no input
		- inputs are not integers or out of range
		- inputs are duplicated
*/

int	*ps_input_validation(int argc, char *argv[])
{
	int	*ret;
	int	i;

	i = 0;
	if (argc == 2)
	{
		printf("inside validation: %s\n", argv[1]);
		ret = ps_validate_one_input(argv[1]);
		printf("after validation: %d, %d, %d\n", ret[0], ret[1], ret[2]);
		if (ret == NULL)
			return (NULL);
	}
	else
	{
		ret = (int *)malloc((argc - 1) * sizeof(int));
		if (ret == NULL)
			return (NULL);
		while (i++ < argc - 1)
		{
			if (check_numeric(argv[i]) == 0)
				return (free(ret), NULL);
			if (ft_atol(argv[i]) > INT_MAX || ft_atol(argv[i]) < INT_MIN)
				return (free(ret), NULL);
			ret[i - 1] = ft_atoi(argv[i]);
		}
		if (check_duplicate(ret, argc - 1) == 0)
			return (free(ret), NULL);
		ret = simplify_arr(ret, argc - 1);
		if (ret == NULL)
			return (NULL);
	}
	return (ret);
}
