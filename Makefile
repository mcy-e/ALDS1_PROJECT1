# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Directories
SRC_DIR = .
OBJ_DIR = ./output
INCLUDE_DIR = ./include

# Detect all source files
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Target executable name
TARGET = $(OBJ_DIR)/main_program

# Default target
all: $(TARGET)

# Rule to build the target
$(TARGET): $(OBJECTS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OBJECTS) -o $@
	@echo "Build successful: $@"

# Rule to build object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned up all build files."

