/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:48:08 by bschaafs          #+#    #+#             */
/*   Updated: 2023/10/27 18:57:16 by bschaafs         ###   ########.fr       */
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

static void	list_push_back(t_stack **stack, char *data, int *error_flag)
{
	int		num;
	t_stack	*element;
	t_stack	*current;

	num = ft_atoi(data);
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

	i = 1;
	stack = NULL;
	while (i < amount && *error_flag == 0)
		list_push_back(&stack, data[i++], error_flag);
	if (*error_flag != 0)
		free_list(&stack);
	return (stack);
}
