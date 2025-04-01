/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:02:51 by pde-masc          #+#    #+#             */
/*   Updated: 2024/01/11 16:37:05 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
rotates return (1) or (0) to keep track of how many elements we rotate
The rotate count should increase by 1 if and only if:
	- the stack exists and is not empty;
	- the stack is segmented
*/

int	rotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || !stack->len)
		return (0);
	temp = stack->content[0];
	i = 0;
	while (++i < stack->len)
		stack->content[i - 1] = stack->content[i];
	stack->content[i - 1] = temp;
	if (stack->is_segmented)
		return (1);
	return (0);
}

int	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	return (rotate(a));
}

int	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	return (rotate(b));
}

/*
Rotates both stacks but will return the result of performing r(stack1).
*/
int	rab(t_stack *stack1, t_stack *stack2)
{
	write(1, "rr\n", 3);
	rotate(stack2);
	return (rotate(stack1));
}

/*
Checks if "rab" should be executed, and executes it if it's a clever move.
If not, it will execute ra on stack1 if it is A and rb if it is B.
Returns the result of rab, ra, or rb.
*/
int	try_rab(t_stack *stack1, t_stack *stack2)
{
	int	first;
	int	last;

	if (stack1->a_or_b == A && stack2->len < 2)
		return (ra(stack1));
	if (stack1->a_or_b == B && stack2->len < 2)
		return (rb(stack1));
	first = stack2->content[0];
	last = stack2->content[stack2->len - 1];
	if (stack1->a_or_b == A && stack2->a_or_b == B)
	{
		if (last != stack1->pivot && (first == stack1->pivot || first < last))
			return (rab(stack1, stack2));
		else
			return (ra(stack1));
	}
	else if (stack1->a_or_b == B && stack2->a_or_b == A)
	{
		if (last != stack1->pivot && (first == stack1->pivot || first > last))
			return (rab(stack1, stack2));
		else
			return (rb(stack1));
	}
	return (0);
}
