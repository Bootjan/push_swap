/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:19 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 16:41:50 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_arr(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		ft_printf("%i: %i\n", i, arr[i]);
		i++;
	}
}

void	pull_from_top(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		ft_rotate(stack_a, stack_b, A);
	keep_b_utd(stack_a, stack_b, (*stack_a)->data);
}

void	pull_from_bottom(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ <= index)
		ft_rrotate(stack_a, stack_b, A);
	keep_b_utd(stack_a, stack_b, (*stack_a)->data);
}

void	do_for_chunk(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	*arr;
	int	max;
	int	distance;
	int	i;

	arr = compute_chunk_numbers(*stack_a, len);
	if (!arr)
		return ;
	max = arr[len - 1];
	distance = 0;
	i = 0;
	while (i++ < len)
	{
		if (pull_from_top_bottom(*stack_a, max, &distance) == TOP)
			pull_from_top(stack_a, stack_b, distance);
		else
			pull_from_bottom(stack_a, stack_b, distance);
	}
	free(arr);
}

void	push_next_element(t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	chunks_len;

	while (*stack_a)
	{
		len = stack_len(*stack_a);
		chunks_len = compute_curr_chunks_len(len);
		do_for_chunk(stack_a, stack_b, chunks_len);
	}
}
