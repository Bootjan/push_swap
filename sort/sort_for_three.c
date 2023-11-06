/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_for_three.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:25:12 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/06 11:26:11 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	*solve_for_3(int *arr, t_stack **stack)
{
	int	max;
	int	sort_index;
	int	min;

	max = ft_get_max(arr, 3);
	if (arr[0] == max)
	{
		ft_rotate(stack, NULL, A);
		arr = ft_swap_list(arr, 0, 1);
		arr = ft_swap_list(arr, 1, 2);
	}
	sort_index = is_sorted_arr(arr, 3);
	if (sort_index == 2)
		return (arr);
	min = ft_get_min(arr, 3);
	if (arr[0] == min)
	{
		ft_swap(stack, NULL, A);
		ft_rotate(stack, NULL, A);
		return (ft_swap_list(arr, 1, 2));
	}
	if (arr[1] == max)
	{
		ft_rrotate(stack, NULL, A);
		arr = ft_swap_list(arr, 1, 2);
		return (ft_swap_list(arr, 1, 0));
	}
	ft_swap(stack, NULL, A);
	return (ft_swap_list(arr, 0, 1));
}

// int	*solve_for_4(int *arr, t_stack **stack_a, t_stack **stack_b)
// {
// 	int	min;
// 	int	max;
// 	int	sort_index;
// 	int	second_lowest;

// 	sort_index = is_sorted_arr(arr, 4);
// 	if (sort_index == 4)
// 		return (arr);
// 	min = ft_get_min(arr, 4);
// 	if (min == arr[0])
// 	{
// 		ft_push(stack_a, stack_b, A);
// 		solve_for_3(&(arr[1]), stack_a);
// 		return (ft_push(stack_a, stack_b, B), arr);
// 	}
// 	max = ft_get_max(arr, 4);
// 	second_lowest = ft_get_2_min(arr, 4);
// 	if (arr[0] == max && is_sorted_arr(&(arr[1]), 3) == 3)
// 	{
// 		ft_rotate(stack_a, stack_b, A);
// 		return (ft_rotate_arr(arr, 4));
// 	}
// 	if (arr[0] == max && arr[3] == second_lowest)
// 	{
		
// 	}
// }
