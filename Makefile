# ==========================================
# Project Settings
# ==========================================
NAME		:= cub3D
CC			:= cc
CFLAGS		:= -Wall -Wextra -Werror -O3
LDFLAGS		:= -fsanitize=address

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
SRCS		:= $(SRC_DIR)/parsing/parsing.c \
			   $(SRC_DIR)/parsing/valid_1.c \
			   $(SRC_DIR)/parsing/read.c \
				\
			   $(SRC_DIR)/utils/append.c \
			   $(SRC_DIR)/utils/death.c \
			   $(SRC_DIR)/utils/ft_split.c \
			   $(SRC_DIR)/utils/lens.c \
			   $(SRC_DIR)/utils/utils_matriz.c \
			   $(SRC_DIR)/utils/utils_vec.c \
				\
			   $(TEST_DIR)/test_parsing.c

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
all: $(NAME)

$(NAME): $(OBJS)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@mkdir -p $(dir $(DEP_DIR)/$*)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) $(LDFLAGS) $(CPPFLAGS) -c $< -o $@

# ==========================================
# Cleanup
# ==========================================
clean:
	@echo "Cleaning object files..."
	@rm -rf $(BUILD_DIR)

fclean: clean
	@echo "Cleaning binary..."
	@rm -rf $(NAME)

re: fclean all

# Include generated dependency files
-include $(DEPS)

.PHONY: all clean fclean re
