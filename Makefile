# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/04/30 08:36:49 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
AR          = ar
ARFLAGS     = rcs
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3
SRC_FILES   = dprintf.c printf.c snprintf.c sprintf.c \
	vdprintf.c vprintf.c vsnprintf.c vsprintf.c
SRCS        = $(wildcard src/*.c)
TEST_SRCS   = $(wildcard tests/*.c)
OBJ_DIR     = obj
OBJS        = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_OBJS   = $(patsubst tests/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
INCLUDES    = -Iinclude -Ilibft/include
HEADERS     = include/libft_printf.h include/libft_internal.h

LIBFT       = libft
LIBFT_FLAGS = -Llibft -lft
LIBFT_DIR   = ./libft
LIBFT_LIB   = libft/libft.a

LDFLAGS     = $(LIBFT_FLAGS) -lbsd

RED         = \e[31m
GREEN       = \e[32m
YELLOW      = \e[33m
BLUE        = \e[34m
MAGENTA     = \e[35m
CYAN        = \e[36m
RESET       = \e[m

all: $(NAME)

bonus: all

$(NAME): $(LIBFT) $(OBJS)
	@cp $(LIBFT_LIB) $(NAME)
	@printf "$(BLUE)%s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: tests/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(INCLUDES) -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR) --no-print-directory

norm:
	@-norminette $(SRCS) $(HEADER) | grep -v "OK"

test: $(OBJS) $(TEST_OBJS) $(HEADER)
	$(CC) $(TEST_OBJS) $(INCLUDES) $(OBJS) $(CFLAGS) $(LDFLAGS)
	@printf "$(BLUE)%s$(RESET): $(CYAN)Running$(RESET) $(NAME)\n" $(NAME)
	@./a.out

clean:
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)
	@make -C $(LIBFT_DIR) clean --no-print-directory

fclean: clean
	@printf "$(BLUE)%s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME) a.out
	@make -C $(LIBFT_DIR) fclean --no-print-directory

re: fclean
	@make all

.PHONY: all clean fclean re norm bonus $(LIBFT)
