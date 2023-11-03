/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/03 14:22:31 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		last;
	t_stack	*current;
	int		index;
	
	current = stack;
	if (!current)
		return (0);
	last = current->data;
	current = current->next;
	index = 0;
	while (current)
	{
		if (last > current->data)
			return (index);
		last = current->data;
		current = current->next;
		index++;
	}
	return (index);
}

int	is_sorted_arr(int *arr, int len)
{
	int	i;

	if (!arr)
		return (-1);
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
			return (i);
		i++;
	}
	return (i);
}

// int	*solve_for_3(int *arr, t_stack **stack)
// {
// 	int	max;
// 	int	sort_index;
// 	int	min;

// 	max = ft_get_max(arr, 3);
// 	if (arr[0] == max)
// 	{
// 		ft_rotate(stack, NULL, A);
// 		arr = ft_swap_list(arr, 0, 1);
// 		arr = ft_swap_list(arr, 1, 2);
// 	}
// 	sort_index = is_sorted_arr(arr, 3);
// 	if (sort_index == 2)
// 		return (arr);
// 	min = ft_get_min(arr, 3);
// 	if (arr[0] == min)
// 	{
// 		ft_swap(stack, NULL, A);
// 		ft_rotate(stack, NULL, A);
// 		return (ft_swap_list(arr, 1, 2));
// 	}
// 	if (arr[1] == max)
// 	{
// 		ft_rrotate(stack, NULL, A);
// 		arr = ft_swap_list(arr, 1, 2);
// 		return (ft_swap_list(arr, 1, 0));
// 	}
// 	ft_swap(stack, NULL, A);
// 	return (ft_swap_list(arr, 0, 1));
// }

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

// void	do_operations(int *rank_arr, int *arr_b, t_stack **stack_a, t_stack **stack_b)
// {
// 	int	len;

// 	len = stack_len(*stack_a);
// 	while (is_sorted(*stack_a) != len || *stack_b)
// 	{
// 		if (len == 3)
// 			rank_arr = solve_for_3(rank_arr, stack_a);
// 		if (len == 4)
// 			rank_arr = solve_for_4(rank_arr, stack_a, stack_b);
// 	}
// }

// void	sort_stack(t_stack **stack_a)
// {
// 	int	*rank_arr;
// 	int	len;

// 	len = stack_len(*stack_a);
// 	if (is_sorted(*stack_a) || len	== 1)
// 		return ;
// 	if (len == 2)
// 	{
// 		if (!is_sorted(*stack_a))
// 			ft_rotate(stack_a, NULL, 0);
// 		return ;
// 	}
// 	rank_arr = compute_index_rank(*stack_a, len);
// 	if (!rank_arr)
// 		return ;
// 	print_arr(rank_arr, stack_len(*stack_a));
// 	// if (len == 3)
// 	// {
// 	// 	rank_arr = solve_for_3(rank_arr, stack_a);
// 	// 	return (free(rank_arr));
// 	// }
// 	// else
// 	// 	do_operations(rank_arr, stack_a, len);
// 	free(rank_arr);
// }

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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error_flag;
	int		*rank_arr;

	if (argc == 1)
		return (ft_printf("Not enough arguments.\n"), 1);
	error_flag = 0;
	stack_a = init_stack(argc, argv, &error_flag);
	if (error_flag != 0)
		return (ft_printf("Error\n"), 1);
	print_stacks(stack_a, NULL);
	stack_b = NULL;
	rank_arr = compute_index_rank(stack_a, stack_len(stack_a));
	sort_stack(rank_arr, &stack_a, &stack_b);
	print_stacks(stack_a, NULL);
	if (is_sorted(stack_a))
		ft_printf("Sorted stack!\n");
	free_list(&stack_a);
	return (0);
}
