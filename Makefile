# ==========================================
# Project Settings
# ==========================================
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -O3 -I./include/ #-fsanitize=address
LDFLAGS		:= -L./lib/minilibx-linux/ -lmlx -lXext -lX11 -lm

# ==========================================
# Directory Structure
# ==========================================
SRC_DIR			:= src
SRC_DIR_BONUS	:= src_bonus
BUILD_DIR		:= build
BUILD_DIR_BONUS	:= build_bonus
OBJ_DIR			:= $(BUILD_DIR)/objs
OBJ_DIR_BONUS	:= $(BUILD_DIR_BONUS)/objs
DEP_DIR			:= $(BUILD_DIR)/deps
DEP_DIR_BONUS	:= $(BUILD_DIR_BONUS)/deps

# ==========================================
# Source & Object Discovery
# ==========================================
SRCS		:=	$(SRC_DIR)/initialization.c \
				\
				$(SRC_DIR)/rendering/movement.c \
				$(SRC_DIR)/rendering/rendering.c \
				$(SRC_DIR)/rendering/utils.c \
				\
				$(SRC_DIR)/rendering/raycasting/bresenham.c \
				$(SRC_DIR)/rendering/raycasting/intersections.c \
				$(SRC_DIR)/rendering/raycasting/projection.c \
				$(SRC_DIR)/rendering/raycasting/texture.c \
				\
				$(SRC_DIR)/utils/death.c \
				$(SRC_DIR)/utils/ft_split.c \
				$(SRC_DIR)/utils/ft_split_not_replace.c \
				$(SRC_DIR)/utils/read_file.c \
				$(SRC_DIR)/utils/string.c \
				$(SRC_DIR)/utils/utils_matriz.c \
				$(SRC_DIR)/utils/utils_vec.c \
				$(SRC_DIR)/utils/append.c \
				$(SRC_DIR)/utils/lens.c \
				\
				$(SRC_DIR)/parsing/valid_1.c \
				$(SRC_DIR)/parsing/valid_2.c \
				$(SRC_DIR)/parsing/valid_3.c \
				$(SRC_DIR)/parsing/valid_4.c \
				$(SRC_DIR)/parsing/valid_5.c \
				$(SRC_DIR)/parsing/valid_6.c \
				$(SRC_DIR)/parsing/parsing.c \
				./main.c

SRCS_BONUS	:=	$(SRC_DIR_BONUS)/initialization_bonus.c \
				\
				$(SRC_DIR_BONUS)/rendering/movement_bonus.c \
				$(SRC_DIR_BONUS)/rendering/rendering_bonus.c \
				$(SRC_DIR_BONUS)/rendering/utils_bonus.c \
				\
				$(SRC_DIR_BONUS)/rendering/raycasting/bresenham_bonus.c \
				$(SRC_DIR_BONUS)/rendering/raycasting/intersections_bonus.c \
				$(SRC_DIR_BONUS)/rendering/raycasting/projection_bonus.c \
				$(SRC_DIR_BONUS)/rendering/raycasting/texture_bonus.c \
				\
				$(SRC_DIR_BONUS)/utils/death_bonus.c \
				$(SRC_DIR_BONUS)/utils/ft_split_bonus.c \
				$(SRC_DIR_BONUS)/utils/ft_split_not_replace_bonus.c \
				$(SRC_DIR_BONUS)/utils/read_file_bonus.c \
				$(SRC_DIR_BONUS)/utils/string_bonus.c \
				$(SRC_DIR_BONUS)/utils/utils_matriz_bonus.c \
				$(SRC_DIR_BONUS)/utils/utils_vec_bonus.c \
				$(SRC_DIR_BONUS)/utils/append_bonus.c \
				$(SRC_DIR_BONUS)/utils/lens_bonus.c \
				\
				$(SRC_DIR_BONUS)/parsing/valid_1_bonus.c \
				$(SRC_DIR_BONUS)/parsing/valid_2_bonus.c \
				$(SRC_DIR_BONUS)/parsing/valid_3_bonus.c \
				$(SRC_DIR_BONUS)/parsing/valid_4_bonus.c \
				$(SRC_DIR_BONUS)/parsing/valid_5_bonus.c \
				$(SRC_DIR_BONUS)/parsing/valid_6_bonus.c \
				$(SRC_DIR_BONUS)/parsing/parsing_bonus.c \
				./main_bonus.c

# Transforms src/file.c into build/objs/file.o
OBJS		:= $(patsubst %.c,$(OBJ_DIR)/%.o,$(SRCS))
OBJS_BONUS	:= $(patsubst %.c,$(OBJ_DIR_BONUS)/%.o,$(SRCS_BONUS))
DEPS		:= $(patsubst %.c,$(DEP_DIR)/%.d,$(SRCS))
DEPS_BONUS	:= $(patsubst %.c,$(DEP_DIR_BONUS)/%.d,$(SRCS_BONUS))

# ==========================================
# Compiler Flags (including dependency generation)
# ==========================================
CPPFLAGS	= -MMD -MP -MF $(DEP_DIR)/$*.d
CPPFLAGS_BONUS	= -MMD -MP -MF $(DEP_DIR_BONUS)/$*.d

# ==========================================
# Build Rules
# ==========================================
all: .mlx $(NAME)

bonus: .mlx .bonus

.mlx: lib/minilibx-linux
	@echo "Building mlx..."
	@$(MAKE) -C ./lib/minilibx-linux/
	@touch .mlx

.bonus: $(OBJS_BONUS)
	@echo "Linking bonus $(NAME)..."
	@$(CC) $(OBJS_BONUS) -o $(NAME) $(LDFLAGS)
	@touch .bonus
	@echo "Build successful!"

lib/minilibx-linux:
	@echo "Extracting minilibx-linux..."
	@cd ./lib && tar -xzf minilibx-linux.tgz

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: %.c .mlx
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR)/$*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@

$(OBJ_DIR_BONUS)/%.o: %.c .mlx
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR_BONUS)/$*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(CPPFLAGS_BONUS) -c $< -o $@

# ==========================================
# Cleanup
# ==========================================
clean:
	@echo "Cleaning object files..."
	@rm -rf $(BUILD_DIR) $(BUILD_DIR_BONUS)

fclean: clean
	@echo "Cleaning minilibx..."
	@-$(MAKE) -C ./lib/minilibx-linux/ clean 2>/dev/null || true
	@echo "Removing library and binary..."
	@rm -rf ./lib/minilibx-linux/
	@rm -rf $(NAME) .mlx .bonus

re: fclean all

# Include generated dependency files
-include $(DEPS)
-include $(DEPS_BONUS)

norm:
	@echo "Running norminette..."
	@norminette $(SRCS) ./include
	@norminette $(SRCS_BONUS) ./include

.PHONY: all clean fclean re norm bonus
