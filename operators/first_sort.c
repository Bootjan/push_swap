/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 13:56:14 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/03 16:11:44 by bschaafs         ###   ########.fr       */
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

int	half_index(int len, int num, int index)
{
	if (ft_abs(num - index) == 1 && index == 1)
		return (SWAP_A);
	if (index == len - 1 && num == 0)
		return (RROTATE);
	if (index == 0 && num == len - 1)
		return (ROTATE);
	if (ft_abs(num - index) <= 2 && index > len >> 1)
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
	while (i > 1)
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

	len = stack_len(*stack_a);
	i = 0;
	while (i < len)
	{
		index = find_index(arr, i, len);
		if (index == i)
		{
			i++;
			continue ;
		}
		if (half_index(len, i, index) == SWAP_A)
		{
			ft_swap(stack_a, stack_b, A);
			arr = ft_swap_list(arr, 0, 1);
		}
		if (half_index(len, i, index) == RROTATE)
		{
			ft_rrotate(stack_a, stack_b, A);
			arr = rrotate_list(arr, len);
		}
		if (half_index(len, i, index) == ROTATE)
		{
			ft_rotate(stack_a, stack_b, A);
			arr = rotate_list(arr, len);
		}
		if (half_index(len, i, index) == SORT_BOTTOM)
			// sort
		if (half_index(len, i, index) == SORT_TOP)
			// sort
		i++;
	}
}
