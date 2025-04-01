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

void	put_on_top_a(t_stack *a, t_stack *b)
{
	if (a->n_rotates > 0)
	{
		if (b->content[b->len - 1] == a->pivot)
			a->n_rotates += rrab(a, b);
		while (a->n_rotates > 0 && !fast_solution_check(a, a->len))
			a->n_rotates += rra(a);
	}
	if (b->len > 1 && b->content[b->len - 1] == a->pivot)
		rrb(b);
}

void	put_on_top_b(t_stack *a, t_stack *b)
{
	if (b->n_rotates > 0)
	{
		if (a->content[a->len - 1] == b->pivot)
			b->n_rotates += rrab(b, a);
		while (b->n_rotates > 0 && !fast_solution_check(b, b->len))
			b->n_rotates += rrb(b);
	}
	if (a->len > 1 && a->content[a->len - 1] == b->pivot)
		rra(a);
}
