# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -O2

# Source file and executable
SRC = assembler_tool.cpp
TARGET = assembler_tool

# Default target
all: $(TARGET)

# Compile the source file into an executable
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) -o $@ $<

# Run the executable
run: $(TARGET)
	./$(TARGET)

# Clean up build files
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all run clean