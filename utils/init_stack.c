/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:48:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/30 13:30:43 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*create_element(int num)
{
	t_stack	*element;

	element = malloc(sizeof(t_stack));
	if (!element)
		return (NULL);
	element->data = num;
	element->next = NULL;
	return (element);
}

static int	ll_contains_num(t_stack *stack, int num)
{
	t_stack	*current;

	current = stack;
	if (!current)
		return (0);
	while (current)
	{
		if (current->data == num)
			return (1);
		current = current->next;
	}
	return (0);
}

static void	list_push_back(t_stack **stack, char *data, int *error_flag)
{
	int		num;
	t_stack	*element;
	t_stack	*current;

	num = ft_atoi(data);
	if (ll_contains_num(*stack, num))
	{
		*error_flag = 1;
		return ;
	}
	element = create_element(num);
	if (!element)
	{
		*error_flag = 1;
		return ;
	}
	current = *stack;
	if (!current)
	{
		*stack = element;
		return ;
	}
	while (current->next)
		current = current->next;
	current->next = element;
}

t_stack	*init_stack(int amount, char **data, int *error_flag)
{
	int		i;
	t_stack	*stack;

	i = amount;
	stack = NULL;
	while (i-- > 1 && *error_flag == 0)
	{
		if (!no_errors(data[i]))
			*error_flag = 1;
		list_push_back(&stack, data[i], error_flag);
	}
	if (*error_flag != 0)
		free_list(&stack);
	return (stack);
}
