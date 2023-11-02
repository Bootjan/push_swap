/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:13:40 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/02 18:50:29 by bschaafs         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"

# define MAX_INT 2147483647
# define MIN_INT 2147483648
# define A 0
# define B 1
# define AB 2

typedef struct s_stack
{
	int				data;
	struct s_stack	*next;
}	t_stack;

t_stack	*init_stack(int amount, char **data, int *error_flag);
void	free_list(t_stack **stack);
size_t	stack_len(t_stack *stack);
void	ft_swap(t_stack **stack_a, t_stack **stack_b, int mode);
void	ft_push(t_stack **stack_a, t_stack **stack_b, int mode);
void	ft_rotate(t_stack **stack_a, t_stack **stack_b, int mode);
void	ft_rrotate(t_stack **stack_a, t_stack **stack_b, int mode);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
int		no_errors(const char *str);
int		*radix_sort(int *arr, t_stack **stack_a, int len);
int		*compute_index_rank(t_stack *stack, int len);
void	print_arr(int *arr, int len);

#endif