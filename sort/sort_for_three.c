/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:25:12 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/13 16:20:22 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	get_1_2_3(t_stack *stack_a, int *one, int *two, int *three)
{
	*one = 0;
	*two = 0;
	*three = 0;
	*one = stack_a->data;
	if (stack_a->next)
		*two = stack_a->next->data;
	else
		return ;
	if (stack_a->next->next)
		*three = stack_a->next->next->data;
}

void	sort_for_3(t_stack **stack_a, int one, int two, int three)
{
	if (is_sorted(*stack_a))
		return ;
	if (one > two && two > three)
	{
		ft_swap(stack_a, NULL, A);
		ft_rrotate(stack_a, NULL, A);
	}
	else if (one > three && three > two)
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
