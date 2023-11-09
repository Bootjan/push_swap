/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:51:41 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/09 15:54:40 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_in_list(int *arr, int len, int target)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (arr[i] == target)
			return (1);
		i++;
	}
	return (0);
}
