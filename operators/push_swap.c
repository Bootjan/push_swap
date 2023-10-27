/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:34:47 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 20:03:25 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap_operation(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!*stack || stack_len(*stack) <= 1)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_swap(t_stack **stack_a, t_stack **stack_b, int mode)
{
	if (mode == 0 && *stack_a)
	{
		swap_operation(stack_a);
		ft_printf("SA\n");
	}
	else if (mode == 1 && *stack_b)
	{
		swap_operation(stack_b);
		ft_printf("SB\n");
	}
	else if (mode == 2 && *stack_a && *stack_b)
	{
		swap_operation(stack_a);
		swap_operation(stack_b);
		ft_printf("SS\n");
	}
}

void	push_operation(t_stack **dst, t_stack **src)
{
	t_stack	*next_src;
	t_stack	*next_dst;

	if (stack_len(*src) == 0)
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
		ft_printf("PA\n");
	}
	else if (mode == 1 && *stack_a)
	{
		push_operation(stack_b, stack_a);
		ft_printf("PB\n");
	}
}
