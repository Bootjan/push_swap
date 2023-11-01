/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:45 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/31 16:16:04 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	compute_power_10(int num)
{
	int	out;

	if (num == 0)
		return (0);
	out = 1;
	while (num > 9)
	{
		out++;
		num /= 10;
	}
	return (out);
}
int	compute_biggest_num(int *arr, size_t len)
{
	size_t	i;
	int		biggest;

	if (len == 0)
		return (0);
	biggest = arr[i];
	i = 1;
	while (i < len)
	{
		if (arr[i] > biggest)
			biggest = arr[i];
		i++;
	}
	return (biggest);
}

int	*radix_sort(int *arr, size_t len)
{
	int	biggest_num;
	int	i;

	biggest_num = compute_biggest_num(arr, len);
	i = 1;
	while (i <= biggest_num)
	{
		
	}
}