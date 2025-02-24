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

int	rotate_a(int pivot, int is_segmented, t_stack *a)
{
	int	from_front;
	int	from_back;

	from_front = 0;
	from_back = 0;
	while (a->content[from_front] > pivot)
		++from_front;
	while (a->content[(a->len - 1) - from_back] > pivot)
		++from_back;
	if (from_front < from_back)
	{
		ra(a);
		if (is_segmented)
			return (1);
	}
	else
	{
		rra(a);
		if (is_segmented && a->content[0] > pivot)
			return (-1);
	}
	return (0);
}

int	rotate_b(int pivot, int is_segmented, t_stack *b)
{
	int	from_front;
	int	from_back;

	from_front = 0;
	from_back = 0;
	while (b->content[from_front] < pivot)
		++from_front;
	while (b->content[(b->len - 1) - from_back] < pivot)
		++from_back;
	if (from_front < from_back)
	{
		rb(b);
		if (is_segmented)
			return (1);
	}
	else
	{
		rrb(b);
		if (is_segmented && b->content[0] < pivot)
			return (-1);
	}
	return (0);
}

void	put_on_top_a(int n_rotates, int pivot, t_stack *a, t_stack *b)
{
	if (n_rotates > 0)
	{
		if (b->content[0] != pivot && n_rotates > 0)
			n_rotates += rrab(a, b);
		while (n_rotates > 0)
			n_rotates += rra(a);
	}
	if (n_rotates < 0)
	{
		while (n_rotates < 0)
			n_rotates += ra(a);
	}
	if (b->content[0] != pivot)
		rrb(b);
}

void	put_on_top_b(int n_rotates, int pivot, t_stack *a, t_stack *b)
{
	if (n_rotates > 0)
	{
		if (a->content[0] != pivot && n_rotates > 0)
			n_rotates += rrab(b, a);
		while (n_rotates > 0)
			n_rotates += rrb(b);
	}
	if (n_rotates < 0)
	{
		while (n_rotates < 0)
		{
			n_rotates += rb(b);
		}
	}
	if (a->content[0] != pivot)
		rra(a);
}
