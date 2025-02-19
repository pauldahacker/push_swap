/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:27:23 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 19:30:17 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <fcntl.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NEWLINE '\n'
# define BYTE_START 1

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
int		is_correct(t_stack *stack, int len);
int		is_reverse_sorted(t_stack *stack, int len);

// ft.c
int		ft_atoi(const char *str);
char	**ft_split(const char *str, char c);

// get_next_line.c
char	*get_next_line(int fd);
char	*destroy(char **s);

// get_next_line_utils.c
size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strchr(const char *str, int c);
char	*tochr(char *str, int c);
char	*ft_strdup(const char *s);

// checker_utils.c
void	apply_r(t_stack *a, t_stack *b, char *line);
void	apply_p(t_stack *a, t_stack *b, char *line);
void	apply_s(t_stack *a, t_stack *b, char *line);
int		is_move_valid(char *move);

#endif
