/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutual_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 14:09:38 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 19:44:22 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	split_a(t_stack *a, t_stack *b, int len)
{
	int	startlen;
	int	first;
	int	median;

	startlen = a->len;
	median = find_pivot_a(a, len);
	first = -1;
	while (a->content[++first] <= median)
		;
	first = a->content[first];
	while (startlen - a->len <= len / 2 - !(len % 2))
	{
		if (b->content[0] == median && a->content[0] > median)
			rab(a, b);
		if (b->content[0] == median && b->len > 1)
			rb(b);
		else if (a->content[0] <= median)
			pb(b, a);
		else
			ra(a);
	}
	put_on_top(first, a, median, b);
}

void	split_b(t_stack *b, t_stack *a, int len)
{
	int	startlen;
	int	first;
	int	median;

	startlen = b->len;
	median = find_pivot_b(b, len);
	first = -1;
	while (b->content[++first] >= median)
		;
	first = b->content[first];
	while (startlen - b->len <= len / 2 - !(len % 2))
	{
		if (a->content[0] == median && b->content[0] < median)
			rab(a, b);
		if (a->content[0] == median && a->len > 1)
			ra(a);
		else if (b->content[0] >= median)
			pa(a, b);
		else
			rb(b);
	}
	put_on_top(median, a, first, b);
}

void	mutual_sort_a(t_stack *a, t_stack *b, int len)
{
	if (a->len <= 5)
		push_swap_5(a);
	if (is_correct(a, a->len) && is_reverse_sorted(b, b->len))
	{
		while (b->len)
			pa(a, b);
		return ;
	}
	if (len <= 2 || is_correct(a, len))
	{
		if (len == 2 && a->content[0] > a->content[1])
			sa(a);
		return ;
	}
	split_a(a, b, len);
	mutual_sort_a(a, b, len / 2);
	mutual_sort_b(b, a, len / 2 + len % 2);
}

void	mutual_sort_b(t_stack *b, t_stack *a, int len)
{
	if (b->len <= 3)
		push_swap_3b(b);
	if (is_correct(a, a->len) && is_reverse_sorted(b, b->len))
	{
		while (b->len)
			pa(a, b);
		return ;
	}
	if (len <= 2 || is_reverse_sorted(b, len))
	{
		if (len == 2 && b->content[0] < b->content[1])
			sb(b);
		while (--len >= 0)
			pa(a, b);
		return ;
	}
	split_b(b, a, len);
	mutual_sort_a(a, b, len / 2 + len % 2);
	mutual_sort_b(b, a, len / 2);
}
