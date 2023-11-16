/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:19 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/13 14:39:46 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	do_for_chunk(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	*arr;
	int	max;

	arr = compute_chunk_numbers(*stack_a, len);
	if (!arr)
		return ;
	max = arr[len - 1];
	free(arr);
	while (len-- > 0)
	{
		while ((*stack_a)->data > max)
			ft_rotate(stack_a, stack_b, A);
		ft_push(stack_a, stack_b, B);
	}
}

void	push_to_b(t_stack **stack_a, t_stack **stack_b)
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
