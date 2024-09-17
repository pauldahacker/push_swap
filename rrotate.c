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

void	rr(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || !stack->len)
		return ;
	i = stack->len;
	temp = stack->content[i - 1];
	while (--i > 0)
		stack->content[i] = stack->content[i - 1];
	stack->content[0] = temp;
}

void	rra(t_stack *a)
{
	write(1, "rra\n", 4);
	rr(a);
}

void	rrb(t_stack *b)
{
	write(1, "rrb\n", 4);
	rr(b);
}

void	rrab(t_stack *a, t_stack *b)
{
	write(1, "rrr\n", 4);
	rr(a);
	rr(b);
}
