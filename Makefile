# Simple Makefile for C++ Learning App
# Demonstrates basic build system concepts

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++11 -Wall -Wextra -g -O2
TARGET = cpplearning
SRCDIR = src
OBJDIR = obj

# Source files
SOURCES = $(wildcard $(SRCDIR)/*.cpp)
OBJECTS = $(SOURCES:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

# Default target
all: $(TARGET)

# Create object directory if it doesn't exist
$(OBJDIR):
	mkdir -p $(OBJDIR)

# Build the main executable
$(TARGET): $(OBJECTS)
	$(CXX) $(OBJECTS) -o $(TARGET)
	@echo "Build complete! Run with: ./$(TARGET)"

# Compile source files to object files
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean build artifacts
clean:
	rm -rf $(OBJDIR) $(TARGET)
	@echo "Clean complete!"

# Rebuild everything
rebuild: clean all

# Run the program
run: $(TARGET)
	./$(TARGET)

# Debug build with more verbose flags
debug: CXXFLAGS += -DDEBUG -g3
debug: $(TARGET)

# Show help
help:
	@echo "Available targets:"
	@echo "  all      - Build the program (default)"
	@echo "  clean    - Remove build artifacts"
	@echo "  rebuild  - Clean and build"
	@echo "  run      - Build and run the program"
	@echo "  debug    - Build with debug flags"
	@echo "  help     - Show this help message"

# Declare phony targets
.PHONY: all clean rebuild run debug help

# Dependencies (for header changes)
$(OBJDIR)/main.o: $(SRCDIR)/Calculator.h $(SRCDIR)/utilities.h
$(OBJDIR)/Calculator.o: $(SRCDIR)/Calculator.h
$(OBJDIR)/utilities.o: $(SRCDIR)/utilities.h