/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:07:42 by pde-masc          #+#    #+#             */
/*   Updated: 2023/12/17 14:16:32 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*init_stack(int len, int a_or_b)
{
	t_stack	*init;

	init = malloc(sizeof(t_stack));
	if (!init)
		return (NULL);
	init->content = (int *)malloc((len) * sizeof(int));
	if (!init->content)
	{
		free(init);
		return (NULL);
	}
	if (a_or_b == A)
		init->len = len;
	else
		init->len = 0;
	init->a_or_b = a_or_b;
	init->is_segmented = FALSE;
	init->n_rotates = 0;
	init->pivot = 0;
	return (init);
}

t_stack	*create_stack_a(int len, char *argv[])
{
	int		i;
	t_stack	*new_stack;

	i = 0;
	new_stack = init_stack(len, A);
	if (len == 1)
		help_create(argv[0], new_stack);
	else
	{
		while (i < len)
		{
			if (!is_number(argv[i]))
				handle_error(new_stack);
			new_stack->content[i] = ft_atoi(argv[i]);
			++i;
		}
	}
	if (has_repeats(new_stack))
		handle_error(new_stack);
	return (new_stack);
}

int	lowest(int *stack_content, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_content[0];
	while (++i < len)
	{
		if (stack_content[i] < tmp)
			tmp = stack_content[i];
	}
	return (tmp);
}

int	highest(int *stack_content, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack_content[0];
	while (++i < len)
	{
		if (stack_content[i] > tmp)
			tmp = stack_content[i];
	}
	return (tmp);
}

int	is_balanced(t_stack *a, t_stack *b)
{
	int	lowest_a;
	int	highest_b;

	if (a->len == 0 || b->len == 0)
		return (1);
	lowest_a = lowest(a->content, a->len);
	highest_b = highest(b->content, b->len);
	return (lowest_a > highest_b);
}

int	is_correct(t_stack *stack, int len)
{
	int	i;
	int	lowest_pos;

	lowest_pos = 0;
	while (stack->content[lowest_pos] != lowest(stack->content, len))
		++lowest_pos;
	if (stack->is_segmented && lowest_pos != 0)
		return (0);
	i = 0;
	while (i < lowest_pos)
	{
		if (stack->content[i] != highest(stack->content, i + 1))
			return (0);
		++i;
	}
	while (i < len)
	{
		if ((stack->content[i]) != lowest(stack->content + i, len - i))
			return (0);
		++i;
	}
	if (lowest_pos > 0 && stack->content[len - 1] > stack->content[0])
		return (0);
	return (is_balanced(stack, stack->other_stack));
}

int	is_reverse_correct(t_stack *stack, int len)
{
	int	i;
	int	highest_pos;

	highest_pos = 0;
	while (stack->content[highest_pos] != highest(stack->content, len))
		++highest_pos;
	if (stack->is_segmented && highest_pos != 0)
		return (0);
	i = 0;
	while (i < highest_pos)
	{
		if (stack->content[i] != lowest(stack->content, i + 1))
			return (0);
		++i;
	}
	while (i < len)
	{
		if (stack->content[i] != highest(stack->content + i, len - i))
			return (0);
		++i;
	}
	if (highest_pos > 0 && stack->content[len - 1] < stack->content[0])
		return (0);
	return (is_balanced(stack->other_stack, stack));
}

int	fast_solution_check(t_stack *stack, int len)
{
	int	top_elem;
	int	top_elem_pos;

	if (stack->len <= 3)
		return (1);
	if (stack->a_or_b == A && is_correct(stack, len))
		top_elem = lowest(stack->content, len);
	else if (stack->a_or_b == B && is_reverse_correct(stack, len))
		top_elem = highest(stack->content, len);
	else
		return (0);
	top_elem_pos = 0;
	while (stack->content[top_elem_pos] != top_elem)
		++top_elem_pos;
	while (stack->content[0] != top_elem)
	{
		if (top_elem_pos > len / 2)
			try_rrab(stack, stack->other_stack);
		else
			try_rab(stack, stack->other_stack);
	}
	return (1);
}
