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
OBJDIR		:= objects/
TESTSDIR 	:= tests/
GTESTDIR 	:= googletest/googletest/include/

# Compiled Objects
OBJS := main.o Logbook.o Entry.o

# Compilation flags
CC 			:= g++ -std=c++11
TARGET 		:= bin/driver
CC_FLAGS 	:= -g 

# using google's unit testing framework 'googletest'
#GT_FLAGS	:= -L/usr/lib -lgtest -lgtest_main -lpthread
#INC_FLAGS 	:= -I $(GTESTDIR)

# using OpenGL compilation flags
GL_FLAGS := -lGL -lGLU -lglut 
GLFW_FLAGS := -L$(LIBDIR) -lglfw3 -lGL -lX11 -lpthread -lXrandr -lXi -ldl

# all compilation flags
CC_FLAGS := -Wall -Wextra -I $(INCLUDEDIR) $(GLFW_FLAGS) -L ./objects/
#########################################################

$(TARGET):
	$(CC) $(TARGET).cpp $(CC_FLAGS) -o $(BINDIR)executable.bin

glad:
	$(CC) -c $(SRCDIR)glad.c $(CC_FLAGS) -o $(OBJDIR)glad.o

test: glad
	$(CC) $(OBJDIR)glad.o $(SRCDIR)test.cpp $(CC_FLAGS) -o $(BINDIR)test.bin 

myWindow: glad
	$(CC) $(OBJDIR)glad.o $(SRCDIR)myWindow.cpp $(CC_FLAGS) -o ./myWindow.out

window: glad
	$(CC) $(OBJDIR)glad.o $(SRCDIR)HelloWindow.cpp $(CC_FLAGS) -o $(BINDIR)HelloWindow.bin

triangle: glad
	$(CC) $(OBJDIR)glad.o $(SRCDIR)HelloTriangle.cpp $(CC_FLAGS) -o $(BINDIR)HelloTriangle.bin -g

strings:
	$(CC) $(TESTSDIR)strings_and_char_ptrs.cpp -o $()strings_and_char_ptrs -g

arrays:
	$(CC) $(TESTSDIR)arrays.cpp -o $()arrays.out -g

clean:
	rm -f $(OBJDIR)*.o *.o *.exe driver $(BINDIR)*.bin

