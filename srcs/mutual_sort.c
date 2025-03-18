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
int	find_pivot(t_stack *stack, int len)
{
	int	i;
	int	j;
	int	count;

    if (stack->len == 4 && stack->a_or_b == A)
        return (lowest(stack, 4));
    if (stack->len == 4 && stack->a_or_b == B)
        return (highest(stack, 4));
	i = -1;
	while (++i < len)
	{
		count = 0;
		j = -1;
		while (++j < len)
		{
			if (stack->a_or_b == A && stack->content[j] <= stack->content[i])
				++count;
			if (stack->a_or_b == B && stack->content[j] >= stack->content[i])
				++count;
		}
		if (count == len / 2)
			break ;
	}
	return (stack->content[i]);
}

void	try_swapping(t_stack *stack1, t_stack *stack2, int pushes_left)
{
	int	i;
	int	pushable_count;

	i = 0;
	pushable_count = 0;
    if (stack1->len < 2)
        return ;
    s(stack1);
    if (is_correct(stack1, stack1->len))
    {
        s(stack1);
        try_ss(stack1, stack2);
        return ;
    }
    s(stack1);
	while (++i <= pushes_left)
	{
		if (stack1->a_or_b == A && stack1->content[i] <= stack1->pivot)
			pushable_count++;
		else if (stack1->a_or_b == B && stack1->content[i] >= stack1->pivot)
			pushable_count++;
	}

	// If a significant number of upcoming elements are pushable, we swap
	if (pushable_count == pushes_left)
		try_ss(stack1, stack2);
}

static int	split_a(t_stack *a, t_stack *b, int len)
{
	int	n_pushes;

    n_pushes = 0;
    while (n_pushes < len / 2 && a->len > 3)
    {
        try_swapping(a, b, len / 2 - n_pushes);
        if (a->content[0] > a->pivot)
        {
            // if (a->content[1] <= a->pivot && a->content[a->len - 1] < a->content[1])
            //     rra(a);
            if (b->len > 1 && b->content[b->len - 1] != a->pivot)
            {
                if (b->content[0] == a->pivot || b->content[b->len - 1] > b->content[0])
                    a->n_rotates += rab(a, b);
                else
                    a->n_rotates += ra(a);
            }
            else
                a->n_rotates += ra(a);
        }
        else
        {
            if (a->content[a->len - 1] < a->content[0])
                rra(a);
            if (is_correct(a, a->len) && a->content[0] > highest(b, b->len))
                break ;
            if (b->content[0] == a->pivot && n_pushes != len / 2 - 1)
                rb(b);
            n_pushes += pb(b, a);
        }
    }
    if (b->content[1] == a->pivot)
        try_ss(b, a);
    put_on_top_a(a, b);
    return (n_pushes);
}

static int	split_b(t_stack *a, t_stack *b, int len)
{
    int	n_pushes;

    n_pushes = 0;
    while (n_pushes < len / 2 && b->len > 3)
    {
        try_swapping(b, a, len / 2 - n_pushes);
        if (b->content[0] < b->pivot)
        {
            // if (b->content[1] >= b->pivot)
            //     rrb(b);
            if (a->content[0] == b->pivot)
                b->n_rotates += rab(b, a);
            else
                b->n_rotates += rb(b);
        }
        else
        {
            if (b->content[b->len - 1] > b->content[0])
                rrb(b);
            if (is_correct(b, b->len) && b->content[0] < lowest(a, a->len))
                break ;
            if (a->content[0] == b->pivot && n_pushes != len / 2 - 1)
                ra(a);
            n_pushes += pa(a, b);
        }
    }
    if (a->content[1] == b->pivot)
        try_ss(a, b);
    put_on_top_b(a, b);
    return (n_pushes);
}

void    mutual_sort_a(t_stack *a, t_stack *b, int len)
{
    int n_pushes;

	a->is_segmented = (a->len != len);
	a->pivot = find_pivot(a, len);
    if (a->len <= 3)
        return (push_swap_3a(a));
    if (len <= 2 || is_correct(a, a->len))
    {
        if (len == 2 && !is_correct(a, 2))
            try_ss(a, b);
        if (is_correct(b, b->len))
        {
            while (b->len)
                pa(a, b);
        }
        return ;
    }
    n_pushes = split_a(a, b, len);
    mutual_sort_a(a, b, len - n_pushes);
    mutual_sort_b(b, a, n_pushes);
}

void    mutual_sort_b(t_stack *b, t_stack *a, int len)
{
    int n_pushes;

	b->is_segmented = (b->len != len);
	b->pivot = find_pivot(b, len);
    if (b->len <= 3)
        return (push_swap_3b(a, b));
    if (is_correct(a, a->len) && is_correct(b, b->len))
    {
        while (b->len)
            pa(a, b);
        return ;
    }
    if (len <= 2 || is_correct(b, len))
    {
        if (len == 2 && !is_correct(b, 2))
            try_ss(b, a);
        while (--len >= 0)
            pa(a, b);
        return ;
    }
    n_pushes = split_b(a, b, len);
    mutual_sort_a(a, b, n_pushes);
    mutual_sort_b(b, a, len - n_pushes);
}
