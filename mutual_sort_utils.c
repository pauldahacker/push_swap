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

int	find_pivot_a(t_stack *a, int len)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < len)
	{
		count = 0;
		j = -1;
		while (++j < len)
		{
			if (a->content[j] > a->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (a->content[i]);
}

int	find_pivot_b(t_stack *b, int len)
{
	int	i;
	int	j;
	int	count;

	i = -1;
	while (++i < len)
	{
		count = 0;
		j = -1;
		while (++j < len)
		{
			if (b->content[j] < b->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (b->content[i]);
}

void	put_on_top(int elem_a, t_stack *a, int elem_b, t_stack *b)
{
	int	pos_a;
	int	pos_b;

	pos_a = find_pos(elem_a, a);
	pos_b = find_pos(elem_b, b);
	while (a->len > 2 * pos_a && b->len > 2 * pos_b
		&& a->content[0] != elem_a && b->content[0] != elem_b)
		rab(a, b);
	while (a->len <= 2 * pos_a && b->len <= 2 * pos_b
		&& a->content[0] != elem_a && b->content[0] != elem_b)
		rrab(a, b);
	while (a->len > 2 * pos_a && a->content[0] != elem_a)
		ra(a);
	while (a->len <= 2 * pos_a && a->content[0] != elem_a)
		rra(a);
	while (b->len > 2 * pos_b && b->content[0] != elem_b)
		rb(b);
	while (b->len <= 2 * pos_b && b->content[0] != elem_b)
		rrb(b);
}
