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

void	push_swap_3a(int len, int is_segmented, t_stack *a, t_stack *b)
{
	int	n_rotates;

	if (len == 2 && !is_correct(a, len, STACK_A))
		s(a);
	if (is_correct(a, len, STACK_A))
		return ;
	if (is_segmented)
	{
		n_rotates = -1;
		while (a->content[0] != lowest(a, len - ++n_rotates))
			ra(a);
		pb(b, a);
		while (--n_rotates >= 0)
			rra(a);
		try_ss(a, b);
		return (pa(a, b));
	}
	else if (a->content[1] == highest(a, 3)
		|| (a->content[2] != highest(a, 3) && a->content[2] != lowest(a, 3)))
	{
		rra(a);
		push_swap_3a(len, is_segmented, a, b);
		return ;
	}
	try_ss(a, b);
	push_swap_3a(len, is_segmented, a, b);
}

void	push_swap_3b(int len, int is_segmented, t_stack *a, t_stack *b)
{
	int	n_pushes;

	if (len == 2 && !is_correct(b, len, STACK_B))
		sb(b);
	if (is_correct(b, len, STACK_B))
	{
		while (len-- > 0)
			pa(a, b);
		return ;
	}
	else if (is_segmented)
	{
		n_pushes = -1;
		while (b->content[0] > lowest(b, len - ++n_pushes))
			pa(a, b);
		if (n_pushes < 2)
			rb(b);
		while (n_pushes++ < 2)
			pa(a, b);
		if (b->content[0] != lowest(b, len))
			rrb(b);
		try_ss(a, b);
		return (pa(a, b));
	}
	if (b->content[1] == lowest(b, 3)
		|| (b->content[2] != lowest(b, 3) && b->content[2] != highest(b, 3)))
	{
		rrb(b);
		push_swap_3b(len, is_segmented, a, b);
		return ;
	}
	try_ss(a, b);
	push_swap_3b(len, is_segmented, a, b);
}

void	push_swap_5a(t_stack *a, t_stack *b)
{
	int	pivot;
	int	n_pushes;

	n_pushes = 0;
	try_ss(a, b);
	while (a->len > 3 && !is_correct(a, a->len, STACK_A))
	{
		if (a->len == 4)
			pivot = lowest(a, a->len);
		else
			pivot = find_pivot(a, a->len, STACK_A);
		if (a->content[0] > pivot)
			rotate_a(pivot, 0, a);
		else
		{
			pb(b, a);
			++n_pushes;
		}
	}
	push_swap_3a(a->len, 0, a, b);
	while (--n_pushes >= 0)
		pa(a, b);
	try_ss(a, b);
}

void	push_swap_5b(t_stack *a, t_stack *b)
{
	int	pivot;

	try_ss(a, b);
	while (b->len > 3 && !is_correct(b, b->len, STACK_B))
	{
		if (b->len == 4)
			pivot = highest(b, b->len);
		else
			pivot = find_pivot(b, b->len, STACK_B);
		if (b->content[0] < pivot)
			rotate_b(pivot, 0, b);
		else
			pa(a, b);
	}
	try_ss(a, b);
	push_swap_3b(b->len, 0, a, b);
	while (b->len)
		pa(a, b);
	try_ss(a, b);
}
