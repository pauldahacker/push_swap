/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 13:38:12 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/05 19:43:13 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push_swap(t_stack *a)
{
	t_stack	*b;

	if (!a || !(a->len) || a->len == 1)
		return ;
	b = init_stack(a->len, B);
	if (!b)
		handle_error(a);
	a->other_stack = b;
	b->other_stack = a;
	mutual_sort_a(a, a->len);
	destroy_stack(&b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (!argc || argc == 1)
		return (0);
	a = create_stack_A(argc - 1, argv + 1);
	// printf("is correct: %d\n", is_correct(a, a->len));
	push_swap(a);
	destroy_stack(&a);
	return (0);
}
