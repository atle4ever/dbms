EXEC    = simpledb
SRC     = $(wildcard *.cc)

#-------------------------------------------------
# Compiler options -------------------------------

CC     = g++
CFLAGS = -g -Wall -Wextra -Winline -W -Wwrite-strings -Wno-unused

OBJ = $(SRC:.cc=.o)


# Build ------------------------------------------

all: $(EXEC)

%.o: %.cc
	$(CC)  $(CFLAGS) -c $< -o $@

-include $(patsubst %.cc, %.d, $(wildcard *.cc))

$(EXEC): $(OBJ)
	$(CC) -o $(EXEC) $(OBJ) $(CFLAGS)


# Clean ------------------------------------------

clean:
	-rm -vf *.o *.d  $(EXEC) core

.PHONY: clean all
#------------------------------------------------
