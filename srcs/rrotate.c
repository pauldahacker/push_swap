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
rotates return (-1) or (0) to keep track of how many elements we rotate.
The rotate count should decrease by 1 if and only if:
	- the stack exists and is not empty;
	- the stack is segmented
*/

int	rr(t_stack *stack)
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
	return (rr(a));
}

int	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	return (rr(b));
}

/*
Reverse-rotates both stacks but will return the result of performing r(stack1).
*/
int	rrab(t_stack *stack1, t_stack *stack2)
{
	write(1, "rrr\n", 4);
	rr(stack2);
	return (rr(stack1));
}
