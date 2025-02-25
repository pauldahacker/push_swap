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

void	ss(t_stack *stack1, t_stack *stack2)
{
	write(1, "ss\n", 3);
	s(stack1);
	s(stack2);
}

/*
Checks if "ss" should be executed, and executes it if it's a clever move.
If it shouldn't, it will check the same for sa(a) and sb(b).
If swapping shouldn't be done, it does nothing.
*/
void	try_ss(t_stack *stack1, t_stack *stack2)
{
	if (stack1->len >= 2 && stack1->content[0] > stack1->content[1]
		&& stack2->len >= 2 && stack2->content[0] < stack2->content[1])
		ss(stack1, stack2);
	else if (stack1->len >= 2 && stack1->content[0] > stack1->content[1])
		sa(stack1);
	else if (stack2->len >= 2 && stack2->content[0] < stack2->content[1])
		sb(stack2);
	return ;
}