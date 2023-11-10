/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_index_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:11:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:11:47 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	data_last_el(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current->next)
		current = current->next;
	return (current->data);
}

static int	find_new_index_back(t_stack *stack_b, int new_el)
{
	t_stack	*current;
	int		index;

	current = stack_b;
	index = 0;
	while (current && new_el > current->data)
	{
		current = current->next;
		index++;
	}
	return (index);
}

int	find_new_index(t_stack *stack_b, int new_el)
{
	t_stack	*current;
	int		index;
	int		len;

	index = 0;
	current = stack_b;
	len = stack_len(stack_b);
	while (current && new_el < current->data)
	{
		current = current->next;
		index++;
	}
	if (index == 0 && data_last_el(stack_b) < new_el)
		index = find_new_index_back(stack_b, new_el);
	if (index == len)
		return (0);
	return (index);
}
