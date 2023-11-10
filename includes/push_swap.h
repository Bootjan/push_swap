/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bschaafs <bschaafs@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 18:13:40 by bschaafs          #+#    #+#             */
/*   Updated: 2023/11/10 13:09:37 by bschaafs         ###   ########.fr       */
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
# define TOP 0
# define BOTTOM 1

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
int		is_sorted(t_stack *stack);
void	sort_for_3_4_5(t_stack **stack_a, t_stack **stack_b, int len);
void	get_1_2_3(t_stack *stack_a, int *one, int *two, int *three);
void	sort_for_4(t_stack **stack_a, t_stack **stack_b);
void	sort_for_5(t_stack **stack_a, t_stack **stack_b);
void	sort_for_3(t_stack **stack_a, int one, int two, int three);
void	push_next_element(t_stack **stack_a, t_stack **stack_b);
int		*compute_chunk_numbers(t_stack *stack, int len);
int		pull_from_top_bottom(t_stack *stack_a, int max, int *distance);
int		compute_curr_chunks_len(int len);
void	keep_b_utd(t_stack **stack_a, t_stack **stack_b, int new_el);

#endif