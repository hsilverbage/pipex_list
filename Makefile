.PHONY: 		clean fclean re norm

NAME = pipex

CC = cc -g3
CFLAGS = -Wall -Wextra -Werror
INCLUDES = -I ./includes

# COLORS
RED=\033[0;31m
BLUE=\033[0;34m
GREEN=\033[0;32m
YELLOW=\033[0;33m
END=\033[0m

SRC_DIR = ./sources
U_DIR = ./utils
OBJ_DIR = .obj

LIBFT = libft/libft.a

SRC =	$(SRC_DIR)/main.c				\
		$(SRC_DIR)/path.c				\
		$(SRC_DIR)/free.c				\
		$(SRC_DIR)/ft_exec_children.c	\
		$(U_DIR)/ft_strjoin_slash.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: $(NAME)

$(NAME): lib $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) $(INCLUDES) $(LIBFT) -o $(NAME)
	@echo "$(GREEN)Compilation succeded ! ✔️$(END)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)/sources
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

lib:
	@make -sC libft

norm:
	@norminette ./libft ./sources ./includes | grep "Error" && echo "$(RED)Norminette KO!$(END)" || echo "$(GREEN)Norminette OK!$(END)"

clean:
	@echo "$(YELLOW)All .o files deleted 🗑 $(END)"
		@make clean -sC libft
		@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(YELLOW)The final program is deleted 🗑 $(END)"
	@make fclean -sC libft
	@rm -f $(NAME)

re: fclean norm all
