/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_sort_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:10:19 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 19:18:11 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate_a(t_stack *a)
{
	int	from_front;
	int	from_back;

	from_front = 0;
	from_back = 0;
	while (a->content[from_front] > a->pivot)
		++from_front;
	while (a->content[(a->len - 1) - from_back] > a->pivot)
		++from_back;
	if (from_front <= from_back || a->is_segmented)
		return (ra(a));
	else
		return (rra(a));
	return (0);
}

int	rotate_b(t_stack *b)
{
	int	from_front;
	int	from_back;

	from_front = 0;
	from_back = 0;
	while (b->content[from_front] < b->pivot)
		++from_front;
	while (b->content[(b->len - 1) - from_back] < b->pivot)
		++from_back;
	if (from_front <= from_back || b->is_segmented)
		return (rb(b));
	else
		return (rrb(b));
	return (0);
}

void	put_on_top_a(t_stack *a, t_stack *b)
{
	if (a->n_rotates > 0)
	{
		if (b->content[0] != a->pivot && a->n_rotates > 0)
			a->n_rotates += rrab(a, b);
		while (a->n_rotates > 0)
			a->n_rotates += rra(a);
	}
	if (a->n_rotates < 0)
	{
		while (a->n_rotates < 0)
			a->n_rotates += ra(a);
	}
	if (b->content[0] != a->pivot)
		rrb(b);
}

void	put_on_top_b(t_stack *a, t_stack *b)
{
	if (b->n_rotates > 0)
	{
		if (a->content[0] != b->pivot && b->n_rotates > 0)
			b->n_rotates += rrab(b, a);
		while (b->n_rotates > 0)
			b->n_rotates += rrb(b);
	}
	if (b->n_rotates < 0)
	{
		while (b->n_rotates < 0)
			b->n_rotates += rb(b);
	}
	if (a->content[0] != b->pivot)
		rra(a);
}
