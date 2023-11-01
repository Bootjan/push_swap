/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:45 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 17:18:52 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_max(int *arr, int len)
{
	int	i;
	int	max;

	if (!arr)
		return (-1);
	max = arr[0];
	i = 1;
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

void	radix_sort(int *arr, t_stack **stack_a, int len)
{
	t_stack	*stack_b;

	stack_b = NULL;
	
}