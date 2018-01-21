###########################################################
# 														  #
# This is a make file that uses variable names to compile #
# all of my files. Note that the order of the variable    #
# declarations matter so make sure to define directories  #
# then compiled objects, then compilation flags before    #
# running the compilation commands. Do not use variable   #
# names such as "PATH" as they will overwrite the default #
# environment variables                                   #
#                                                         #
###########################################################

# Assignments
###########################################################

# Directory variables
SRCDIR 		:= src/
BUILDDIR 	:= build/
INCLUDEDIR 	:= include/
LIBDIR 		:= lib/
BINDIR 		:= bin/
TESTSDIR 	:= tests/
GTESTDIR 	:= googletest/googletest/include/

# Compiled Objects
OBJS := main.o Logbook.o Entry.o

# Compilation flags
CC 			:= g++
TARGET 		:= bin/driver
CC_FLAGS 	:= -g 

# using google's unit testing framework 'googletest'
#GT_FLAGS	:= -L/usr/lib -lgtest -lgtest_main -lpthread
#INC_FLAGS 	:= -I $(GTESTDIR)

# using OpenGL compilation flags
GL_FLAGS := -lGL -lGLU -lglut 
GLFW_FLAGS := -L$(LIBDIR) -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi

# all compilation flags
CC_FLAGS := -Wall -Wextra -I $(INCLUDEDIR) $(GLFW_FLAGS)
#########################################################

$(TARGET):
	$(CC) $(TARGET).cpp $(CC_FLAGS) -o ./bin/executable.bin

glad:
	$(CC) -c src/glad.c $(CC_FLAGS) -o glad.o

test:
	$(CC) glad.o test.cpp $(CC_FLAGS) -o ./bin/test.bin 

clean:
	rm -f *.o *.exe driver ./bin/*.bin

