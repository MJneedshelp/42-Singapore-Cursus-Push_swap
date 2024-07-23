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




int	find_stray_sz(char **stray)
{
	int	stray_sz;

	stray_sz = 0;
	while (stray[stray_sz] != NULL)
	{
		stray_sz++;
	}
	return (stray_sz);
}



/* Description: Takes in a string and splits it into an array of strings
   XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXx
   WRITE THIS LATER
*/
int	*ps_validate_one_input(char *arg1)
{
	int		*ret;
	char	**stray;
	int		stray_sz;
	int		i;

	i = 0;
	stray = ft_split(arg1, ' ');
	if (stray == NULL)
		return (NULL);
	printf("After ft_split: %s, %s | %d\n", stray[1], stray[2], ft_atoi(stray[1]));
	stray_sz = find_stray_sz(stray);
	printf("Stray size: %d\n", stray_sz);
	ret = (int *)malloc(stray_sz * sizeof(int));
	if (ret == NULL)
		return (free (stray), NULL);
	while (i < stray_sz)
	{
		if (check_numeric(stray[i]) == 0)
			return (free(ret), free(stray), NULL);
		if (ft_atol(stray[i]) > INT_MAX || ft_atol(stray[i]) < INT_MIN)
			return (free(ret), free(stray), NULL);
		ret[i] = ft_atoi(stray[i]);
		i++;
	}
	if (check_duplicate(ret, stray_sz) == 0)
		return (free(ret), free(stray), NULL);
	ret = simplify_arr(ret, stray_sz);
	if (ret == NULL)
		return (free(ret), free(stray), NULL);
	return (ret);
}