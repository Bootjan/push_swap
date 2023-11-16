/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 13:03:11 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/16 12:19:42 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	return_result(size_t num, int pos_neg)
{
	if (num > MAX_INT && pos_neg == 1)
		return (1);
	if (num > MIN_INT && pos_neg == -1)
		return (1);
	return (0);
}

static int	bigger_than_int(const char *str)
{
	size_t	i;
	size_t	num;
	size_t	max_iter;
	int		sign;

	i = 0;
	sign = 1;
	num = 0;
	max_iter = 11;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		i++;
		sign = -1;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] && str[i + 1] && str[i] == '0')
		i++;
	while (ft_isdigit(str[i]) && max_iter-- > 0)
		num = num * 10 + str[i++] - '0';
	if (max_iter == 11)
		return (1);
	return (return_result(num, sign));
}

int	no_errors(const char *str)
{
	if (!all_digits(str))
		return (0);
	if (bigger_than_int(str))
		return (0);
	return (1);
}
