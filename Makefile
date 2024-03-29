# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: uurbizu- <uurbizu-@student.42urduliz.co    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/28 20:36:39 by uurbizu-          #+#    #+#              #
#    Updated: 2023/12/22 19:22:17 by uurbizu-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

# Projects
NAME = push_swap
NAME_BONUS = checker

# Compiler
CC = cc
CFLAGS = -Wall  -Wextra -Werror  -g3 #-fsanitize=address
MAKE = make

# Directories
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = inc
MAIN_DIR = mains
LIBFT_PATH = inc/libft

# Files
SRC_FILES = $(wildcard $(SRC_DIR)/*.c) 
SRC_MAIN = $(SRC_DIR)/$(MAIN_DIR)/main.c
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES)) 
OBJ_MAIN = $(patsubst $(SRC_DIR)/$(MAIN_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_MAIN))

SRC_BONUS_MAIN = $(SRC_DIR)/$(MAIN_DIR)/checker_bonus.c
OBJ_BONUS_MAIN = $(patsubst $(SRC_DIR)/$(MAIN_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_BONUS_MAIN))


LIBFT = $(LIBFT_PATH)/libft.a

#.SILENT: esto para quitar los @

# all
all: $(NAME)

$(NAME): $(OBJ_FILES) $(OBJ_MAIN) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
#	@echo "$(NAME): $(GREEN)$(OBJ_DIR) directory was created$(RESET)"
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -c -o $@ $<
	@echo "$(NAME): $(GREEN)$@ object file created$(RESET)"

$(OBJ_DIR)/main.o: $(SRC_DIR)/$(MAIN_DIR)/main.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -c -o $@ $<
	@echo "$(NAME): $(GREEN)$@ object file created$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) directory was created$(RESET)"
	
$(LIBFT):
	@$(MAKE) -C $(LIBFT_PATH)
	@echo "$(NAME): $(GREEN)$(LIBFT) was created$(RESET)"

# bonus
bonus: $(NAME_BONUS)

$(NAME_BONUS): $(OBJ_FILES) $(OBJ_BONUS_MAIN) $(LIBFT) 
	@$(CC) $(CFLAGS) -o $@ $^ -L$(LIBFT_PATH) -lft
	@echo "$(NAME_BONUS): $(GREEN)$(NAME_BONUS) was created$(RESET)"

$(OBJ_DIR)/checker_bonus.o: $(SRC_DIR)/$(MAIN_DIR)/checker_bonus.c
	@$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -I$(LIBFT_PATH) -c -o $@ $<
	@echo "$(NAME): $(GREEN)$@ object file created$(RESET)"
	@mkdir -p $(OBJ_DIR)
	@echo "$(NAME): $(GREEN)$(OBJ_DIR) directory was created$(RESET)"
	
# clean
clean:
	@$(MAKE) -C $(LIBFT_PATH) fclean
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -r -f $(OBJ_DIR)
	@echo "$(NAME): $(RED)$(OBJ_DIR) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

# fclean
fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

# re	
re: fclean all

# re_bonus
re_bonus: fclean bonus

.PHONY: all bonus clean fclean re re_bonus