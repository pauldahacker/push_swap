/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:04:49 by pde-masc          #+#    #+#             */
/*   Updated: 2024/01/11 16:58:19 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*destroy_stack(t_stack **stack)
{
	if ((*stack)->content)
		free((*stack)->content);
	free(*stack);
	*stack = NULL;
	return (NULL);
}

void	handle_error(t_stack *stack)
{
	if (stack)
		destroy_stack(&stack);
	write(STDERR_FILENO, "Error\n", 6);
	exit(EXIT_FAILURE);
}

int	is_number(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	num = 0;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		++str;
	}
	if (!*str || *str < '0' || *str > '9')
		return (0);
	while (*str && *str == '0')
		++str;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		num = num * 10 + (*str - '0');
		++str;
	}
	return (!*str && num * sign >= INT_MIN && num * sign <= INT_MAX);
}

int	has_repeats(t_stack *stack)
{
	int	tmp;
	int	i;
	int	j;

	i = 0;
	while (i < stack->len)
	{
		tmp = stack->content[i];
		j = i;
		while (++j < stack->len)
		{
			if (stack->content[j] == tmp)
				return (1);
		}
		++i;
	}
	return (0);
}

void	help_create(char *numbers, t_stack *new_stack)
{
	int		i;
	int		j;
	char	**split;

	split = ft_split(numbers, ' ');
	if (!split || !split[0])
		handle_error(new_stack);
	i = 0;
	j = -1;
	while (split[i])
	{
		if (!is_number(split[i]))
		{
			while (split[++j])
				free(split[j]);
			free(split);
			handle_error(new_stack);
		}
		new_stack->content[i] = ft_atoi(split[i]);
		++i;
	}
	while (split[++j])
		free(split[j]);
	free(split);
	new_stack->len = i;
}
