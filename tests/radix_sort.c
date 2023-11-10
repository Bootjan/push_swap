/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:09:45 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/02 16:58:31 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/push_swap.h"

int	get_max(int *arr, int len)
{
	int	i;
	int	max;

	max = arr[0];
	i = 1;
	while (i < len)
	{
		if (arr[i] > max)
			max = arr[i];
		i++;
	}
	return (max);
}

int	*count_exp(int *arr, int len, int exp)
{
	int	i;
	int	*count;

	if (!arr)
		return (NULL);
	count = ft_calloc(10, sizeof(int));
	if (!count)
		return (NULL);
	i = 0;
	ft_bzero(count, len * sizeof(int));
	while (i < len)
		count[(arr[i++] / exp) % 10]++;
	i = 0;
	while (i++ < 9)
		count[i] += count[i - 1];
	i = 10;
	while (i-- > 1)
		count[i] = count[i - 1];
	count[0] = 0;
	return (count);
}

int	*do_sort(int *arr, int len, int exp, t_stack **stack_a)
{
	int		i;
	int		*output;
	int		*count;
	t_stack	*stack_b;

	i = 0;
	stack_b = NULL;
	output = ft_calloc(len, sizeof(int));
	if (!output)
		return (NULL);
	count = count_exp(arr, len, exp);
	if (!count)
		return (free(output), NULL);
	while (i < len)
	{
		output[count[(arr[i] / exp) % 10]] = arr[i]; // should do operations here
		count[(arr[i++] / exp) % 10]++;
	}
	ft_memmove(arr, output, len * sizeof(int));
	return (free(output), free(count), arr);
}

int	*radix_sort(int *arr, t_stack **stack_a, int len)
{
	t_stack	*stack_b;
	int		max;
	int		exp;

	stack_b = NULL;
	if (!arr || !*stack_a)
		return (NULL);
	max = get_max(arr, len);
	exp = 1;
	while (exp < max)
	{
		arr = do_sort(arr, len, exp);
		exp *= 10;
	}
	return (arr);
}
