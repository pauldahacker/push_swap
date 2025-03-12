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

void	push_swap_3a(t_stack *a)
{
	if (a->len == 3 && a->content[1] == highest(a, 3))
		rra(a);
	if (a->len == 3 && a->content[0] == highest(a, 3))
		ra(a);
	if (!is_correct(a, 3))
		sa(a);
}

void	push_swap_3b(t_stack *a, t_stack *b)
{
	if (b->len == 3 && b->content[1] == lowest(b, 3))
		rrb(b);
	if (b->len == 3 && b->content[0] == lowest(b, 3))
		rb(b);
	if (!is_correct(b, 3))
		sb(b);
	while (b->len)
		pa(a, b);
	return ;
}

void	push_swap_5a(t_stack *a, t_stack *b)
{
	int	n_pushes;

	n_pushes = 0;
	while (a->len > 3 && !is_correct(a, a->len))
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
	push_swap_3a(a);
	while (--n_pushes >= 0)
		pa(a, b);
	try_ss(a, b);
}

void	push_swap_5b(t_stack *a, t_stack *b)
{
	while (b->len > 3 && !is_correct(b, b->len))
	{
		if (b->len == 4)
			b->pivot = highest(b, b->len);
		if (b->content[0] < b->pivot)
			rotate_b(b);
		else
			pa(a, b);
	}
	push_swap_3b(a, b);
	try_ss(a, b);
}
