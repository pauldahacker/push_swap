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

# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# define MAX_ARGS INT_MAX

typedef struct s_stack
{
	int	content[MAX_ARGS];
	int	len;
}		t_stack;

// swap.c
void	s(t_stack *stack);
void	sa(t_stack *a);
void	sb(t_stack *b);
void	ss(t_stack *a, t_stack *b);

// push.c
void	p(t_stack *stack1, t_stack *stack2);
void	pa(t_stack *a, t_stack *b);
void	pb(t_stack *b, t_stack *a);

// rotate.c
void	r(t_stack *stack);
void	ra(t_stack *a);
void	rb(t_stack *b);
void	rab(t_stack *a, t_stack *b);

// rrotate.c
void	rr(t_stack *stack);
void	rra(t_stack *a);
void	rrb(t_stack *b);
void	rrab(t_stack *a, t_stack *b);

// stack_utils.c
int		is_number(char *str);
int		has_repeats(t_stack *stack);
int		help_create(char *numbers, t_stack *new_stack);
t_stack	*create_stack(int len, char *numbers[]);
void	*destroy_stack(t_stack **stack);

// stack.c
int		lowest(t_stack *a);
int		highest(t_stack *a);
int		find_pos(int elem, t_stack *a);
int		is_correct(t_stack *stack, int len);
int		is_reverse_sorted(t_stack *stack, int len);

// small_sort.c
void	push_swap_3a(t_stack *a);
void	push_swap_3b(t_stack *b);
void	push_swap_5(t_stack *a);

// mutual_sort_utils.c
int		find_pivot_a(t_stack *a, int len);
int		find_pivot_b(t_stack *b, int len);
void	put_on_top(int elem_a, t_stack *a, int elem_b, t_stack *b);

// mutual_sort.c
void	split_a(t_stack *a, t_stack *b, int len);
void	split_b(t_stack *b, t_stack *a, int len);
void	mutual_sort_a(t_stack *a, t_stack *b, int len);
void	mutual_sort_b(t_stack *b, t_stack *a, int len);

// push_swap.c
void	push_swap(t_stack *a);

// ft.c
int		ft_atoi(const char *str);
char	**ft_split(const char *str, char c);

#endif
