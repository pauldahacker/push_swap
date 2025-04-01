/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 18:59:25 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 19:30:51 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	if (s1[i] - s2[i] < 0)
		return (-1);
	if (s1[i] - s2[i] > 0)
		return (1);
	return (0);
}

void	apply_rotate(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rr\n") == 0)
		rotate(a);
	if (ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0)
		rotate(b);
	if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrr\n") == 0)
		rrotate(a);
	if (ft_strcmp(line, "rrb\n") == 0 || ft_strcmp(line, "rrr\n") == 0)
		rrotate(b);
}

void	apply_push(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "pa\n") == 0)
		push(a, b);
	else if (ft_strcmp(line, "pb\n") == 0)
		push(b, a);
}

void	apply_swap(t_stack *a, t_stack *b, char *line)
{
	if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "ss\n") == 0)
		swap(a);
	if (ft_strcmp(line, "sb\n") == 0 || ft_strcmp(line, "ss\n") == 0)
		swap(b);
}

int	is_move_valid(char *line)
{
	return (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0
		|| ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
		|| ft_strcmp(line, "rr\n") == 0 || ft_strcmp(line, "rrr\n") == 0
		|| ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0
		|| ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
		|| ft_strcmp(line, "ss\n") == 0);
}
