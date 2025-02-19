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

void	apply_instructions(t_stack *a, t_stack *b)
{
	char	*line;

	line = get_next_line(STDIN_FILENO);
	if (!line)
		return ;
	if (is_move_valid(line) && line[0] == 'r')
		apply_r(a, b, line);
	else if (is_move_valid(line) && line[0] == 'p')
		apply_p(a, b, line);
	else if (is_move_valid(line) && line[0] == 's')
		apply_s(a, b, line);
	else
	{
		free(line);
		write(2, "Error\n", 6);
		destroy_stack(&a);
		destroy_stack(&b);
		exit(1);
	}
	free(line);
	apply_instructions(a, b);
}

void    checker(t_stack *a)
{
    t_stack	*b;

    b = create_stack(0, 0);
    if (!b)
    {
		write(2, "Error\n", 6);
		destroy_stack(&a);
		exit(1);
	}
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
	checker(a);
	destroy_stack(&a);
	return (0);
}
