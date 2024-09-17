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

void	r(t_stack *stack)
{
	int	temp;
	int	i;

	if (!stack || !stack->len)
		return ;
	temp = stack->content[0];
	i = 0;
	while (++i < stack->len)
		stack->content[i - 1] = stack->content[i];
	stack->content[i - 1] = temp;
}

void	ra(t_stack *a)
{
	write(1, "ra\n", 3);
	r(a);
}

void	rb(t_stack *b)
{
	write(1, "rb\n", 3);
	r(b);
}

void	rab(t_stack *a, t_stack *b)
{
	write(1, "rr\n", 3);
	r(a);
	r(b);
}
