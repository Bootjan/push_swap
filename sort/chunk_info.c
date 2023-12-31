/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:31:20 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/13 14:31:44 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	compute_curr_chunks_len(int len)
{
	if (len > 200)
		return (45);
	if (len <= 15)
		return (len);
	return (15);
}

static int	find_smallest(int *arr, t_stack *stack, int len_arr)
{
	t_stack	*current;
	int		smallest;

	current = stack;
	while (current)
	{
		if (!ft_in_list(arr, len_arr, current->data))
		{
			smallest = current->data;
			break ;
		}
		current = current->next;
	}
	while (current)
	{
		if (current->data < smallest && \
		!ft_in_list(arr, len_arr, current->data))
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	*compute_chunk_numbers(t_stack *stack, int len)
{
	int	i;
	int	*arr;

	arr = ft_calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = find_smallest(arr, stack, i);
		i++;
	}
	return (arr);
}
