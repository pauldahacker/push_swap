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

# COLORS
BLUE 	= \033[0;34m
GREEN 	= \033[0;32m
YELLOW	= \033[0;93m
BROWN 	= \033[38;2;184;143;29m
RESET 	= \033[0m

# COMPILATION
NAME    	= push_swap
BONUS_NAME	= checker
CC      	= gcc
CFLAGS  	= -Wall -Wextra -Werror #-fsanitize=address
RM      	= rm -rf

# DIRECTORIES
LIBFT_DIR  = libft/
INCLUDE_DIR = headers/
SRCS_DIR  = srcs/
BONUS_SRCS_DIR = $(SRCS_DIR)bonus/
OBJS_DIR  = objs/

# HEADERS
LIBFT_HEADER = $(LIBFT_DIR)libft.h
HEADERS	= $(INCLUDE_DIR)push_swap.h
BONUS_HEADERS = $(INCLUDE_DIR)checker.h $(HEADERS)

# FILES
LIBFT_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c \
	ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
	ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c \
	ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c \
	ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
	ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

COMMON_FILES = swap.c push.c rotate.c rrotate.c stack_utils.c stack.c \
	small_sort.c mutual_sort_utils.c mutual_sort.c

SRCS_FILES = $(COMMON_FILES) push_swap.c

BONUS_SRCS_FILES = checker_utils.c checker.c \
	get_next_line_utils.c get_next_line.c

# SOURCES & OBJECTS
LIBFT_SRCS = \
	$(addprefix $(LIBFT_DIR), $(LIBFT_FILES))
SRCS = \
	$(addprefix $(SRCS_DIR), $(SRCS_FILES))
BONUS_SRCS = \
	$(addprefix $(SRCS_DIR), $(COMMON_FILES)) \
	$(addprefix $(BONUS_SRCS_DIR), $(BONUS_SRCS_FILES))

LIBFT = $(LIBFT_DIR)libft.a
OBJS = $(addprefix $(OBJS_DIR), $(notdir $(SRCS:.c=.o)))
BONUS_OBJS = $(addprefix $(OBJS_DIR), $(notdir $(BONUS_SRCS:.c=.o))) \

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "$(GREEN)Created $(NAME) ✓ $(RESET)\n"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@mkdir -p $(OBJS_DIR)
	@echo "$(BROWN)Compiling ${BLUE}→ $(YELLOW)$< $(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS) $(BONUS_HEADERS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@echo "$(GREEN)Created $(BONUS_NAME) ✓$(RESET)\n"

$(OBJS_DIR)%.o: $(BONUS_SRCS_DIR)%.c Makefile
	@mkdir -p $(OBJS_DIR)
	@echo "$(BROWN)Compiling ${BLUE}→ $(YELLOW)$< $(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBFT): $(LIBFT_HEADER) $(LIBFT_SRCS)
	@$(MAKE) -s -C $(LIBFT_DIR)

clean:
	@echo "$(BLUE)Cleaning $(LIBFT_DIR) objects...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(BLUE)Cleaning $(NAME) objects...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)All objects removed ✓ $(RESET)\n"

fclean: clean
	@echo "$(BLUE)Cleaning $(LIBFT_DIR) executables...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(BLUE)Cleaning $(NAME) executables...$(RESET)"
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)All executables removed ✓ $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus
