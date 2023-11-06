/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:13:40 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/06 14:49:15 by bschaafs         ###   ########.fr       */
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

# define DO_NOTHING -1
# define SWAP_A 0
# define RROTATE 1
# define ROTATE 2
# define SORT_BOTTOM 3
# define SORT_TOP 4

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
int		ft_get_2_min(int *arr, int len);
void	sort_stack(int *arr, t_stack **stack_a, t_stack **stack_b);
int		*pull_from_bottom(t_stack **stack_a, t_stack **stack_b, int num, int *arr);
int		find_index(int *arr, int num, int len);
int		is_sorted(t_stack *stack);

#endif