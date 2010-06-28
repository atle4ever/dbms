# Makefile for B+Tree homework

EXEC    = bptree_test
HEADER  = $(wildcard *.h) BPTree.cc
SRC     = $(filter-out $(HEADER), $(wildcard *.cc))
CFLAGS  = -g -O2 -Wall
# CFLAGS  = -O2 -Wall
INCLUDE = /usr/include/boost

#-------------------------------------------------
# Compiler options -------------------------------

CC      = g++
CFLAGS += $(addprefix -I, $(INCLUDE))
LFLAGS  = # -lpthread
OBJ = $(SRC:.cc=.o)

# Build ------------------------------------------

all: $(EXEC)

%.o: %.cc $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LFLAGS)

# Clean ------------------------------------------

clean:
	-rm -vf *.o $(EXEC) core

.PHONY: clean all

#-------------------------------------------------

