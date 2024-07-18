/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Test_argc_argv.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mintan <mintan@student.42singapore.sg>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 23:31:00 by mintan            #+#    #+#             */
/*   Updated: 2024/07/05 23:31:00 by mintan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include "../include/libft.h"

int main(int argc, char *argv[])
{
	printf("No. of arguments: %d\n", argc);
	for(int i = 0; i < argc; i++)
		printf("argument: %d | value: %s\n", i, argv[i]);
}
11