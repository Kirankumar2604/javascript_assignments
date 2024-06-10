@echo off
REM Set the compiler and flags
set CXX=g++
set CXXFLAGS=-std=c++11 -w

REM Include and library paths
set INCLUDES=-I src\include
set LIBDIRS=-L src\lib

REM Necessary libraries to link
set LIBS=-lSDL2_image -lmingw32 -lSDL2main -lSDL2 -lwinmm -static-libgcc

REM Source files and output executable
set SRCS=main.cpp board.cpp eval.cpp search.cpp gui.cpp tile.cpp piece.cpp
set TARGET=Yel.exe

REM Compile source files to object files
for %%f in (%SRCS%) do (
    %CXX% %CXXFLAGS% %INCLUDES% -c %%f -o %%~nf.o
)

REM Link the object files to create the executable
%CXX% -o %TARGET% %OBJS% %LIBDIRS% %LIBS%

REM Clean up object files
del %OBJS%

echo Compilation complete.
pause
