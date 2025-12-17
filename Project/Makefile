# # Compiler and flags
# CXX := g++
# CXXFLAGS := -std=c++11 -w -I. -MMD -MP

# # Directories
# BUILD_DIR := build
# INCLUDE_DIR := .

# # Source files
# MAIN_SRC := main.cpp
# TEST_SRC := test.cpp
# S_TEST_SRC := test_s.cpp
# H_TEST_SRC := test_h.cpp
# ALL_CPP := $(wildcard *.cpp)
# COMMON_SRC := $(filter-out $(MAIN_SRC) $(TEST_SRC) $(S_TEST_SRC) $(H_TEST_SRC), $(ALL_CPP))

# # Object files
# COMMON_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(COMMON_SRC))
# MAIN_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(MAIN_SRC))
# TEST_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(TEST_SRC))
# S_TEST_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(S_TEST_SRC))
# H_TEST_OBJ := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(H_TEST_SRC))

# # Binaries
# RUN_BIN := $(BUILD_DIR)/run.out
# TEST_BIN := $(BUILD_DIR)/test.out
# S_TEST_BIN := $(BUILD_DIR)/s_test.out
# H_TEST_BIN := $(BUILD_DIR)/h_test.out

# # Dependency files
# DEPS := $(COMMON_OBJ:.o=.d) $(MAIN_OBJ:.o=.d) $(TEST_OBJ:.o=.d) $(H_TEST_OBJ:.o=.d)

# # Default target
# all: $(TEST_BIN)

# # Ensure build dir exists
# $(BUILD_DIR):
# 	mkdir -p $(BUILD_DIR)

# # Generic compilation rule with dependency generation
# $(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
# 	@$(CXX) -c -I$(INCLUDE_DIR) $(CXXFLAGS) -MF $(patsubst %.o,%.d,$@) $< -o $@

# # Link targets
# $(RUN_BIN): $(MAIN_OBJ) $(COMMON_OBJ)
# 	$(CXX) $^ -o $@

# $(TEST_BIN): $(TEST_OBJ) $(COMMON_OBJ)
# 	$(CXX) $^ -o $@

# $(S_TEST_BIN): $(S_TEST_OBJ) $(COMMON_OBJ)
# 	$(CXX) $^ -o $@
	
# $(H_TEST_BIN): $(H_TEST_OBJ) $(COMMON_OBJ)
# 	$(CXX) $^ -o $@

# # Convenience targets
# run: $(RUN_BIN)
# 	./$(RUN_BIN)

# test: $(TEST_BIN)
# 	./$(TEST_BIN)

# test_s: $(S_TEST_BIN)
# 	./$(S_TEST_BIN)
	
# test_h: $(H_TEST_BIN)
# 	./$(H_TEST_BIN)

# # Clean build artifacts
# clean:
# 	rm -rf $(BUILD_DIR)

# # Include dependency files
# -include $(DEPS)

# .PHONY: run test test_h clean

# # ---------- Config ----------
# CXX := g++
# CXXFLAGS := -std=c++17 -Wall -Wextra -I"Headers"    # change "Headers" to your header folder name or "." if headers at root
# BUILD_DIR := build
# INCLUDE_DIR := Headers   # used for -I if needed; keep consistent with CXXFLAGS
# # ----------------------------

# # find all .cpp files recursively
# SRC := $(shell find . -type f -name '*.cpp' -print)

# # Optionally exclude tests or other files
# # Example: remove test files if they are in root and you don't want them compiled by default:
# # SRC := $(filter-out ./test.cpp ./test_s.cpp ./test_h.cpp, $(SRC))

# # main source (adjust if your main.cpp is at different path)
# MAIN_SRC := ./main.cpp

# # other sources (all except main)
# OTHER_SRC := $(filter-out $(MAIN_SRC), $(SRC))

# # map source -> build object keeping directory structure under build/
# OBJ := $(patsubst ./%, $(BUILD_DIR)/%, $(OTHER_SRC:.cpp=.o))
# MAIN_OBJ := $(patsubst ./%, $(BUILD_DIR)/%, $(MAIN_SRC:.cpp=.o))

# # dependency files
# DEPS := $(OBJ:.o=.d) $(MAIN_OBJ:.o=.d)

# # final binary
# RUN_BIN := $(BUILD_DIR)/run.out

# .PHONY: all clean run

# all: $(RUN_BIN)

# # ensure build directories for object files exist
# $(BUILD_DIR)/%/:
# 	mkdir -p $@

# # generic rule: compile any src (preserves subdirs under build)
# # uses -MMD -MP to generate .d files for deps
# $(BUILD_DIR)/%.o: ./%.cpp | $(BUILD_DIR)/%/
# 	@echo "Compiling $< -> $@"
# 	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

# # link
# $(RUN_BIN): $(MAIN_OBJ) $(OBJ) | $(BUILD_DIR)
# 	@echo "Linking $@"
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# # run
# run: $(RUN_BIN)
# 	./$(RUN_BIN)

# # clean
# clean:
# 	rm -rf $(BUILD_DIR)

# # include deps if present
# -include $(DEPS)



# # ---------------- Config ----------------
# CXX      := g++
# CXXFLAGS := -std=c++17 -Wall -Wextra -I"Headers"    # <-- change "Headers" if your header folder is different
# BUILD_DIR := build
# RUN_BIN   := $(BUILD_DIR)/run.out
# # ----------------------------------------

# # Find all .cpp files recursively (relative paths starting with ./)
# SRC := $(shell find . -type f -name '*.cpp' -print)

# # Map sources -> object files under build/ preserving subdirs
# OBJ := $(patsubst ./%, $(BUILD_DIR)/%, $(SRC:.cpp=.o))

# # Dependency files (*.d)
# DEPS := $(OBJ:.o=.d)

# .PHONY: all clean run

# all: $(RUN_BIN)

# # Compile rule: create directory then compile (generate .d via -MMD -MP)
# # $@ = target object file, $< = source .cpp
# $(BUILD_DIR)/%.o: ./%.cpp
# 	@mkdir -p $(dir $@)
# 	@echo "Compiling $< -> $@"
# 	$(CXX) $(CXXFLAGS) -c $< -o $@ -MMD -MP

# # Link rule
# $(RUN_BIN): $(OBJ)
# 	@mkdir -p $(dir $@)
# 	@echo "Linking -> $@"
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# run: $(RUN_BIN)
# 	./$(RUN_BIN)

# # Remove build artifacts
# clean:
# 	rm -rf $(BUILD_DIR)

# # Include dependency files if present (silently ignore if missing)
# -include $(DEPS)


# # Compiler
# CXX := g++
# CXXFLAGS := -std=c++11 -Wall -I.

# # Directories
# BUILD_DIR := build
# SRC_DIRS := . Module-1 Module-2
# SRCS := $(wildcard $(foreach dir,$(SRC_DIRS),$(dir)/*.cpp))
# OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
# DEPS := $(OBJS:.o=.d)

# # Output binary
# RUN_BIN := $(BUILD_DIR)/run.out

# # Default target
# all: $(RUN_BIN)

# # Create build subdirectories automatically
# $(BUILD_DIR)/%.o: %.cpp
# 	@mkdir -p $(dir $@)
# 	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# # Link
# $(RUN_BIN): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# # Run
# run: $(RUN_BIN)
# 	./$(RUN_BIN)

# # Clean
# clean:
# 	rm -rf $(BUILD_DIR)

# # Include dependencies
# -include $(DEPS)

# .PHONY: all run clean

# # Compiler
# CXX := g++
# CXXFLAGS := -std=c++11 -Wall -I.

# # Directories
# BUILD_DIR := build
# SRC_DIRS := . Module-1 Module-2

# # Collect all sources
# SRCS := $(wildcard $(foreach dir,$(SRC_DIRS),$(dir)/*.cpp))

# # Object files mirrored in build folder
# OBJS := $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# # Dependency files
# DEPS := $(OBJS:.o=.d)

# # Output binary
# RUN_BIN := $(BUILD_DIR)/run.out

# # Default target
# all: $(RUN_BIN)

# # Compile .cpp into .o and generate .d
# $(BUILD_DIR)/%.o: %.cpp
# 	@mkdir -p $(dir $@)
# 	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# # Link
# $(RUN_BIN): $(OBJS)
# 	$(CXX) $(CXXFLAGS) $^ -o $@

# # Run
# run: $(RUN_BIN)
# 	./$(RUN_BIN)

# # Clean build
# clean:
# 	rm -rf $(BUILD_DIR)

# # Include dependencies
# -include $(DEPS)

# .PHONY: all run clean



# Compiler
CXX := g++
CXXFLAGS := -std=c++11 -Wall -IHeaders

# Directories
BUILD_DIR := build
SRC_DIRS := . Module-1 Module-2 Module-3 Module-4 Module-5 Module-6 Module-7

# Binary
RUN_BIN := $(BUILD_DIR)/run.out

# Find all .cpp files in source directories
SRCS := $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.cpp))

# Object files in build directory (mirroring folder structure)
OBJS := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)

# Ensure build directories exist for object files
$(BUILD_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -MMD -MP -c $< -o $@

# Link binary
$(RUN_BIN): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Default target
all: $(RUN_BIN)

# Run convenience target
run: $(RUN_BIN)
	./$(RUN_BIN)

# Clean build
clean:
	rm -rf $(BUILD_DIR)

# Include dependency files
-include $(DEPS)

.PHONY: all run clean
