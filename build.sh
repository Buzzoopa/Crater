#!/bin/bash

# Libraries to link with SDL2
LIBS="-lmingw32 -lSDL2main -lSDL2"

# Include directories
INCLUDES="-Iinclude"

# Source files
SRCS="src/main.cpp src/Crater/RenderWindow.cpp"

# Output executable
OUT="main"

# Compile command
g++ -mconsole -o $OUT $SRCS $INCLUDES $LIBS
