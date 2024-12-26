# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -O2

# Directories
SRC_DIR = .
OBJ_DIR = ./output
INCLUDE_DIR = ./include
LIB_DIR = ./lib

# Directories containing source files
SRC_NUMBERS = ./1-Numbers
SRC_STRINGS = ./2-Strings
SRC_ARRAYS = ./3-Arrays
SRC_MATRICES = ./4-Matrices

# Exclude test files from source files (assuming they are in the 'Tests' directory)
EXCLUDE_TESTS = $(wildcard $(SRC_DIR)/Tests/*.c)

# Detect all source files except tests
SOURCES = $(filter-out $(EXCLUDE_TESTS), \
    $(wildcard $(SRC_NUMBERS)/*.c) \
    $(wildcard $(SRC_STRINGS)/*.c) \
    $(wildcard $(SRC_ARRAYS)/*.c) \
    $(wildcard $(SRC_MATRICES)/*.c))

# Detect all test files (including test_numbers.c)
TEST_SOURCES = $(wildcard $(SRC_DIR)/Tests/test_*.c)

# Convert source files to object files
OBJECTS = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SOURCES))

# Convert test files to object files
TEST_OBJECTS = $(patsubst %.c, $(OBJ_DIR)/test_%.o, $(TEST_SOURCES))

# Target executable name
TARGET = $(OBJ_DIR)/main_program

# Default target
all: $(TARGET)

# Rule to build the target executable
$(TARGET): $(OBJECTS)
	@mkdir -p $(OBJ_DIR)
	$(CC) $(OBJECTS) -o $@
	@echo "Build successful: $@"

# Rule to build object files for main source files
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Rule to build object files for test files
$(OBJ_DIR)/test_%.o: Tests/test_%.c
	@mkdir -p $(OBJ_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

# Rule to build and run tests
test: $(TEST_OBJECTS) $(TARGET)
	@echo "Running tests..."
	$(CC) $(TEST_OBJECTS) -o $(OBJ_DIR)/test_program -L$(LIB_DIR) -lmainlib
	$(OBJ_DIR)/test_program
	@echo "Tests completed."

# Clean build artifacts
clean:
	rm -rf $(OBJ_DIR)
	@echo "Cleaned up all build files."
