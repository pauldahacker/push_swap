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
        if (stack->len == 4 && count == 1)
            break ;
		if (stack->len != 4 && count == len / 2)
			break ;
	}
	return (stack->content[i]);
}

/*
Returns 1 if swapping the stack is a smart move, 0 if not.
Conditions for swapping to be a smart move:
    i.  leads to a correct setup 
    OR
    ii. the first element of the stack should stay on the stack
    and all remaining elements that need to be pushed on other stack
    are directly after the first element.
*/
int	should_swap(t_stack *stack, int pushes_left)
{
	int	i;
	int	pushable_count;
    int flag;

	i = 0;
	pushable_count = 0;
    flag = 0;
    if (stack->len < 2)
        return (flag);
    swap(stack);
    if ((stack->a_or_b == A && is_correct(stack, stack->len))
        || (stack->a_or_b == B && is_reverse_correct(stack, stack->len)))
        flag = 1;
    swap(stack);
	while (++i <= pushes_left)
	{
		if ((stack->a_or_b == A && stack->content[i] <= stack->pivot)
            || (stack->a_or_b == B && stack->content[i] >= stack->pivot))
			pushable_count++;
	}
	if (pushable_count == pushes_left)
		flag = 1;
    return (flag);
}

/*
Checks if rotating the stack using r or rr leads to a correct setup.
If so, it returns ROTATE_FLAG or RROTATE_FLAG.
If not, it returns 0.
*/
int should_rotate(t_stack *stack, int pushes_left)
{
    int flag;

    flag = 0;
    if (stack->len < 2 )
        return (flag);
    rotate(stack);
    if ((stack->a_or_b == A && is_correct(stack, stack->len))
        || (stack->a_or_b == B && is_reverse_correct(stack, stack->len)))
        flag = ROTATE_FLAG;
    rrotate(stack);
    rrotate(stack);
    if (stack->a_or_b == A)
    {
        if (is_correct(stack, stack->len)
            || (stack->content[0] <= stack->pivot && stack->content[0] < stack->content[1]))
            flag = RROTATE_FLAG;
    }
    if (stack->a_or_b == B)
    {
        if (is_reverse_correct(stack, stack->len)
            || (stack->content[0] >= stack->pivot && stack->content[0] > stack->content[1]))
            flag = RROTATE_FLAG;
    }
    (void)pushes_left;
    rotate(stack);
    return (flag);
}

static int	split_a(t_stack *a, t_stack *b, int len)
{
	int	n_pushes;

    n_pushes = 0;
    while (!fast_solution_check(a, a->len) && n_pushes < len / 2)
    {
        if (should_swap(a, len / 2 - n_pushes))
            try_ss(a, b);
        else if (should_rotate(a, len / 2 - n_pushes) == ROTATE_FLAG)
            try_rab(a, b);
        else if (should_rotate(a, len / 2 - n_pushes) == RROTATE_FLAG)
            try_rrab(a, b);
        else if (a->content[0] > a->pivot)
            a->n_rotates += try_rab(a, b);
        else
        {
            if (b->content[0] == a->pivot && n_pushes != len / 2 - 1)
                rb(b);
            n_pushes += pb(b, a);
        }
    }
    if (b->len > 1 && b->content[1] == a->pivot)
        try_ss(b, a);
    put_on_top_a(a, b);
    return (n_pushes);
}

static int	split_b(t_stack *a, t_stack *b, int len)
{
    int	n_pushes;

    n_pushes = 0;
    while (!fast_solution_check(b, b->len) && n_pushes < len / 2)
    {
        if (should_swap(b, len / 2 - n_pushes))
            try_ss(b, a);
        else if (should_rotate(b, len / 2 - n_pushes) == ROTATE_FLAG)
            try_rab(b, a);
        else if (should_rotate(b, len / 2 - n_pushes) == RROTATE_FLAG)
            try_rrab(b, a);
        else if (b->content[0] < b->pivot)
            b->n_rotates += try_rab(b, a);
        else
        {
            if (a->content[0] == b->pivot && n_pushes != len / 2 - 1)
                ra(a);
            n_pushes += pa(a, b);
        }
    }
    if (a->len > 1 && a->content[1] == b->pivot)
        try_ss(a, b);
    put_on_top_b(a, b);
    return (n_pushes);
}

void    mutual_sort_a(t_stack *a, int len)
{
    int n_pushes;
    t_stack *b;

    b = a->other_stack;
	a->is_segmented = (a->len != len);
	a->pivot = find_pivot(a, len);
    if (a->len <= 3)
        return (push_swap_3a(a));
    if (len <= 2 || fast_solution_check(a, len))
    {
        if (len == 2 && a->content[0] > a->content[1])
            try_ss(a, b);
        return ;
    }
    n_pushes = split_a(a, b, len);
    mutual_sort_a(a, len - n_pushes);
    mutual_sort_b(b, n_pushes);
}

void    mutual_sort_b(t_stack *b, int len)
{
    int n_pushes;
    t_stack *a;

    a = b->other_stack;
	b->is_segmented = (b->len != len);
	b->pivot = find_pivot(b, len);
    if (b->len <= 3)
        return (push_swap_3b(a, b));
    if (len <= 2 || fast_solution_check(b, len))
    {
        if (len == 2 && b->content[0] < b->content[1])
            try_ss(b, a);
        if (fast_solution_check(a, a->len))
        {
            while (len--)
                pa(a, b);
        }
        return ;
    }
    n_pushes = split_b(a, b, len);
    mutual_sort_a(a, n_pushes);
    mutual_sort_b(b, len - n_pushes);
}
