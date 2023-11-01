/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/01 14:26:49 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		last;
	t_stack	*current;
	
	current = stack;
	if (!current)
		return (1);
	last = current->data;
	current = current->next;
	while (current)
	{
		if (last > current->data)
			return (0);
		last = current->data;
		current = current->next;
	}
	return (1);
}

void	sort_stack(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(*stack_a) || stack_len(*stack_a)	== 1)
		return ;
	if (stack_len(*stack_a) == 2)
	{
		if (!is_sorted(*stack_a))
			ft_rotate(stack_a, stack_b, 0);
		return ;
	}
	// *stack_a = quicksort(*stack_a, stack_len(*stack_a));
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
	stack_b = NULL;
	if (error_flag != 0)
		return (ft_printf("Error\n"), 1);
	print_stacks(stack_a, stack_b);
	rank_arr = compute_index_rank(stack_a);
	print_arr(rank_arr, stack_len(stack_a));

	// sort_stack(&stack_a, &stack_b);
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
