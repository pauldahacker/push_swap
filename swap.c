/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:58:52 by pde-masc          #+#    #+#             */
/*   Updated: 2024/01/11 16:38:21 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s(t_stack *stack)
{
	int	tmp;

	if (!stack || stack->len <= 1)
		return ;
	tmp = stack->content[0];
	stack->content[0] = stack->content[1];
	stack->content[1] = tmp;
}

void	sa(t_stack *a)
{
	write(1, "sa\n", 3);
	s(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	s(b);
}

void	ss(t_stack *a, t_stack *b)
{
	write(1, "ss\n", 3);
	s(a);
	s(b);
}
