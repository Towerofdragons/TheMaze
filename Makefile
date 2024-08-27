# OBJS - which files to compile
OBJS = SDLwindow.c

# OBJ_NAME - what to name our executable
OBJ_NAME = maze

# compiler flags
COMPILER_FLAGS = -Wall -Werror -Wextra -pedantic

# Linker flags
LINKER_FLAGS = -lSDL2 -lm

# Describe dependencies
all : $(OBJS)

	gcc $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
	./maze
