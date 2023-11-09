/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:34:47 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 19:24:43 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_operation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || stack_len(*stack) <= 1)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_swap(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0)
	{
		swap_operation(stack_a);
		write(1, "sa\n", 3);
	}
	else if (mode == 1)
	{
		swap_operation(stack_b);
		write(1, "sb\n", 3);
	}
	else if (mode == 2)
	{
		swap_operation(stack_a);
		swap_operation(stack_b);
		write(1, "ss\n", 3);
	}
}

static int	push_operation(t_stack **dst, t_stack **src)
{
	t_stack	*next_src;
	t_stack	*next_dst;

	if (!src || stack_len(*src) == 0)
		return (0);
	next_dst = NULL;
	next_src = (*src)->next;
	if (*dst)
		next_dst = *dst;
	*dst = *src;
	*src = next_src;
	(*dst)->next = next_dst;
	return (1);
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == A && *stack_b)
	{
		if (push_operation(stack_a, stack_b))
			write(1, "pa\n", 3);
	}
	else if (mode == B && *stack_a)
	{
		if (push_operation(stack_b, stack_a))
			write(1, "pb\n", 3);
	}
}
