/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 19:27:23 by pde-masc          #+#    #+#             */
/*   Updated: 2024/02/06 19:30:17 by pde-masc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define NEWLINE '\n'
# define BYTE_START 1

// get_next_line.c
char	*get_next_line(int fd);

// get_next_line_utils.c
char	*tochr(char *str, int c);
char	*getbufferline(char *s);
int		myread(int fd, char *buf);
char	*destroy(char **s);
char	*assemble(int fd, char *buf, int readbytes);

// checker_utils.c
void	apply_rotate(t_stack *a, t_stack *b, char *line);
void	apply_push(t_stack *a, t_stack *b, char *line);
void	apply_swap(t_stack *a, t_stack *b, char *line);
int		is_move_valid(char *move);

#endif
