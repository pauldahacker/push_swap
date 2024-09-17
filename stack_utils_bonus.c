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

#include "checker.h"

int	is_number(char *str)
{
	long	num;
	int		sign;

	sign = 1;
	if (!str)
		return (0);
	if (*str == '-' || *str == '+')
	{
		sign -= (*str == '-') * 2;
		++str;
	}
	if (*str && *str >= '0' && *str <= '9')
		num = *(str++) - '0';
	while (*str)
	{
		if (*str >= '0' && *str <= '9' && ((sign == 1 && num < INT_MAX)
				|| (sign == -1 && num < (long)INT_MAX + 1)))
		{
			num = num * 10 + *str - '0';
			++str;
		}
		else
			return (0);
	}
	return (num * sign <= (long)INT_MAX && num * sign >= (long)INT_MIN);
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

int	help_create(char *numbers, t_stack *new_stack)
{
	int		i;
	int		j;
	char	**split;

	split = ft_split(numbers, ' ');
	if (!split)
		return (0);
	i = 0;
	j = -1;
	while (split[i])
	{
		if (!is_number(split[i]))
		{
			while (split[++j])
				free(split[j]);
			free(split);
			return (0);
		}
		new_stack->content[i] = ft_atoi(split[i]);
		++i;
	}
	while (split[++j])
		free(split[j]);
	free(split);
	return (i);
}

t_stack	*create_stack(int len, char *numbers[])
{
	int		i;
	t_stack	*new_stack;

	new_stack = malloc(sizeof(t_stack));
	if (!new_stack)
		return (NULL);
	if (len == 1)
	{
		len = help_create(numbers[0], new_stack);
		if (!len)
			return (destroy_stack(&new_stack));
	}
	else
	{
		i = 0;
		while (numbers && *(numbers + i))
		{
			if (!is_number(numbers[i]))
				return (destroy_stack(&new_stack));
			new_stack->content[i] = ft_atoi(numbers[i]);
			++i;
		}
	}
	new_stack->len = len;
	return (new_stack);
}

void	*destroy_stack(t_stack **stack)
{
	free((*stack)->content);
	*stack = NULL;
	return (NULL);
}
