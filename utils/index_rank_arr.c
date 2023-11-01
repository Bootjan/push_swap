/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_rank_arr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:01:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 15:15:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_first_smallest(t_stack *stack, int *smallest)
{
	t_stack	*current;
	int		index;
	int		i;

	current = stack;
	if (!current)
		return (-1);
	i = 0;
	index = 0;
	*smallest = current->data;
	while (current)
	{
		if (current->data < *smallest)
		{
			*smallest = current->data;
			index = i;
		}
		i++;
		current = current->next;
	}
	return (index);
}

int	first_unused_element(t_stack *current, int *last, int *smallest)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	while (current)
	{
		if (current->data > *last)
		{
			*smallest = current->data;
			index = i;
			break ;
		}
		i++;
		current = current->next;
	}
	return (index);
}

int	find_next_smallest(t_stack *stack, int *last)
{
	t_stack	*current;
	int		index;
	int		i;
	int		smallest;

	current = stack;
	if (!current)
		return (-1);
	i = 0;
	index = first_unused_element(stack, last, &smallest);
	while (current)
	{
		if (current->data < smallest && current->data > *last)
		{
			smallest = current->data;
			index = i;
		}
		i++;
		current = current->next;
	}
	*last = smallest;
	return (index);
}

int	*compute_index_rank(t_stack *stack)
{
	int	len;
	int	*rank_arr;
	int	index;
	int	last;
	int	i;

	len = stack_len(stack);
	rank_arr = ft_calloc(len, sizeof(int));
	if (!rank_arr)
		return (NULL);
	index = find_first_smallest(stack, &last);
	rank_arr[index] = 0;
	i = 1;
	while (i < len)
	{
		index = find_next_smallest(stack, &last);
		rank_arr[index] = i++;
	}
	return (rank_arr);
}
