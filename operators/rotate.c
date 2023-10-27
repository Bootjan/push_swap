/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:08:58 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 20:14:18 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rotate_operator(t_stack **stack)
{
	t_stack	*first;
	t_stack	*current;

	first = *stack;
	if (!first || stack_len(first) <= 1)
		return ;
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
		ft_printf("RA\n");
	}
	else if (mode == 1)
	{
		rotate_operator(stack_b);
		ft_printf("RB\n");
	}
	else if (mode == 2)
	{
		rotate_operator(stack_a);
		rotate_operator(stack_b);
		ft_printf("RR\n");
	}
}
