# Makefile

# Project Name
PROJ_NAME := PROJECT2_1_C

# Compiler and linker
CXX := g++

# SOURCE folder
SRC_DIR := .

HALFTONING_DIR := ../

# HEADER folder
INC_DIR := ../

# Build folder
BUILD_DIR := build

# Source files C++
SRCSXX := $(wildcard $(SRC_DIR)/*.cpp)
SRCSXX += $(wildcard $(HALFTONING_DIR)/*.cpp)

# Object files
OBJS := $(patsubst %.cpp,%.o, $(SRCSXX))

PROJ_DEP := `pkg-config --cflags --libs opencv`

all: folders $(PROJ_NAME)

$(PROJ_NAME): $(OBJS)
	@echo "Linking $^ ..."
	$(CXX) $^ -o $(BUILD_DIR)/$@ $(PROJ_DEP)
	@echo "\033[92mBinary are ready in $(BUILD_DIR)/$@!\033[0m"

%.o: %.cpp
	@echo "Compiling $@ ..."
	$(CXX) -O0 -g -c $^ -o $@ -I$(INC_DIR)
	@echo "\033[94m$@ Compiled!\033[0m"

folders:
	@mkdir -p $(BUILD_DIR)

clean:
	@rm -rf $(BUILD_DIR)/* $(SRC_DIR)/*.o $(HALFTONING_DIR)/*.o
