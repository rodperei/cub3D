# ==========================================
# Project Settings
# ==========================================
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -O0 -I./include/ #-fsanitize=address
LDFLAGS		:= -L./lib/minilibx-linux/ -lmlx -lXext -lX11 -lm

# ==========================================
# Directory Structure
# ==========================================
SRC_DIR		:= src
TEST_DIR	:= testes
BUILD_DIR	:= build
OBJ_DIR		:= $(BUILD_DIR)/objs
DEP_DIR		:= $(BUILD_DIR)/deps

# ==========================================
# Source & Object Discovery
# ==========================================
#SRCS		:= $(SRC_DIR)/parsing/parsing.c \
			   $(SRC_DIR)/parsing/valid_1.c \
				\
			   $(SRC_DIR)/utils/append.c \
			   $(SRC_DIR)/utils/death.c \
			   $(SRC_DIR)/utils/ft_split.c \
			   $(SRC_DIR)/utils/lens.c \
			   $(SRC_DIR)/utils/read_file.c \
			   $(SRC_DIR)/utils/string.c \
			   $(SRC_DIR)/utils/utils_matriz.c \
			   $(SRC_DIR)/utils/utils_vec.c \
				\
			   $(TEST_DIR)/test_parsing.c
SRCS		:=	$(SRC_DIR)/rendering/line.c \
				$(SRC_DIR)/rendering/movement.c \
				$(SRC_DIR)/rendering/rendering.c \
				$(SRC_DIR)/rendering/utils.c \
				\
				./tmp_main.c 

# Transforms src/file.c into build/objs/file.o
OBJS		:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
DEPS		:= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRCS))

# ==========================================
# Compiler Flags (including dependency generation)
# ==========================================
CPPFLAGS	= -MMD -MP -MF $(DEP_DIR)/$*.d

# ==========================================
# Build Rules
# ==========================================
all: .mlx $(NAME)

.mlx:
	@echo "Building mlx..."
	@$(MAKE) -C ./lib/minilibx-linux/
	@touch .mlx

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR)/$*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

# ==========================================
# Cleanup
# ==========================================
clean:
	@echo "Cleaning object files..."
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "Cleaning binary..."
	@$(MAKE) -C ./lib/minilibx-linux/ clean
	@rm -rf $(NAME) .mlx

re: fclean all

# Include generated dependency files
-include $(DEPS)

norm:
	@echo "Running norminette..."
	@norminette $(SRC_DIR) $(TEST_DIR) ./include

.PHONY: all clean fclean re norm
