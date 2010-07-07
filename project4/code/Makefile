# Makefile for query processor

EXEC    = simple_dbms
HEADER  = $(wildcard *.h)
SRC     = $(filter-out $(HEADER), $(wildcard *.cc))
CFLAGS  = -g -Wall
# CFLAGS  = -O2 -Wall
INCLUDE =

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
