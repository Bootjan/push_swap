/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:25:12 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:30:24 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_for_3(t_stack **stack_a, int one, int two, int three)
{
	if (one > two && two > three)
	{
		ft_swap(stack_a, NULL, A);
		ft_rrotate(stack_a, NULL, A);
	}
	else if (one > three && three > one)
		ft_rotate(stack_a, NULL, A);
	else if (two > one && one > three)
		ft_rrotate(stack_a, NULL, A);
	else if (two > three && three > one)
	{
		ft_rrotate(stack_a, NULL, A);
		ft_swap(stack_a, NULL, A);
	}
	else if (three > one && one > two)
		ft_swap(stack_a, NULL, A);
}

void	get_1_2_3(t_stack *stack_a, int *one, int *two, int *three)
{
	*one = stack_a->data;
	*two = stack_a->next->data;
	*three = stack_a->next->next->data;
}

void	sort_for_3_4_5(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	one;
	int	two;
	int	three;

	if (is_sorted(*stack_a))
		return ;
	get_1_2_3(*stack_a, &one, &two, &three);
	if (len == 3)
		sort_for_3(stack_a, one, two, three);
	else if (len == 4)
		sort_for_4(stack_a, stack_b);
	else if (len == 5)
		sort_for_5(stack_a, stack_b);
	else
	{
		push_next_element(stack_a, stack_b);
		push_to_a(stack_a, stack_b);
	}
}
