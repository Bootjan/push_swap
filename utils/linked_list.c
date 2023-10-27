/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:55:00 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 19:41:46 by bschaafs         ###   ########.fr       */
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

void	print_list(t_stack *stack, char stack_name)
{
	t_stack	*current;

	ft_printf("%c:\n", stack_name);
	current = stack;
	if (!current)
		return ;
	while (current)
	{
		ft_printf("%i\n", current->data);
		current = current->next;
	}
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
