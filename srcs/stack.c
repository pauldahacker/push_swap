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
	init->n_pushes = 0;
	init->pivot = 0;
	return (init);
}

t_stack	*create_stack_A(int len, char *argv[])
{
	int		i;
	t_stack	*new_stack;

	new_stack = init_stack(len, A);
	if (len == 1)
		help_create(argv[0], new_stack);
	else
	{
		i = 0;
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

int	lowest(t_stack *stack, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->content[0];
	while (++i < len)
	{
		if (stack->content[i] < tmp)
			tmp = stack->content[i];
	}
	return (tmp);
}

int	highest(t_stack *stack, int len)
{
	int	tmp;
	int	i;

	i = 0;
	tmp = stack->content[0];
	while (++i < len)
	{
		if (stack->content[i] > tmp)
			tmp = stack->content[i];
	}
	return (tmp);
}

int	is_correct(t_stack *stack, int len)
{
	int	i;
	int	j;
	int	tmp;

	if (len < 2)
		return (1);
	i = 0;
	while (i < len)
	{
		tmp = stack->content[i];
		j = ++i;
		while (j < stack->len)
		{
			if (stack->a_or_b == A && stack->content[j] < tmp)
				return (0);
			if (stack->a_or_b == B && stack->content[j] > tmp)
				return (0);
			++j;
		}
	}
	return (1);
}
