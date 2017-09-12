#
# This is an example Makefile for a dice rolling  program.  This
# program uses both the dice  module and a main file "game.cpp".
# Typing 'make' or 'make make' will create the executable file.
#

# define some Makefile variables for the compiler and compiler flags
# to use Makefile variables later in the Makefile: $()
#
#  -g    adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
#
# for C++ define  CC = g++
CC = g++
CFLAGS  = -std=c++14 -g -Wall

# typing 'make' will invoke the first target entry in the file 
# (in this case the default target entry)
# you can name this target entry anything, but "default" or "all"
# are the most commonly used names by convention
#
default: game

# To create the executable file dice we need the object files
# dice.o, game.o:
#
game:  dice.o  sort_source.o game.o
	$(CC) $(CFLAGS) -o game  dice.o game.o sort_source.o

# To create the object file dice.o, we need the source
# files dice.h dice.cpp:
#
dice.o:  dice.cpp  dice.h 
	$(CC) $(CFLAGS) -c dice.cpp

# To create the object file sort.o, we need the source
# files sort_header.h sort_source.cpp:
#
sort_source.o:  sort_source.cpp  sort_header.h
	$(CC) $(CFLAGS) -c sort_source.cpp


# To create the object file game.o, we need the source files
# game.cpp:
#
game.o:  util_file.h game.cpp 
	$(CC) $(CFLAGS) -c game.cpp


# To start over from scratch, type 'make clean'.  This
# removes the executable file, as well as old .o object
# files and *~ backup files:
#
clean: 
	$(RM) game *.o *~ *.txt
