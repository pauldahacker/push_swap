/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:01:52 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/02 09:09:07 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
pushes return (1) or (0) to keep track of how many elements we push
*/
int	push(t_stack *stack1, t_stack *stack2)
{
	int	len;
	int	i;

	if (!stack1 || !stack2 || !stack2->len)
		return (0);
	len = stack1->len + 1;
	while (--len > 0)
		stack1->content[len] = stack1->content[len - 1];
	stack1->content[0] = stack2->content[0];
	i = 0;
	while (i < stack2->len)
	{
		stack2->content[i] = stack2->content[i + 1];
		++i;
	}
	--stack2->len;
	++stack1->len;
	return (1);
}

int	pa(t_stack *a, t_stack *b)
{
	write(1, "pa\n", 3);
	return (push(a, b));
}

int	pb(t_stack *b, t_stack *a)
{
	write(1, "pb\n", 3);
	return (push(b, a));
}
