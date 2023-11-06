/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pull_from_bottom.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:39:29 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/06 14:35:27 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	need_to_push(int *index)
{
	(*index)--;
	if (*index >= 1)
		return (1);
	return (0);
}

static int	need_to_rrot_push(t_stack *stack_a, int num)
{
	t_stack	*current;
	int		out;

	out = 0;
	if (!stack_a)
		return (0);
	current = stack_a;
	while (current->next && current->data != num)
		current = current->next;
	while (current->next)
	{
		current = current->next;
		out++;
	}
	return (out);
}

int	*pull_from_bottom(t_stack **stack_a, t_stack **stack_b, int num, int *arr)
{
	int	to_bottom;
	int	index;

	index = find_index(arr, num, stack_len(*stack_a));
	while (need_to_push(&index))
		ft_push(stack_a, stack_b, B);
	to_bottom = need_to_rrot_push(*stack_a, num);
	index = to_bottom;
	while (index-- > 0)
	{
		ft_rrotate(stack_a, stack_b, A);
		ft_push(stack_a, stack_b, B);
	}
	ft_swap(stack_a, stack_b, A);
	while (to_bottom--)
	{
		ft_push(stack_a, stack_b, A);
		ft_rrotate(stack_a, stack_b, A);
	}
	while (*stack_b)
		ft_push(stack_a, stack_b, A);
	return (free(arr), compute_index_rank(*stack_a, stack_len(*stack_a)));
}
