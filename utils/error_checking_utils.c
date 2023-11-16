/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_checking_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:19:12 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/16 12:19:51 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_min_plus(char c)
{
	return (c == '-' || c == '+');
}

static int	is_space(char c)
{
	return (c == ' ' || (c >= '\t' && c <= '\r'));
}

int	all_digits(const char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && (is_min_plus(str[i]) || is_space(str[i])))
		i++;
	return (ft_isdigit(str[i]));
}
