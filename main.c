/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 20:06:30 by bschaafs         ###   ########.fr       */
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
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	ft_push(&stack_a, &stack_b, 1);
	ft_swap(&stack_a, &stack_b, 1);
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	ft_push(&stack_a, &stack_b, 1);
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
	ft_swap(&stack_a, &stack_b, 0);
	print_list(stack_a, 'a');
	print_list(stack_b, 'b');
}
