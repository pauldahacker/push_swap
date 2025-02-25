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

int	r(t_stack *stack)
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
	return (r(a));
}

int	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	return (r(b));
}

/*
Rotates both stacks but will return the result of performing r(stack1).
*/
int	rab(t_stack *stack1, t_stack *stack2)
{
	write(1, "rr\n", 3);
	r(stack2);
	return (r(stack1));
}
