/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:56:14 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/06 14:47:08 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	find_index(int *arr, int num, int len)
{
	int	index;

	index = 0;
	while (index < len)
	{
		if (arr[index] == num)
			return (index);
		index++;
	}
	return (index);
}

int	compute_action(int len, int num, int index)
{
	if (index == num)
		return (DO_NOTHING);
	if (num == 0 && index == 1)
		return (SWAP_A);
	if (index == len - 1 && num == 0)
		return (RROTATE);
	if (index == 0 && num == len - 1)
		return (ROTATE);
	if (index > len >> 1 && num <= len >> 1)
		return (SORT_BOTTOM);
	if (ft_abs(num - index) <= 2 && index <= len >> 1)
		return (SORT_TOP);
	return (-1);
}

int	*rotate_list(int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len - 1)
	{
		arr = ft_swap_list(arr, i, i + 1);
		i++;
	}
	return (arr);
}

int	*rrotate_list(int *arr, int len)
{
	int	i;

	i = len - 1;
	while (i > 0)
	{
		arr = ft_swap_list(arr, i, i - 1);
		i--;
	}
	return (arr);
}

void	sort_bottom(int *arr, t_stack **stack_a, t_stack **stack_b, int index)
{
	int	len;
	int	num;
	int	i;

	len = stack_len(*stack_a);
	num = arr[index];
	i = 0;
	while (index + i++ < len - 2)
	{
		ft_rrotate(stack_a, stack_b, A);
		ft_push(stack_a, stack_b, B);
	}
	ft_rrotate(stack_a, stack_b, A);
}

void	sort_stack(int *arr, t_stack **stack_a, t_stack **stack_b)
{
	int	len;
	int	i;
	int	index;
	int	action;

	len = stack_len(*stack_a);
	i = 0;
	while (i < len && !is_sorted(*stack_a))
	{
		index = find_index(arr, i, len);
		action = compute_action(len, i, index);
		if (action == SWAP_A)
		{
			ft_swap(stack_a, stack_b, A);
			arr = ft_swap_list(arr, 0, 1);
		}
		if (action == RROTATE)
		{
			ft_rrotate(stack_a, stack_b, A);
			arr = rrotate_list(arr, len);
		}
		if (action == ROTATE)
		{
			ft_rotate(stack_a, stack_b, A);
			arr = rotate_list(arr, len);
		}
		if (action == SORT_BOTTOM)
			arr = pull_from_bottom(stack_a, stack_b, 1, arr);
		// if (half_index(len, i, index) == SORT_TOP)
			// sort
		i++;
	}
	free(arr);
}
