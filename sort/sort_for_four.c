/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_four.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:22:40 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 13:24:05 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insert_from_b(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (index == 0)
		ft_push(stack_a, stack_b, A);
	else if (index == 1)
	{
		ft_push(stack_a, stack_b, A);
		ft_swap(stack_a, stack_b, A);
	}
	else if (index == 2)
	{
		ft_rrotate(stack_a, stack_b, A);
		ft_push(stack_a, stack_b, A);
		ft_rotate(stack_a, stack_b, A);
		ft_rotate(stack_a, stack_b, A);
	}
	else if (index == 3)
	{
		ft_push(stack_a, stack_b, A);
		ft_rotate(stack_a, stack_b, A);
	}
}

static int	compute_new_index(int b_var, int one, int two, int three)
{
	if (b_var < one)
		return (0);
	if (b_var < two)
		return (1);
	if (b_var < three)
		return (2);
	return (3);
}

void	sort_for_4(t_stack **stack_a, t_stack **stack_b)
{
	int	one;
	int	two;
	int	three;
	int	index;

	ft_push(stack_a, stack_b, B);
	get_1_2_3(*stack_a, &one, &two, &three);
	sort_for_3(stack_a, one, two, three);
	get_1_2_3(*stack_a, &one, &two, &three);
	index = compute_new_index((*stack_b)->data, one, two, three);
	insert_from_b(stack_a, stack_b, index);
}
