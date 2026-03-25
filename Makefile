# ==========================================
# Project Settings
# ==========================================
NAME		:= cub3D
CC			:= cc
CFLAGS	:= -Wall -Wextra -Werror -O3

# ==========================================
# Directory Structure
# ==========================================
SRC_DIR		:= src
BUILD_DIR	:= build
OBJ_DIR		:= $(BUILD_DIR)/objs
DEP_DIR		:= $(BUILD_DIR)/deps

# ==========================================
# Source & Object Discovery
# ==========================================
SRCS		:= $(SRC_DIR)/XXXX \
			   $(SRC_DIR)/XXXX \

# Transforms src/file.c into build/objs/file.o
OBJS		:= $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)
DEPS		:= $(SRCS:$(SRC_DIR)/%.c=$(DEP_DIR)/%.d)

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
	@$(CC) $(OBJS) -o $(NAME)
	@echo "Build successful!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
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
	@rm -rf $(NAME)

re: fclean all

# Include generated dependency files
-include $(DEPS)

.PHONY: all clean fclean re
