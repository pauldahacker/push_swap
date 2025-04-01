/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:58:57 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 19:30:33 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static void	apply_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return ;
	if (is_move_valid(line) && line[0] == 'r')
		apply_rotate(a, b, line);
	else if (is_move_valid(line) && line[0] == 'p')
		apply_push(a, b, line);
	else if (is_move_valid(line) && line[0] == 's')
		apply_swap(a, b, line);
	else
	{
		destroy_stack(&a);
		destroy_stack(&b);
		handle_error(NULL);
	}
	free(line);
	apply_instructions(a, b);
}

static void    checker(t_stack *a)
{
    t_stack	*b;

    b = init_stack(a->len, 0);
    apply_instructions(a, b);
    if (is_correct(a, a->len))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
    destroy_stack(&b);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;

	if (!argc || argc == 1)
		return (0);
	a = create_stack_A(argc - 1, argv + 1);
	checker(a);
	destroy_stack(&a);
	return (0);
}
