# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: startagl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 21:52:59 by startagl          #+#    #+#              #
#    Updated: 2023/09/06 21:41:15 by startagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME        = cube3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g -fsanitize=address
SRC_DIR     = src
UTILS_DIR   = utils
STR_UTILS_DIR = $(UTILS_DIR)/str_utils
FILE_CTRL_DIR = $(SRC_DIR)/file_ctrl
INCLUDE_DIR = includes
ASSETS_DIR  = assets
MAPS_DIR    = maps
OBJ_DIR     = objs
SRCS        = $(wildcard $(SRC_DIR)/*.c) $(wildcard $(FILE_CTRL_DIR)/*.c)
UTILS_SRCS  = $(wildcard $(UTILS_DIR)/*.c) $(wildcard $(STR_UTILS_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(UTILS_SRCS:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o)
RM          = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
	mkdir -p $(OBJ_DIR)/str_utils
	mkdir -p $(OBJ_DIR)/file_ctrl

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(UTILS_DIR)/%.c $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(STR_UTILS_DIR)/%.c $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "[+] $(NAME) compiled"

clean:
	@$(RM) $(OBJ_DIR)
	@echo "[+] $(NAME) cleaned"

fclean: clean
	@$(RM) $(NAME)
	@echo "[+] $(NAME) fcleaned"

re: fclean all
