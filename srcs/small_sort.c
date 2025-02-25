/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:08:38 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 16:38:14 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap_3a(int len, t_stack *a, t_stack *b)
{
	if (len == 2 && !is_correct(a, len, STACK_A))
		sa(a);
	if (is_correct(a, len, STACK_A))
		return ;
	else if (a->content[1] == highest(a, 3)
		|| (a->content[2] != highest(a, 3) && a->content[2] != lowest(a, 3)))
	{
		rra(a);
		push_swap_3a(len, a, b);
		return ;
	}
	try_ss(a, b);
	push_swap_3a(len, a, b);
}

void	push_swap_3b(int len, t_stack *a, t_stack *b)
{
	if (len == 2 && !is_correct(b, len, STACK_B))
		sb(b);
	if (is_correct(b, len, STACK_B))
	{
		while (len-- > 0)
			pa(a, b);
		return ;
	}
	if (b->content[1] == lowest(b, 3)
		|| (b->content[2] != lowest(b, 3) && b->content[2] != highest(b, 3)))
	{
		rrb(b);
		push_swap_3b(len, a, b);
		return ;
	}
	try_ss(a, b);
	push_swap_3b(len, a, b);
}

void	push_swap_5a(t_stack *a, t_stack *b)
{
	int	n_pushes;

	n_pushes = 0;
	while (a->len > 3 && !is_correct(a, a->len, STACK_A))
	{
		if (a->len == 4)
			a->pivot = lowest(a, a->len);
		if (a->content[0] > a->pivot)
			rotate_a(a);
		else
		{
			pb(b, a);
			++n_pushes;
		}
	}
	push_swap_3a(a->len, a, b);
	while (--n_pushes >= 0)
		pa(a, b);
	try_ss(a, b);
}

void	push_swap_5b(t_stack *a, t_stack *b)
{
	while (b->len > 3 && !is_correct(b, b->len, STACK_B))
	{
		if (b->len == 4)
			b->pivot = highest(b, b->len);
		if (b->content[0] < b->pivot)
			rotate_b(b);
		else
			pa(a, b);
	}
	try_ss(a, b);
	push_swap_3b(b->len, a, b);
	while (b->len)
		pa(a, b);
	try_ss(a, b);
}
