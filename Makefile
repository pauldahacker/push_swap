# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pde-masc <pde-masc@student.42barcel>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/17 14:52:11 by pde-masc          #+#    #+#              #
#    Updated: 2024/02/06 19:22:47 by pde-masc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
BONUS	= checker

BLUE 	= \033[0;34m
GREEN 	= \033[0;32m
RED 	= \033[0;31m
ORANGE	= \033[38;5;209m
YELLOW	= \033[0;93m
BROWN 	= \033[38;2;184;143;29m
RESET 	= \033[0m

SRCS    = swap.c push.c rotate.c rrotate.c stack_utils.c stack.c \
		  small_sort.c mutual_sort_utils.c mutual_sort.c push_swap.c ft.c \

BONUS_SRCS	= get_next_line.c get_next_line_utils.c stack_bonus.c ft_bonus.c \
			stack_utils_bonus.c swap_bonus.c push_bonus.c rotate_bonus.c \
			rrotate_bonus.c checker_utils.c checker.c

HEADER  = push_swap.h
BONUS_HEADER = checker.h

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror
RM      = rm -rf

%.o:    %.c
	@echo "$(BROWN)Compiling   ${BLUE}→   $(YELLOW)$< $(RESET)"
	@${CC} ${CFLAGS} -c -o $@ $<

OBJS    = ${SRCS:.c=.o}
BONUS_OBJS	= ${BONUS_SRCS:.c=.o}
DEPS = $(addsuffix .d, $(basename $(SRCS)))
DEPS2 = $(addsuffix .d, $(basename $(BONUS_SRCS)))

all: ${NAME}

-include ${DEPS}
${NAME}:	$(OBJS) $(HEADER)
	@${CC} ${SRCS} -o ${NAME}
	@echo "\n$(GREEN)Created $(NAME) ✓ $(RESET)\n"

-include ${DEPS2}
bonus:	$(BONUS_OBJS) $(BONUS_HEADER)
	@touch $@
	@${CC} ${BONUS_SRCS} -o ${BONUS}
	@echo "\n$(GREEN)Created ${BONUS} ✓$(RESET)\n"

clean:
	${RM} ${OBJS} ${BONUS_OBJS}
	${RM} ${DEPS} ${DEPS2}
	@echo "\n${GREEN}Objects cleaned successfully $(RESET)\n"

fclean:
	@${RM} ${OBJS} ${BONUS_OBJS}
	@${RM} ${DEPS} ${DEPS2}
	@${RM} bonus
	@${RM} ${NAME} ${BONUS}
	@echo "\n${GREEN}Objects and executables cleaned successfully $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re
