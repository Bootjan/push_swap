/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:12:55 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/16 12:39:07 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

static void	sort_big_stack(t_stack **stack_a, t_stack **stack_b)
{
	push_to_b(stack_a, stack_b);
	push_to_a(stack_a, stack_b);
}

static void	sort_stack(t_stack **stack_a, t_stack **stack_b, int len)
{
	int	one;
	int	two;
	int	three;

	if (is_sorted(*stack_a))
		return ;
	get_1_2_3(*stack_a, &one, &two, &three);
	if (len == 2)
		ft_rrotate(stack_a, stack_b, A);
	else if (len == 3)
		sort_for_3(stack_a, one, two, three);
	else if (len == 4)
		sort_for_4(stack_a, stack_b);
	else if (len == 5)
		sort_for_5(stack_a, stack_b);
	else
		sort_big_stack(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		error_flag;

	if (argc == 1)
		return (ft_putendl_fd("At least one argument has to be given.", 2), 1);
	error_flag = 0;
	stack_a = init_stack(argc, argv, &error_flag);
	if (error_flag != 0)
		return (ft_putendl_fd("Error", 2), 1);
	stack_b = NULL;
	sort_stack(&stack_a, &stack_b, stack_len(stack_a));
	free_list(&stack_a);
	free_list(&stack_b);
	return (0);
}
