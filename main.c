/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/06 14:36:27 by bschaafs         ###   ########.fr       */
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
			return (0);
		last = current->data;
		current = current->next;
		index++;
	}
	return (1);
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
