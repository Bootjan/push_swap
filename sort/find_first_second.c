/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_first_second.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 14:52:19 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 19:43:55 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_first(t_stack *stack_a, int max)
{
	t_stack	*current;
	int		index;

	index = 0;
	current = stack_a;
	if (!current)
		return (-1);
	while (current)
	{
		if (current->data <= max)
			return (index);
		index++;
		current = current->next;
	}
	return (-1);
}

int	find_last(t_stack *stack_a, int max)
{
	t_stack	*current;
	int		i;
	int		index;

	index = -1;
	current = stack_a;
	if (!current)
		return (-1);
	i = 0;
	while (current)
	{
		if (current->data <= max)
			index = i;
		i++;
		current = current->next;
	}
	return (index);
}

int	compute_curr_chunks_len(int len)
{
	int	div_20;

	if (len <= 20)
		return (len);
	div_20 = len / 20 + 1;
	return (len / div_20);
}

int	find_smallest(int *arr, t_stack *stack, int len_arr)
{
	t_stack	*current;
	int		smallest;

	current = stack;
	while (current)
	{
		if (!ft_in_list(arr, len_arr, current->data))
		{
			smallest = current->data;
			break ;
		}
		current = current->next;
	}
	while (current)
	{
		if (current->data < smallest && !ft_in_list(arr, len_arr, current->data))
			smallest = current->data;
		current = current->next;
	}
	return (smallest);
}

int	*compute_chunk_numbers(t_stack *stack, int len)
{
	int	i;
	int	*arr;

	arr = ft_calloc(len, sizeof(int));
	if (!arr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		arr[i] = find_smallest(arr, stack, i);
		i++;
	}
	return (arr);
}

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

int	distance_to_border(int len, int index_first, int index_bottom)
{

	int	distance_bottom;

	distance_bottom = len - index_bottom - 1;
	if (distance_bottom < index_first)
		return (BOTTOM);
	return (TOP);
}

int	pull_from_top_bottom(t_stack *stack_a, int max, int *distance)
{
	int	index_first;
	int	index_bottom;
	int	len;

	index_first = find_first(stack_a, max);
	index_bottom = find_last(stack_a, max);
	len = stack_len(stack_a);
	if (distance_to_border(len, index_first, index_bottom) == TOP)
		return (*distance = index_first, TOP);
	return (*distance = len - index_bottom - 1, BOTTOM);
}

void	pull_from_top(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ < index)
		ft_rotate(stack_a, stack_b, A);
	ft_push(stack_a, stack_b, B);
}

void	pull_from_bottom(t_stack **stack_a, t_stack **stack_b, int index)
{
	int	i;

	i = 0;
	while (i++ <= index)
		ft_rrotate(stack_a, stack_b, A);
	ft_push(stack_a, stack_b, B);
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
