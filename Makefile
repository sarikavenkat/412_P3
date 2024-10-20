# Makefile for Load Balancer program

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -std=c++17 -Wall -Wextra

# Source files
SRCS = LoadBalancer.cpp main.cpp WebServer.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Executable name
EXEC = load_balancer

# Default target
all: $(EXEC)

# Link object files to create the executable
$(EXEC): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile source files to object files
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build files and log file
clean:
	rm -f $(OBJS) $(EXEC) log.txt

# Phony targets
.PHONY: all clean
