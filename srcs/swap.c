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

void	swap(t_stack *stack)
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
	swap(a);
}

void	sb(t_stack *b)
{
	write(1, "sb\n", 3);
	swap(b);
}

void	ss(t_stack *stack1, t_stack *stack2)
{
	write(1, "ss\n", 3);
	swap(stack1);
	swap(stack2);
}

/*
Checks if "ss" should be executed, and executes it if it's a clever move.
If not, it will execute sa on stack1 if it is A and sb if it is B.
*/
void	try_ss(t_stack *stack1, t_stack *stack2)
{
	if (stack1->a_or_b == A && stack2->a_or_b == B)
	{
		if (stack2->len >= 2 && stack2->content[0] < stack2->content[1])
			ss(stack1, stack2);
		else
			sa(stack1);
	}
	else if (stack1->a_or_b == B && stack2->a_or_b == A)
	{
		if (stack2->len >= 2 && stack2->content[0] > stack2->content[1])
			ss(stack1, stack2);
		else
			sb(stack1);
	}
	return ;
}