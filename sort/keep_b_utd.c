/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_b_utd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:11:34 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 15:00:24 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	find_first_three(t_stack *stack, int *one, int *two, int *three)
{
	*one = stack->data;
	*two = stack->next->data;
	*three = stack->next->next->data;
}

static void	sort_b_for_3(t_stack **stack_a, t_stack **stack_b, int new_el)
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

static void	sort_b_for_4(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	one;
	int	two;
	int	three;

	find_first_three(*stack_b, &one, &two, &three);
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

static void	sort_b_for_5(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	one;
	int	two;
	int	three;
	int	four;

	find_first_three(*stack_b, &one, &two, &three);
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

static void	sort_b(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	
}

void	keep_b_utd(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	len;

	len = stack_len(*stack_b);
	if (len <= 2)
		ft_push(stack_a, stack_b, B);
	if (len == 1 && new_el < (*stack_b)->next->data)
		ft_swap(stack_a, stack_b, B);
	else if (len == 2)
		sort_b_for_3(stack_a, stack_b, new_el);
	else if (len == 3)
		sort_b_for_4(stack_a, stack_b, new_el);
	else if (len == 4)
		sort_b_for_5(stack_a, stack_b, new_el);
	else if (len > 3)
		ft_push(stack_a, stack_b, B);
		// sort_b(stack_a, stack_b, new_el);
}
