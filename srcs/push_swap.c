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

void	push_swap(t_stack *a)
{
	t_stack	*b;

	if (!a || !(a->len) || a->len == 1)
		return ;
	b = create_stack(0, NULL);
	if (!b)
		return ;
	mutual_sort_a(a, b, a->len);
	destroy_stack(&b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (!argc || argc == 1)
		return (0);
	a = create_stack(argc - 1, argv + 1);
	if (!a)
	{
		write(2, "Error\n", 6);
		exit(1);
	}
	if (has_repeats(a))
	{
		write(2, "Error\n", 6);
		destroy_stack(&a);
		exit(1);
	}
	push_swap(a);
	destroy_stack(&a);
	return (0);
}
