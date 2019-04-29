SRC_DIR = src
BIN_DIR = bin

SRC_FILES = $(wildcard $(SRC_DIR)/*.cpp)
BIN_FILES = $(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%,$(SRC_FILES))

# MuJoCo Flags
MJ_DIR = external/mujoco200
MJ_CPP_FLAGS = -I$(MJ_DIR)/include -L$(MJ_DIR)/bin -lmujoco200 -lGL -lglew $(MJ_DIR)/bin/libglfw.so.3 -lpthread


# All of the executable files.
all : $(BIN_FILES)

# Build all of the .cpp files in the source directory.
$(BIN_DIR)/% : $(SRC_DIR)/%.cpp
	g++ -o $@ $< $(MJ_CPP_FLAGS)

# Remove all of the binaries.
clean : 
	rm $(BIN_FILES)