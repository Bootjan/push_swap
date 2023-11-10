/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keep_b_utd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 12:11:34 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:13:52 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	insert_from_top(t_stack **stack_a, t_stack **stack_b, int new_index)
{
	int	i;

	i = 0;
	while (i++ < new_index)
		ft_rotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, B);
}

static void	insert_from_bottom(t_stack **stack_a, \
t_stack **stack_b, int new_index)
{
	int	i;

	i = 0;
	while (i++ < new_index)
		ft_rrotate(stack_a, stack_b, B);
	ft_push(stack_a, stack_b, B);
}

static void	sort_b(t_stack **stack_a, t_stack **stack_b, int new_el)
{
	int	new_index;
	int	half_len;

	new_index = find_new_index(*stack_b, new_el);
	half_len = stack_len(*stack_b) >> 1;
	if (new_index <= half_len)
		insert_from_top(stack_a, stack_b, new_index);
	else
		insert_from_bottom(stack_a, stack_b, new_index);
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
		sort_b(stack_a, stack_b, new_el);
}
