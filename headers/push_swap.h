/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 12:24:00 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 17:46:37 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>
# include "../libft/libft.h"

# define STACK_A 'A'
# define STACK_B 'B'

# define TRUE 1
# define FALSE 0

typedef struct s_stack
{
	int	*content;
	int	len;
	int	is_segmented;
	int	n_rotates;
}		t_stack;

// swap.c
void	s(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);
void	try_ss(t_stack *a, t_stack *b);

// push.c
void	p(t_stack *stack1, t_stack *stack2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

// rotate.c
int		r(t_stack *stack);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rab(t_stack *stack1, t_stack *stack2);

// rrotate.c
int		rr(t_stack *stack);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrab(t_stack *stack1, t_stack *stack2);

// stack_utils.c
void	*destroy_stack(t_stack **stack);
void	handle_error(t_stack *stack);
int		is_number(char *str);
int		has_repeats(t_stack *stack);
void	help_create(char *numbers, t_stack *new_stack);

// stack.c
t_stack	*init_stack(size_t size, int len);
t_stack	*create_stack(int len, char *argv[]);
int		lowest(t_stack *stack, int len);
int		highest(t_stack *stack, int len);
int		is_correct(t_stack *stack, int len, int a_or_b);

// small_sort.c
void	push_swap_3a(int len, int is_segmented, t_stack *a, t_stack *b);
void	push_swap_3b(int len, int is_segmented, t_stack *a, t_stack *b);
void	push_swap_5a(t_stack *a, t_stack *b);
void	push_swap_5b(t_stack *a, t_stack *b);

// mutual_sort_utils.c
int		rotate_a(int pivot, int is_segmented, t_stack *a);
int		rotate_b(int pivot, int is_segmented, t_stack *b);
void	put_on_top_a(int n_rotates, int pivot, t_stack *a, t_stack *b);
void	put_on_top_b(int n_rotates, int pivot, t_stack *a, t_stack *b);

// mutual_sort.c
int		find_pivot(t_stack *stack, int len, int a_or_b);
void	mutual_sort_a(t_stack *a, t_stack *b, int len);
void	mutual_sort_b(t_stack *a, t_stack *b, int len);

void	print_stack(t_stack *a);

#endif
