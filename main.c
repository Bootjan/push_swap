/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bootjan <bootjan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 23:16:53 by bootjan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

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
		free_list(&stack_a);
		return (0);
	}
	print_both(stack_a, stack_b);
	ft_push(&stack_a, &stack_b, 1);
	ft_rotate(&stack_a, NULL, 0);
	print_both(stack_a, stack_b);
	ft_push(&stack_a, &stack_b, 1);
	ft_rotate(&stack_a, &stack_b, 2);
	print_both(stack_a, stack_b);
}
