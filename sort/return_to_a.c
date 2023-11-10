/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:14:39 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:41:48 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	find_index_max(t_stack *stack_b)
{
	t_stack	*current;
	int		index;
	int		max;
	int		i;

	current = stack_b;
	i = 1;
	index = 0;
	max = current->data;
	current = current->next;
	while (current)
	{
		if (current->data > max)
		{
			index = i;
			max = current->data;
		}
		i++;
		current = current->next;
	}
	return (index);
}

static void	push_to_a_top(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		ft_rotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, A);
}

static void	push_to_a_bottom(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		ft_rrotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, A);
}

void	push_to_a(t_stack **stack_a, t_stack **stack_b)
{
	int	index_max;
	int	len;

	while (*stack_b)
	{
		index_max = find_index_max(*stack_b);
		len = stack_len(*stack_b);
		if (index_max <= len >> 1)
			push_to_a_top(stack_a, stack_b, index_max);
		else
			push_to_a_bottom(stack_a, stack_b, len - index_max);
	}
}
