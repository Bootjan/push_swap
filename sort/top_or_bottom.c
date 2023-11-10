/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   top_or_bottom.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:04:28 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 12:07:50 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_first(t_stack *stack_a, int max)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack_a;
	if (!current)
		return (-1);
	while (current)
	{
		if (current->data <= max)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

static int	find_last(t_stack *stack_a, int max)
{
	t_stack	*current;
	int		i;
	int		index;

	index = -1;
	current = stack_a;
	if (!current)
		return (-1);
	i = 0;
	while (current)
	{
		if (current->data <= max)
			index = i;
		i++;
		current = current->next;
	}
	return (index);
}

static int	distance_to_border(int len, int index_first, int index_bottom)
{

	int	distance_bottom;

	distance_bottom = len - index_bottom - 1;
	if (distance_bottom < index_first)
		return (BOTTOM);
	return (TOP);
}

int	pull_from_top_bottom(t_stack *stack_a, int max, int *distance)
{
	int	index_first;
	int	index_bottom;
	int	len;

	index_first = find_first(stack_a, max);
	index_bottom = find_last(stack_a, max);
	len = stack_len(stack_a);
	if (distance_to_border(len, index_first, index_bottom) == TOP)
		return (*distance = index_first, TOP);
	return (*distance = len - index_bottom - 1, BOTTOM);
}
