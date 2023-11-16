/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_second_max.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 14:12:03 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/13 14:13:06 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index_max(t_stack *stack_b, int *max)
{
	t_stack	*current;
	int		index;
	int		i;

	current = stack_b;
	i = 1;
	index = 0;
	*max = current->data;
	current = current->next;
	while (current)
	{
		if (current->data > *max)
		{
			index = i;
			*max = current->data;
		}
		i++;
		current = current->next;
	}
	return (index);
}

static int	init_vars(t_stack *stack_b, t_stack **current, \
int *index_second_max, int max)
{
	int	second_max;

	*index_second_max = 0;
	second_max = stack_b->data;
	*current = stack_b->next;
	if (second_max == max && *current)
	{
		*index_second_max = 1;
		second_max = (*current)->data;
		*current = (*current)->next;
	}
	return (second_max);
}

int	find_second_max(t_stack *stack_b, int max)
{
	int		index_second_max;
	int		i;
	int		second_max;
	t_stack	*current;

	second_max = init_vars(stack_b, &current, &index_second_max, max);
	i = 1;
	if (second_max != stack_b->data)
		i = 2;
	while (current)
	{
		if (current->data > second_max && current->data < max)
		{
			index_second_max = i;
			second_max = current->data;
		}
		i++;
		current = current->next;
	}
	return (index_second_max);
}
