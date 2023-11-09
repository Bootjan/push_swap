/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_five.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 13:23:35 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 13:37:49 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insert_from_b(t_stack **stack_a, t_stack **stack_b, int index)
{
	if (index == 2)
		ft_swap(stack_a, stack_b, A);
	else if (index == 3)
		ft_rrotate(stack_a, stack_b, A);
	ft_push(stack_a, stack_b, A);
	if (index == 1)
		ft_swap(stack_a, stack_b, A);
	else if (index == 2)
	{
		ft_swap(stack_a, stack_b, A);
		ft_rrotate(stack_a, stack_b, A);
	}
	else if (index == 3)
	{
		ft_rotate(stack_a, stack_b, A);
		ft_rotate(stack_a, stack_b, A);
	}
	else if (index == 4)
		ft_rotate(stack_a, stack_b, A);
}

static int	compute_new_index(t_stack *stack_a, t_stack *stack_b)
{
	int	new_int;
	int	one;
	int	two;
	int	three;
	int	four;

	new_int = stack_b->data;
	get_1_2_3(stack_a, &one, &two, &three);
	four = stack_a->next->next->next->data;
	if (new_int < one)
		return (0);
	if (new_int < two)
		return (1);
	if (new_int < three)
		return (2);
	if (new_int < four)
		return (3);
	return (4);
}

void	sort_for_5(t_stack **stack_a, t_stack **stack_b)
{
	int	index;

	ft_push(stack_a, stack_b, B);
	sort_for_4(stack_a, stack_b);
	index = compute_new_index(*stack_a, *stack_b);
	insert_from_b(stack_a, stack_b, index);
}
