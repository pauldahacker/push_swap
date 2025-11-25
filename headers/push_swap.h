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

# define A 'A'
# define B 'B'

# define TRUE 1
# define FALSE 0

# define ROTATE_FLAG 1
# define RROTATE_FLAG -1

typedef struct s_stack	t_stack;
typedef struct s_stack
{
	int		*content;
	int		len;
	int		a_or_b;
	int		is_segmented;
	int		n_rotates;
	int		pivot;
	t_stack	*other_stack;
}		t_stack;

// swap.c
void	swap(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *stack1, t_stack *stack2);
void	try_ss(t_stack *stack1, t_stack *stack2);

// push.c
int		push(t_stack *stack1, t_stack *stack2);
int		pa(t_stack *a, t_stack *b);
int		pb(t_stack *b, t_stack *a);

// rotate.c
int		rotate(t_stack *stack);
int		ra(t_stack *a);
int		rb(t_stack *b);
int		rab(t_stack *stack1, t_stack *stack2);
int		try_rab(t_stack *stack1, t_stack *stack2);

// rrotate.c
int		rrotate(t_stack *stack);
int		rra(t_stack *a);
int		rrb(t_stack *b);
int		rrab(t_stack *stack1, t_stack *stack2);
int		try_rrab(t_stack *stack1, t_stack *stack2);

// stack_utils.c
void	*destroy_stack(t_stack **stack);
void	handle_error(t_stack *stack);
int		is_number(char *str);
int		has_repeats(t_stack *stack);
void	help_create(char *numbers, t_stack *new_stack);

// stack.c
t_stack	*init_stack(int len, int a_or_b);
t_stack	*create_stack_a(int len, char *argv[]);
int		lowest(int *stack_content, int len);
int		highest(int *stack_content, int len);
int		is_reverse_correct(t_stack *stack, int len);
int		is_correct(t_stack *stack, int len);
int		fast_solution_check(t_stack *stack, int len);

// small_sort.c
void	push_swap_3a(t_stack *a);
void	push_swap_3b(t_stack *a, t_stack *b);

// mutual_sort_utils.c
void	put_on_top_a(t_stack *a, t_stack *b);
void	put_on_top_b(t_stack *a, t_stack *b);

// mutual_sort.c
int		find_pivot(t_stack *stack, int len);
void	mutual_sort_a(t_stack *a, int len);
void	mutual_sort_b(t_stack *a, int len);

void	print_stack(t_stack *a);

#endif
