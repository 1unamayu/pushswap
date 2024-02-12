# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/23 11:50:42 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/11 01:16:43 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Changelog :
#   2022/03/23 - first version. SRC && OBJ folders
#   2022/04/05 - second version. make re improved
#  
# ------------------------------------------------
NAME = push_swap
SRC_DIR = src
SRC2_DIR = src/sort
OBJ_DIR = .objs
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
# ------------- COLORS
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m
PINK			=   \033[38;5;162m
LIGHT_PINK      =   \033[38;5;200m
BLUE			= 	\033[38;5;39m
DARK_BLUE		=   \033[38;5;57m
# -----------------SRC
SRC =	$(SRC_DIR)/push_swap.c \
		$(SRC_DIR)/ft_stack_indexing.c \
		$(SRC_DIR)/ft_stack_min_max.c \
		$(SRC_DIR)/ft_exit_error.c \
		$(SRC_DIR)/ft_data_validation.c \
		$(SRC_DIR)/ft_stack_actions.c \
		$(SRC_DIR)/ft_data_load.c \
		$(SRC_DIR)/ft_check_duplicates.c \
		$(SRC_DIR)/ft_build_stack.c \
		$(SRC_DIR)/ft_is_sorted.c \
		$(SRC_DIR)/ft_stack_free.c \
		$(SRC_DIR)/ft_sort.c \
		$(SRC_DIR)/ft_stack_len.c \
		$(SRC_DIR)/ft_sort_3.c\
		$(SRC_DIR)/ft_sort_4.c\
		$(SRC_DIR)/ft_sort_5.c\
		$(SRC_DIR)/ft_sort_med.c\
		$(SRC_DIR)/ft_sort_big.c\
		$(SRC_DIR)/ft_stack_keying.c\

SRC2= expan.c
OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = gcc
HEAD = -I./includes -I./$(LIBFT_DIR)
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
LFLAGS = -L ./$(LIBFT_DIR) -lft -lreadline
RM = /bin/rm -rf

all: $(NAME)


$(NAME): $(OBJ) $(LIBFT)
		$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME)
		clear
		@echo "$(LIGHT_PINK)╔════════════════════════════════════╗"
		@echo "$(LIGHT_PINK)║  ${PINK}   😊  PUSH_SWAP COMPLETE   😊    ║"
		@echo "$(LIGHT_PINK)╚════════════════════════════════════╝ $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(ORANGE)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD) -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

$(LIBFT):
		@make -C $(LIBFT_DIR) bonus

clean:
		@make clean -C $(LIBFT_DIR)
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@make fclean -C $(LIBFT_DIR)
		@$(RM) $(NAME)
		sleep .1
		clear
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║          ${DARK_BLUE} 🗑️  ALL CLEAN 🗑️ ${BLUE}          ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

leaks: $(NAME)
	@echo "$(BLUE) No arguements $(RESET)"
	@valgrind ./push_swap 2>&1 | grep leaks
	@echo "$(BLUE) Sorted $(RESET)"
	@valgrind ./push_swap "1 2" 2>&1 | grep leaks
	@echo "$(BLUE) Repeated input $(RESET)"
	@valgrind ./push_swap "2 2" 2>&1 | grep leaks
	@echo "$(BLUE) Bad arguements $(RESET)"
	@valgrind ./push_swap "a 2" 2>&1 | grep leaks
	@echo "$(BLUE) MAXINT $(RESET)"
	@valgrind ./push_swap "2147483649" 2>&1 | grep leaks
	@echo "$(BLUE) 30 random $(RESET)"
	@valgrind ./push_swap 22 2 4 17 13 8 3 11 27 21 24 30 19 28 12 26 7 14 16 18 23 10 25 20 6 29 15 5 1 9 2>&1 | grep leaks
	@echo "$(BLUE) 30 random 1 argument $(RESET)"
	@valgrind ./push_swap "22 2 4 17 13 8 3 11 27 21 24 30 19 28 12 26 7 14 16 18 23 10 25 20 6 29 15 5 1 9" 2>&1 | grep leaks
	@echo "$(BLUE) 3 arguements with error $(RESET)"
	@valgrind ./push_swap "22 2 s" 2 1 2>&1 | grep leaks
		
.PONY: all clean fclean re debug_mac debug_linux