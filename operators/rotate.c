/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:08:58 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/30 15:01:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate_operator(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	if (!stack || stack_len(*stack) <= 1)
		return ;
	first = *stack;
	*stack = first->next;
	first->next = NULL;
	current = *stack;
	while (current->next)
		current = current->next;
	current->next = first;
}

void	ft_rotate(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0)
	{
		rotate_operator(stack_a);
		ft_printf("ra\n");
	}
	else if (mode == 1)
	{
		rotate_operator(stack_b);
		ft_printf("rb\n");
	}
	else if (mode == 2)
	{
		rotate_operator(stack_a);
		rotate_operator(stack_b);
		ft_printf("rr\n");
	}
}

static void	rev_rotate_operator(t_stack **stack)
{
	t_stack	*current;
	t_stack	*last;

	if (!stack || stack_len(*stack) <= 1)
		return ;
	current = *stack;
	while (current->next)
		current = current->next;
	last = current->next;
	current->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	ft_rrotate(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0)
	{
		rev_rotate_operator(stack_a);
		ft_printf("rra\n");
	}
	else if (mode == 1)
	{
		rev_rotate_operator(stack_b);
		ft_printf("rrb\n");
	}
	else if (mode == 2)
	{
		rev_rotate_operator(stack_a);
		rev_rotate_operator(stack_b);
		ft_printf("rrr\n");
	}
}
