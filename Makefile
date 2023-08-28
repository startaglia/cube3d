# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: startagl <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/08/28 21:52:59 by startagl          #+#    #+#              #
#    Updated: 2023/08/28 23:32:02 by startagl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = cube3d
CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g
SRC_DIR     = src
UTILS_DIR   = utils
INCLUDE_DIR = includes
ASSETS_DIR  = assets
MAPS_DIR    = maps
OBJ_DIR     = objs
SRCS        = $(wildcard $(SRC_DIR)/*.c)
UTILS_SRCS  = $(wildcard $(UTILS_DIR)/*.c)
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o) $(UTILS_SRCS:$(UTILS_DIR)/%.c=$(OBJ_DIR)/%.o)
RM          = rm -rf

.PHONY: all clean fclean re

all: $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I $(INCLUDE_DIR) -c $< -o $@

$(OBJ_DIR)/%.o : $(UTILS_DIR)/%.c $(INCLUDE_DIR)/*.h | $(OBJ_DIR)
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

