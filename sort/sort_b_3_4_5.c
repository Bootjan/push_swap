/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_3_4_5.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 16:09:42 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:10:08 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_b_for_3(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	one;
	int	two;

	one = (*stack_b)->next->data;
	two = (*stack_b)->next->next->data;
	if (new_el < one && new_el > two)
		ft_swap(stack_a, stack_b, B);
	else if (new_el < one && new_el < two)
		ft_rotate(stack_a, stack_b, B);
}

void	sort_b_for_4(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	one;
	int	two;
	int	three;

	get_1_2_3(*stack_b, &one, &two, &three);
	if (new_el < two && new_el > three)
		ft_rrotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, B);
	if (new_el < three)
		ft_rotate(stack_a, stack_b, B);
	else if (new_el < two)
	{
		ft_rotate(stack_a, stack_b, B);
		ft_rotate(stack_a, stack_b, B);
	}
	else if (new_el < one)
		ft_swap(stack_a, stack_b, B);
}

void	sort_b_for_5(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	one;
	int	two;
	int	three;
	int	four;

	get_1_2_3(*stack_b, &one, &two, &three);
	four = (*stack_b)->next->next->next->data;
	if (new_el < two && new_el > three)
		ft_rotate(stack_a, stack_b, B);
	else if (new_el < three && new_el > four)
		ft_rrotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, B);
	if (new_el < four)
		ft_rotate(stack_a, stack_b, B);
	else if (new_el < three)
	{
		ft_rotate(stack_a, stack_b, B);
		ft_rotate(stack_a, stack_b, B);
	}
	else if (new_el < two)
	{
		ft_swap(stack_a, stack_b, B);
		ft_rrotate(stack_a, stack_b, B);
	}
	else if (new_el < one)
		ft_swap(stack_a, stack_b, B);
}
