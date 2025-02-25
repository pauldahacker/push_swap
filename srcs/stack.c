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

t_stack	*init_stack(size_t size, int len)
{
	t_stack	*init;

	init = malloc(sizeof(t_stack));
	if (!init)
		return (NULL);
	init->content = (int *)malloc((size) * sizeof(int));
	if (!init->content)
	{
		free(init);
		return (NULL);
	}
	init->len = len;
	init->is_segmented = FALSE;
	init->n_rotates = 0;
	init->pivot = 0;
	return (init);
}

t_stack	*create_stack(int len, char *argv[])
{
	int		i;
	t_stack	*new_stack;

	new_stack = init_stack(len, len);
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

int	is_correct(t_stack *stack, int len, int a_or_b)
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
			if (a_or_b == STACK_A && stack->content[j] < tmp)
				return (0);
			if (a_or_b == STACK_B && stack->content[j] > tmp)
				return (0);
			++j;
		}
	}
	return (1);
}
