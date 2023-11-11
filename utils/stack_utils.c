/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:55:00 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/11 16:24:10 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*current;

	len = 0;
	current = stack;
	if (!current)
		return (0);
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current || !current->next)
		return (1);
	while (current->next)
	{
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}
