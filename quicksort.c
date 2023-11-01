/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 13:18:59 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 13:52:19 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

void	push_back(t_stack **stack, t_stack *element)
{
	t_stack	*current;

	current = *stack;
	element->next = NULL;
	if (!current)
	{
		*stack = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}

t_stack	*get_last_element(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!current)
		return (0);
	while (current->next)
		current = current->next;
	return (current);
}

t_stack	*append_current(t_stack **right, t_stack **left, t_stack *current, \
int pivot)
{
	t_stack	*next;

	if (!current)
		return (NULL);
	next = current->next;
	if (current->data > pivot)
		push_back(right, current);
	else
		push_back(left, current);
	return (next);
}

t_stack	*quicksort(t_stack *stack, int len)
{
	t_stack	*pivot;
	t_stack	*left;
	t_stack	*right;
	t_stack	*current;
	int		i;

	i = 0;
	left = NULL;
	right = NULL;
	current = stack;
	if (!current)
		return (NULL);
	pivot = get_last_element(stack);
	while (current && i++ < len - 1)
		current = append_current(&right, &left, current, pivot->data);
	right = quicksort(right, stack_len(right));
	left = quicksort(left, stack_len(left));
	pivot->next = right;
	push_back(&left, pivot);
	return (left);
}
