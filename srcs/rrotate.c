/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:03:19 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 12:02:49 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
reverse-rotates return (-1) or (0) to keep track of how many elements we rotate
The rotate count should decrease by 1 if and only if:
	- the stack exists and is not empty;
	- the stack is segmented
*/

int	rrotate(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || !stack->len)
		return (0);
	i = stack->len;
	temp = stack->content[i - 1];
	while (--i > 0)
		stack->content[i] = stack->content[i - 1];
	stack->content[0] = temp;
	if (stack->is_segmented)
		return (-1);
	return (0);
}

int	rra(t_stack *a)
{
	write(1, "rra\n", 4);
	return (rrotate(a));
}

int	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	return (rrotate(b));
}

/*
Reverse-rotates both stacks but will return the result of performing r(stack1).
*/
int	rrab(t_stack *stack1, t_stack *stack2)
{
	write(1, "rrr\n", 4);
	rrotate(stack2);
	return (rrotate(stack1));
}

/*
Checks if "rrab" should be executed, and executes it if it's a clever move.
If not, it will execute rra on stack1 if it is A and rrb if it is B.
Returns the result of rrab, rra, or rrb.
*/
int	try_rrab(t_stack *stack1, t_stack *stack2)
{
	int	first;
	int	last;

	if (stack1->a_or_b == A && stack2->len < 2)
		return (rra(stack1));
	if (stack1->a_or_b == B && stack2->len < 2)
		return (rrb(stack1));
	first = stack2->content[0];
	last = stack2->content[stack2->len - 1];
	if (stack1->a_or_b == A && stack2->a_or_b == B)
	{
		if (first != stack1->pivot && first < last)
			return (rrab(stack1, stack2));
		else
			return (rra(stack1));
	}
	else if (stack1->a_or_b == B && stack2->a_or_b == A)
	{
		if (first != stack1->pivot && first > last)
			return (rrab(stack1, stack2));
		else
			return (rrb(stack1));
	}
	return (0);
}