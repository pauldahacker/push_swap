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
CFLAGS  	= -Wall -Wextra -Werror
RM      	= rm -rf

# DIRECTORIES
SRCS_DIR  = srcs/
OBJS_DIR  = objs/
INCLUDE_DIR = headers/

# FILES
LIBFT_FILES = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
			  ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
			  ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
			  ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c \
			  ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c \
			  ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c \
			  ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c

SRCS_FILES = swap.c push.c rotate.c rrotate.c stack_utils.c stack.c \
			 small_sort.c mutual_sort_utils.c mutual_sort.c push_swap.c

BONUS_SRCS_FILES = get_next_line.c get_next_line_utils.c stack_bonus.c \
				   stack_utils_bonus.c swap_bonus.c push_bonus.c rotate_bonus.c \
				   rrotate_bonus.c checker_utils.c checker.c

# PATHS
HEADERS	= $(INCLUDE_DIR)push_swap.h
BONUS_HEADERS	= $(INCLUDE_DIR)checker.h
SRCS       = $(addprefix $(SRCS_DIR), $(SRCS_FILES))
BONUS_SRCS = $(addprefix $(SRCS_DIR), $(BONUS_SRCS_FILES))
OBJS       = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(SRCS))
BONUS_OBJS = $(patsubst $(SRCS_DIR)%.c, $(OBJS_DIR)%.o, $(BONUS_SRCS))

# LIBFT
LIBFT_DIR  = libft/
LIBFT      = $(LIBFT_DIR)libft.a
LIBFT_SRCS = $(addprefix $(LIBFT_DIR), $(LIBFT_FILES))

# RULES
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS) $(HEADERS)
	@$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)
	@echo "\n$(GREEN)Created $(NAME) ✓ $(RESET)\n"

# OBJECT FILE COMPILATION
$(OBJS_DIR)%.o: $(SRCS_DIR)%.c Makefile
	@mkdir -p $(OBJS_DIR)
	@echo "$(BROWN)Compiling ${BLUE}→ $(YELLOW)$< $(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(LIBFT): $(LIBFT_SRCS)
	@$(MAKE) -s -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT) $(BONUS_OBJS) $(BONUS_HEADERS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)
	@echo "\n$(GREEN)Created $(BONUS_NAME) ✓$(RESET)\n"

clean:
	@echo "$(YELLOW)Cleaning $(LIBFT_DIR) object files...$(RESET)"
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(YELLOW)Cleaning $(NAME) object files...$(RESET)"
	@$(RM) $(OBJS_DIR)
	@echo "$(GREEN)Object files cleaned successfully ✓ $(RESET)\n"

fclean: clean
	@echo "$(YELLOW)Cleaning executables...$(RESET)"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "$(GREEN)Executables cleaned successfully ✓ $(RESET)\n"

re: fclean all

.PHONY: all clean fclean re bonus
