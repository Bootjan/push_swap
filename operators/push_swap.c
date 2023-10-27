/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:34:47 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 23:36:11 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_operation(t_stack **stack)
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
		ft_printf("sa\n");
	}
	else if (mode == 1)
	{
		swap_operation(stack_b);
		ft_printf("sb\n");
	}
	else if (mode == 2)
	{
		swap_operation(stack_a);
		swap_operation(stack_b);
		ft_printf("ss\n");
	}
}

void	push_operation(t_stack **dst, t_stack **src)
{
	t_stack	*next_src;
	t_stack	*next_dst;

	if (!src || !dst || stack_len(*src) == 0)
		return ;
	next_dst = NULL;
	next_src = (*src)->next;
	if (*dst)
		next_dst = *dst;
	*dst = *src;
	*src = next_src;
	(*dst)->next = next_dst;
}

void	ft_push(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0 && *stack_b)
	{
		push_operation(stack_a, stack_b);
		ft_printf("pa\n");
	}
	else if (mode == 1 && *stack_a)
	{
		push_operation(stack_b, stack_a);
		ft_printf("pb\n");
	}
}
