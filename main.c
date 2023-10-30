/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/30 13:45:15 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	is_sorted(t_stack *stack)
{
	int		last;
	t_stack	*current;
	
	current = stack;
	if (!current)
		return (0);
	last = current->data;
	current = current->next;
	while (current)
	{
		if (last > current->data)
			return (1);
		last = current->data;
		current = current->next;
	}
	return (0);
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
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error_flag;

	if (argc == 1)
	{
		ft_printf("Not enough arguments.\n");
		return (0);
	}
	error_flag = 0;
	stack_a = init_stack(argc, argv, &error_flag);
	stack_b = NULL;
	if (error_flag != 0)
	{
		ft_printf("Error\n");
		return (0);
	}
	sort_stack(&stack_a, &stack_b);
	print_stacks(stack_a, stack_b);
	free_list(&stack_a);
	// ft_push(&stack_a, &stack_b, 1);
	// ft_rotate(&stack_a, NULL, 0);
	// print_both(stack_a, stack_b);
	// ft_push(&stack_a, &stack_b, 1);
	// ft_rotate(&stack_a, &stack_b, 2);
	// print_both(stack_a, stack_b);
}
