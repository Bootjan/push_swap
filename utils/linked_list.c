/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:55:00 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 19:50:26 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

size_t	stack_len(t_stack *stack)
{
	size_t	len;
	t_stack	*current;

	len = 0;
	current = stack;
	if (!current)
		return (0);
	while (current)
	{
		current = current->next;
		len++;
	}
	return (len);
}

static void	print_stacks_helper(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a && stack_b)
	{
		ft_printf("%i  %i\n", stack_a->data, stack_b->data);
		print_stacks_helper(stack_a->next, stack_b->next);
	}
	else if (stack_a)
	{
		ft_printf("%i\n", stack_a->data);
		print_stacks_helper(stack_a->next, NULL);
	}
	else if (stack_b)
	{
		ft_printf("   %i\n", stack_b->data);
		print_stacks_helper(NULL, stack_b->next);
	}
}

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	print_stacks_helper(stack_a, stack_b);
	ft_printf("_  _\na  b\n\n");
}

void	free_list(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	current = *stack;
	if (!current)
		return ;
	while (current)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
