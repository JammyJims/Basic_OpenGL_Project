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
CC 			:= g++
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

window: glad
	$(CC) $(OBJDIR)glad.o $(SRCDIR)HelloWindow.cpp $(CC_FLAGS) -o $(BINDIR)HelloWindow.bin

clean:
	rm -f $(OBJDIR)*.o *.exe driver $(BINDIR)*.bin

