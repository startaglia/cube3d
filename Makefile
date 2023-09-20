NAME			= cub3D
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror -g #-fsanitize=address -fcommon
RM				= rm -rf
LIBFT_DIR		= libs/libft
MLX_LINUX_DIR	= libs/mlx_linux
MLX_DIR			= libs/mlx
INCLUDE			= includes/
SRC_DIR			= srcs
OBJ_DIR			= objs
LIBFT			= $(LIBFT_DIR)/libft.a
MLX				= $(MLX_DIR)/libmlx.a
MLX_LINUX		= $(MLX_LINUX_DIR)/libmlx_Linux.a
LIBS			= $(LIBFT)
SRCS			= $(wildcard $(SRC_DIR)/*.c)
OBJS			= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
CLEAR			= clear

ifeq ($(OS),Windows_NT) 
    detected_OS := Windows
else
    detected_OS := $(shell sh -c 'uname 2>/dev/null || echo Unknown')
endif

ifeq ($(detected_OS),Darwin)
	LIBS += $(MLX)
	LINKER_MAC = -framework OpenGL -framework AppKit
	MINILIBX = mlx
else ifeq ($(detected_OS),Linux)
	LIBS += $(MLX_LINUX)
	LINKER_LINUX += -L$(MLX_LINUX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_LINUX_DIR) -lXext -lX11 -lm -lz
	LINUX_OBJ_FLAGS = -I/usr/include -I$(MLX_LINUX_DIR)
	MINILIBX = mlx_linux
endif

all: $(NAME)

$(NAME): $(LIBS) $(OBJ_DIR) $(OBJS)
	@$(CC) $(CFLAGS) $(LINKER_MAC) -I $(INCLUDE) $(OBJS) $(LIBS) $(LINKER_LINUX) -o $@
	@$(CLEAR)
	@echo "[+] $(NAME) compiled$(END)"

$(OBJ_DIR):
	@mkdir -p $@
	@echo "[+] $@ folder created$(END)"

$(LIBFT):
	@make -s -C $(LIBFT_DIR)
	@echo "[+] libft compiled$(END)"

$(MLX_LINUX):
	@chmod +x $(MLX_LINUX_DIR)/configure
	@make -s -C $(MLX_LINUX_DIR) 2> /dev/null 1> /dev/null
	@echo "[+] mlx_linux compiled$(END)"

$(MLX):
	@make -s -C $(MLX_DIR) 2> /dev/null
	@echo "[+] mlx compiled$(END)"

$(OBJ_DIR)/%.o : $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -I $(INCLUDE) $(LINUX_OBJ_FLAGS) -c $< -o $@
	@echo "[+] $@ compiled$(END)"

clean:
	@make -s -C $(LIBFT_DIR) clean
	@echo "[+] libft cleaned$(END)"
	@make -s -C libs/$(MINILIBX) clean 1> /dev/null
	@echo "[+] $(MINILIBX) cleaned$(END)"
	@$(RM) $(OBJ_DIR)
	@echo "[+] $(NAME) cleaned$(END)"

fclean: clean
	@make -s -C $(LIBFT_DIR) fclean
	@echo "[+] libft fcleaned$(END)"
	@$(RM) $(NAME)
	@echo "[+] $(NAME) fcleaned$(END)"

re: fclean all