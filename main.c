/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/02 18:08:06 by bschaafs         ###   ########.fr       */
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

void	do_operations(int *rank_arr, t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	int		*arr_b;

	stack_b = NULL;
	arr_b = ft_calloc(len, sizeof(int));
	if (!arr_b)
		return ;
	while (!is_sorted(*stack_a) || stack_b)
	{
		if (top())
	}
}

void	sort_stack(t_stack **stack_a)
{
	int	*rank_arr;
	int	len;

	len = stack_len(*stack_a);
	if (is_sorted(*stack_a) || len	== 1)
		return ;
	if (len == 2)
	{
		if (!is_sorted(*stack_a))
			ft_rotate(stack_a, NULL, 0);
		return ;
	}
	rank_arr = compute_index_rank(*stack_a, len);
	if (!rank_arr)
		return ;
	do_operations(rank_arr, stack_a, len);
	free(rank_arr);
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
	int		error_flag;
	int		*rank_arr;

	if (argc == 1)
		return (ft_printf("Not enough arguments.\n"), 1);
	error_flag = 0;
	stack_a = init_stack(argc, argv, &error_flag);
	if (error_flag != 0)
		return (ft_printf("Error\n"), 1);
	print_stacks(stack_a, NULL);
	sort_stack(&stack_a);
	free_list(&stack_a);
	return (0);
}
