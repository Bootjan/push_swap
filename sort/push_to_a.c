/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   return_to_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:14:39 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/13 14:11:59 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push_to_a_top(t_stack **stack_a, t_stack **stack_b, \
int index, int max)
{
	int	i;
	int	index_second_max;

	i = 0;
	while (i++ < index - 1)
		ft_rotate(stack_a, stack_b, B);
	index_second_max = find_second_max(*stack_b, max);
	if (index_second_max == 0)
		ft_swap(stack_a, stack_b, B);
	else if (i != 1 || (*stack_b)->data != max)
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
	int	max;

	max = 0;
	while (*stack_b)
	{
		index_max = find_index_max(*stack_b, &max);
		len = stack_len(*stack_b);
		if (index_max <= len >> 1)
			push_to_a_top(stack_a, stack_b, index_max, max);
		else
			push_to_a_bottom(stack_a, stack_b, len - index_max);
	}
}
