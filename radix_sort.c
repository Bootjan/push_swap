/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:45 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/30 15:20:14 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	compute_biggest_num(int *arr, size_t len)
{
	size_t	i;
	int		biggest;
	int		out;

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
	out = 1;
	while (biggest > 9)
	{
		out++;
		biggest /= 10;
	}
	return (out);
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