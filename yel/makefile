INCLUDE_PATHS = -I src\include
LIBRARY_PATHS = -L src\lib

COMPILER_FLAGS = -std=c++11 -w -Wl,-subsystem,windows
LINKER_FLAGS = -lSDL2_image -lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc

OBJ_NAME = Yel
OBJS = main.cpp board.cpp eval.cpp search.cpp gui.cpp tile.cpp piece.cpp

make:
	g++ $(OBJS) -o $(OBJ_NAME) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(COMPILER_FLAGS) $(LINKER_FLAGS)
#mingw32-make make