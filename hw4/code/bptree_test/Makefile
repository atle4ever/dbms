# Makefile for simple_dbms
EXEC    = bptree_test
HEADER  = ../BPTree.h ../Timer.h
SRC     = test.cc

CFLAGS = -Wall -g
LFLAGS =
INCLUDE = ../
#-------------------------------------------------
# Compiler options -------------------------------

CC      = g++
CFLAGS += $(addprefix -I, $(INCLUDE))

OBJ = $(SRC:.cc=.o)


# Configure ------------------------------------------

all: $(EXEC)


# Build ------------------------------------------

%.o: %.cc
	$(CC)  $(CFLAGS) -c $< -o $@

%.d : %.cc
	@$(CC) $(CFLAGS) -M $< > $@

-include $(patsubst %.cc, %.d, $(wildcard *.cc))

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS) $(LFLAGS)

# Clean ------------------------------------------

clean:
	-rm -vf *.o *.d $(EXEC) core

.PHONY: clean all

#------------------------------------------------
