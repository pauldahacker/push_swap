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

void	print_stack(t_stack *a)
{
	int	i;

	i = 0;
	printf("------\n");
	while (i < a->len)
		printf("[ %d ]\n", a->content[i++]);
	printf("------\n");
}

/*
Finds the pivot (p) for either A or B, ranging from position 0 to len.
For A,	p = number in A such that len / 2 numbers are less than or equal to p.
For B,	p = number in B such that len / 2 numbers are less than p.
*/
int	find_pivot(t_stack *stack, int len, int a_or_b)
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
			if (a_or_b == STACK_A && stack->content[j] <= stack->content[i])
				++count;
			if (a_or_b == STACK_B && stack->content[j] >= stack->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (stack->content[i]);
}

static void	split_a(t_stack *a, t_stack *b, int len)
{
	int	n_pushes;

    n_pushes = 0;
    while (n_pushes < len / 2)
    {
        if (n_pushes == len / 2 - 1)
        {
            if (a->content[0] > a->pivot && a->content[1] <= a->pivot)
                sa(a);
        }
        if (a->content[0] > a->pivot)
        {
            if (b->content[0] == a->pivot)
                a->n_rotates += rab(a, b);
            else
                a->n_rotates += ra(a);
        }
        else
        {
            if (b->content[0] == a->pivot && n_pushes != len / 2 - 1)
                rb(b);
            n_pushes += pb(b, a);
        }
    }
    if (b->content[1] == a->pivot)
        sb(b);
    put_on_top_a(a, b);
}

static void	split_b(t_stack *a, t_stack *b, int len)
{
    int	n_pushes;

    n_pushes = 0;
    while (n_pushes < len / 2)
    {
        if (n_pushes == len / 2 - 1)
        {
            if (b->content[0] < b->pivot && b->content[1] >= b->pivot)
                sb(b);
        }
        if (b->content[0] < b->pivot)
        {
            if (a->content[0] == b->pivot)
                b->n_rotates += rab(b, a);
            else
                b->n_rotates += rb(b);
        }
        else
        {
            if (a->content[0] == b->pivot && n_pushes != len / 2 - 1)
                ra(a);
            n_pushes += pa(a, b);
        }
    }
    if (a->content[1] == b->pivot)
        sa(a);
    put_on_top_b(a, b);
}

void    mutual_sort_a(t_stack *a, t_stack *b, int len)
{
	a->is_segmented = (a->len != len);
	a->pivot = find_pivot(a, len, STACK_A);
    if (a->len <= 5)
        return (push_swap_5a(a, b));
    if (is_correct(a, a->len, STACK_A) && is_correct(b, b->len, STACK_B))
    {
        while (b->len)
            pa(a, b);
        return ;
    }
    if (is_correct(a, len, STACK_A))
        return ;
    split_a(a, b, len);
    mutual_sort_a(a, b, len - len / 2);
    mutual_sort_b(b, a, len / 2);
}

void    mutual_sort_b(t_stack *b, t_stack *a, int len)
{
	b->is_segmented = (b->len != len);
	b->pivot = find_pivot(b, len, STACK_B);
    if (b->len <= 5)
        return (push_swap_5b(a, b));
    if (is_correct(a, a->len, STACK_A) && is_correct(b, b->len, STACK_B))
    {
        while (b->len)
            pa(a, b);
        return ;
    }
    if (len <= 2 || is_correct(b, len, STACK_B))
    {
        try_ss(a, b);
        while (--len >= 0)
            pa(a, b);
        return ;
    }
    split_b(a, b, len);
    mutual_sort_a(a, b, len / 2);
    mutual_sort_b(b, a, len - len / 2);
}
