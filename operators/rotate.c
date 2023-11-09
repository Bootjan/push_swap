/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:08:58 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 19:08:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	rotate_operator(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	if (!stack || stack_len(*stack) <= 1)
		return (0);
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = first;
	return (1);
}

void	ft_rotate(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0)
	{
		if (rotate_operator(stack_a))
			write(1, "ra\n", 3);
	}
	else if (mode == 1)
	{
		if (rotate_operator(stack_b))
			write(1, "rb\n", 3);
	}
	else if (mode == 2)
	{
		if (rotate_operator(stack_a) && rotate_operator(stack_b))
			write(1, "rr\n", 3);
	}
}

static int	rev_rotate_operator(t_stack **stack)
{
	t_stack	*current;
	t_stack	*previous;

	if (!stack || stack_len(*stack) <= 1)
		return (0);
	current = *stack;
	previous = NULL;
	while (current->next)
	{
		previous = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	if (previous)
		previous->next = NULL;
	return (1);
}

void	ft_rrotate(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0)
	{
		if (rev_rotate_operator(stack_a))
			write(1, "rra\n", 4);
	}
	else if (mode)
	{
		if (rev_rotate_operator(stack_b))
			write(1, "rrb\n", 4);
	}
	else if (mode == 2)
	{
		if (rev_rotate_operator(stack_b) && rev_rotate_operator(stack_a))
			write(1, "rrr\n", 4);
	}
}
