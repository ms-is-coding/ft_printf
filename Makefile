# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smamalig <smamalig@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/13 21:10:40 by smamalig          #+#    #+#              #
#    Updated: 2025/03/27 18:26:16 by smamalig         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = libftprintf.a
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -O3 -g3
AR          = ar
ARFLAGS     = rcs
SRCS        = $(wildcard src/*.c)
TEST_SRCS   = $(wildcard tests/*.c)
OBJ_DIR     = obj
OBJS        = $(patsubst src/%.c, $(OBJ_DIR)/%.o, $(SRCS))
TEST_OBJS   = $(patsubst tests/%.c, $(OBJ_DIR)/%.o, $(TEST_SRCS))
LIBFT       = libft/libft.a
INCLUDES    = -Iinclude -Ilibft/include
HEADER      = include/libft_printf.h include/libft_internal.h
LIBS        = -lm -Llibft -lft

# Colors

RED         = \033[0;31m
GREEN       = \033[0;32m
YELLOW      = \033[0;33m
BLUE        = \033[0;34m
MAGENTA     = \033[0;35m
CYAN        = \033[0;36m
BOLD        = \033[1m
RESET       = \033[0m

all: $(NAME)

bonus: all

$(NAME): $(OBJS)
	@cp $(LIBFT) $(NAME)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(YELLOW)Building$(RESET) $(NAME)\n" $(NAME)
	@ar rcs $(NAME) $(OBJS)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(OBJ_DIR)/%.o: tests/%.c $(HEADER)
	@mkdir -p $(dir $@)
	@printf "$(BLUE)%12s$(RESET): $(MAGENTA)Compiling$(RESET) $<\n" $(NAME)
	@$(CC) $(INCLUDES) -c $< -o $@

norm:
	@-norminette $(SRCS) $(HEADER) -R CheckDefine | grep -v "OK"

test: $(OBJS) $(TEST_OBJS) $(HEADER)
	@$(CC) $(TEST_OBJS) $(OBJS) $(CFLAGS) $(LIBS)
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(CYAN)Running$(RESET) $(NAME)\n" $(NAME)
	@./a.out

clean:
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) object files\n" $(NAME)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(BOLD)$(BLUE)%12s$(RESET): $(RED)Removing$(RESET) executables and libraries\n" $(NAME)
	@rm -f $(NAME) a.out

re: fclean all

.PHONY: all clean fclean re norm bonus
